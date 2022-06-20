//webTranslate.cpp
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

//存储输出函数
int writer(char* data, size_t size, size_t nmemb, std::string* writerData) {
    if (writerData == NULL)
        return 0;
    int len = size*nmemb;
    writerData->append(data, len);
    return len;
}

//url编码为符合标准的url
std::string url_encode(const std::string &value) {
    std::ostringstream escaped;
    escaped.fill('0');
    escaped << std::hex;

    for (std::string::const_iterator i = value.begin(), n = value.end(); i != n; ++i) {
        std::string::value_type c = (*i);

        // 保留符合规则的字符
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
            continue;
        }

        // 编码字符
        escaped << std::uppercase;
        escaped << '%' << std::setw(2) << int((unsigned char) c);
        escaped << std::nouppercase;
    }

    return escaped.str();
}

//初始化连接，配置相关appid，以及初始语言和翻译的语言，生成合适的签名
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

//获取发送请求的url
std::string WebConnect::getURL() {
    return translate_url + "appid=" + appid + "&q=" + url_encode(q) + "&from=" + from + "&to=" + to + "&salt=" + salt + "&sign=" + sign;
}

//打开连接
void WebConnect::connect() {
    this->curl = curl_easy_init();
}

//获取curl实体
CURL* WebConnect::getCurl() {
    return this->curl;
}

//关闭连接
void WebConnect::close() {
    curl_easy_cleanup(this->curl);
}

//翻译函数，通过初始化curl实体，发送对应的请求，获得最终的结果
std::string translate(std::string q) {
    WebConnect web(q, "en", "zh");//英文转中文
    web.connect();
    std::string request = web.getURL();//获取URL
    curl_easy_setopt(web.getCurl(), CURLOPT_URL, request.c_str());//打开连接
    std::string buffer;
    curl_easy_setopt(web.getCurl(), CURLOPT_WRITEFUNCTION, writer);//保存输入结果
    curl_easy_setopt(web.getCurl(), CURLOPT_WRITEDATA, &buffer);//将结果输入缓冲字符串
    CURLcode res = curl_easy_perform(web.getCurl());//获得返回的状态
    web.close();//关闭连接
    if (res != CURLE_OK) {
        std::cout << "erro message:" << res << std::endl;
        exit(0);
    }
    Json::Value root;//JSON字符串实体
    Json::Reader reader;//读取json实体类
    bool parsingSuccessful = reader.parse(buffer, root);//将JSON字符串注入root实体
    Json::Value trans = root["trans_result"];//获取翻译内容
    return trans[0]["dst"].asCString();
}