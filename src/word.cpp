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

void splitSentence(vector<string>& res, const string key) {
    int len = key.size();
    int start = 0, end = 0;
    while (end < len) {
        while ((!isBlank(key[end]) && (!isChar(key[end])) && end < len)) {
            res.push_back(string(key, (start = end), 1));
            ++start;
            ++end;
        }
        while (isBlank(key[end]) && end < len) {
            ++start;
            ++end;
        }
        while (isChar(key[end]) && end < len)
            end++;
        if (end > len)
            break;
        res.push_back(string(key, start, end - start));
        start = end;
    }
}

string splitChinese(const string key) {
    int len = key.size();
    int start = 0, end = 0;
    int i;
    const char* ss = key.c_str();
    for (i = 0; i < key.size(); i++) {
        if (isChChar(ss + i))
            break;
    }
    return string(key, 0, i);
}