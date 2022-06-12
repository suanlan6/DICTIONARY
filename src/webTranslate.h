#ifndef WEBTRANSLATE_H
#define WEBTRANSLATE_H
#include <cassert>
#include <cctype>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstring>
#include "curl/curl.h"
#include "openssl/md5.h"
#include "json/json.h"

int writer(char* data, size_t size, size_t nmemb, std::string* writerData);
std::string translate(std::string q);
std::string url_encode(const std::string &value);

class WebConnect {
public:
    WebConnect(std::string q, std::string from, std::string to);
    std::string getURL();
    void connect();
    CURL* getCurl();
    void close();
private:
    const std::string appid = "20220611001245593";
    const std::string secret_key = "eEPiF_Y6Un_LYd1gNSGP";
    const std::string translate_url = "https://api.fanyi.baidu.com/api/trans/vip/translate?";
    std::string salt;
    std::string q;
    std::string from;
    std::string to;
    std::string sign;
    CURL* curl;
};
#endif