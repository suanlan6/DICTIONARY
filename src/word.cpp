//word.cpp
#include <ctype.h>
#include "word.h"
#include <iostream>
using namespace std;

void Word::set(string e, string c, string wc)
{
    english = e;
    chinese = c;
    word_class = wc;
}

string Word::getChinese()
{
    return chinese;
}

string Word::getWord_class()
{
    return word_class;
}

//将一个句子按照单词分组，每一个单词或者标点符号均看作一个完整的字符串
void splitSentence(vector<string>& res, const string key) {
    int len = key.size();
    int start = 0, end = 0;
    while (end < len) {
        //判断是否为标点
        while ((!isBlank(key[end]) && (!isChar(key[end])) && end < len)) {
            res.push_back(string(key, (start = end), 1));
            ++start;
            ++end;
        }
        //判断是否为空格
        while (isBlank(key[end]) && end < len) {
            ++start;
            ++end;
        }
        //判断是否为英文单词
        while (isChar(key[end]) && end < len)
            end++;
        if (end > len)
            break;
        res.push_back(string(key, start, end - start));
        start = end;
    }
}

//将中文词义截取
string splitChinese(const string key) {
    int len = key.size();
    int start = 0, end = 0;
    int i;
    const char* ss = key.c_str();
    //判断是否有中文标点出现
    for (i = 0; i < key.size(); i++) {
        if (isChChar(ss + i))
            break;
    }
    return string(key, 0, i);
}