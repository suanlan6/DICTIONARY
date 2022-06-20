//main.cpp
#include "dictionary.h"
#include <QApplication>
#include "curl/curl.h"
#include "openssl/md5.h"

#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dictionary w; //创建主页面
    w.show(); //展示主页面
    return a.exec();
}