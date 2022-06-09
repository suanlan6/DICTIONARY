#ifndef _WORD_H
#define _WORD_H
#include <string>
#include <vector>

const int commaLen = 7;
const std::string comma[commaLen] = {";", ",", ".", "?", "!", "(", ")"};

void splitSentence(std::vector<std::string>& res, const std::string key);
std::string splitChinese(const std::string key);

inline bool isChar(const char s) {
    return (s >= 'A' && s <= 'Z') ||
        (s >= 'a' && s <= 'z');
}

inline bool isBlank(const char s) {
    return s == ' ';
}

inline bool isComma(const std::string& s) {
    for (int i = 0; i < commaLen; i++) {
        if (comma[i] == s)
            return true;
    }
    return false;
}

inline bool isNum(const char s) {
    return s > '0' && s < '9';
}

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