//word.h
#ifndef _WORD_H
#define _WORD_H
#include <string>
#include <vector>

const int commaLen = 7;
const std::string comma[commaLen] = {";", ",", ".", "?", "!", "(", ")"};

void splitSentence(std::vector<std::string>& res, const std::string key);
std::string splitChinese(const std::string key);

//判断是否为英文字符
inline bool isChar(const char s) {
    return (s >= 'A' && s <= 'Z') ||
        (s >= 'a' && s <= 'z');
}

//判断是否为空格
inline bool isBlank(const char s) {
    return s == ' ';
}

//判断是否为英文符号
inline bool isComma(const std::string& s) {
    for (int i = 0; i < commaLen; i++) {
        if (comma[i] == s)
            return true;
    }
    return false;
}

//判断是否为数字
inline bool isNum(const char s) {
    return s > '0' && s < '9';
}

//判断是否为中文字符
inline bool isChChar(const char* c){
    const char sign[]={"，。！？；：‘’“”、【】·《》"};
    for(int i=0;sign[i];i+=2) //i+=2
        if (sign[i]==c[0] && sign[i+1]==c[1])
            return true;
    return false;
}

class Word {
public:
    void set(std::string e, std::string c, std::string wc);
    std::string getChinese();
    std::string getWord_class();
private:
    std::string english;
    std::string chinese;
    std::string word_class;
};
#endif