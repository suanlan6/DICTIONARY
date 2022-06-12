#include "webTranslate.h"
#include <cassert>
#include <cctype>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstring>
#include <iostream>
#include "curl/curl.h"
#include "openssl/md5.h"
#include "json/json.h"

int writer(char* data, size_t size, size_t nmemb, std::string* writerData) {
    if (writerData == NULL)
        return 0;
    int len = size*nmemb;
    writerData->append(data, len);
    return len;
}

std::string url_encode(const std::string &value) {
    std::ostringstream escaped;
    escaped.fill('0');
    escaped << std::hex;

    for (std::string::const_iterator i = value.begin(), n = value.end(); i != n; ++i) {
        std::string::value_type c = (*i);

        // Keep alphanumeric and other accepted characters intact
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
            continue;
        }

        // Any other characters are percent-encoded
        escaped << std::uppercase;
        escaped << '%' << std::setw(2) << int((unsigned char) c);
        escaped << std::nouppercase;
    }
    //std::cout << escaped.str() << std::endl;
    return escaped.str();
}

WebConnect::WebConnect(std::string q, std::string from, std::string to) :
            salt(std::to_string(rand())),
            q(q),
            from(from),
            to(to),
            sign(this->appid + this->q + this->salt + this->secret_key)
{
    unsigned char md[16];
    char tmp[3]={'\0'},buf[33]={'\0'};
    MD5((unsigned char *)sign.c_str(), sign.size(), md);
    for (int i = 0; i < 16; i++){
        sprintf(tmp,"%2.2x",md[i]);
        strcat(buf,tmp);
    }
    this->sign = std::string(buf);
}

std::string WebConnect::getURL() {
    return translate_url + "appid=" + appid + "&q=" + url_encode(q) + "&from=" + from + "&to=" + to + "&salt=" + salt + "&sign=" + sign;
}

void WebConnect::connect() {
    this->curl = curl_easy_init();
}

CURL* WebConnect::getCurl() {
    return this->curl;
}

void WebConnect::close() {
    curl_easy_cleanup(this->curl);
}

std::string translate(std::string q) {
    WebConnect web(q, "en", "zh");
    web.connect();
    std::string request = web.getURL();
    curl_easy_setopt(web.getCurl(), CURLOPT_URL, request.c_str());
    std::string buffer;
    curl_easy_setopt(web.getCurl(), CURLOPT_WRITEFUNCTION, writer);
    curl_easy_setopt(web.getCurl(), CURLOPT_WRITEDATA, &buffer);
    CURLcode res = curl_easy_perform(web.getCurl());
    web.close();
    Json::Value root;
    Json::Reader reader;
    bool parsingSuccessful = reader.parse(buffer, root);
    Json::Value trans = root["trans_result"];
    return trans[0]["dst"].asCString();
}