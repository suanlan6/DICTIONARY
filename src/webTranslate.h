//webTranslate.h
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

int writer(char* data, size_t size, size_t nmemb, std::string* writerData);//缓冲写入函数
std::string translate(std::string q);//翻译函数
std::string url_encode(const std::string &value);//URL编码函数

class WebConnect {
public:
    WebConnect(std::string q, std::string from, std::string to);
    std::string getURL();//获取URL
    void connect();//连接
    CURL* getCurl();//获取CURL实体
    void close();//关闭连接
private:
    const std::string appid = "20220611001245593";//获取apppid
    const std::string secret_key = "eEPiF_Y6Un_LYd1gNSGP";//获取密钥
    const std::string translate_url = "https://api.fanyi.baidu.com/api/trans/vip/translate?";//固定翻译URL
    std::string salt;//盐值
    std::string q;//翻译文本
    std::string from;//原本语言
    std::string to;//目标翻译语言
    std::string sign;//签名
    CURL* curl;//curl实体，用于完成发送网络请求
};
#endif