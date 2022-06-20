//history.cpp
#include "history.h"
#include "ui_history.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <stack>

history::history(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::history)
{
    ui->setupUi(this);
    ui->textBrowser->setStyleSheet("border-style: outset; border-width: 2px; border-color: rgb(13,118,114);border-radius:10px;padding:2px 4px"); //输出框圆角框
    on_textBrowser_destroyed(); //输出框
}

//清空按钮
void history::on_pushButton_clicked()
{
    std::ofstream ff; //文件流创建
    ff.open("history.txt"); //覆盖已有文件以达到清空效果
    ff.close(); //关闭文件
    ui->textBrowser->clear(); //输出框内容的清空
}

//输出框
void history::on_textBrowser_destroyed()
{
    std::ifstream ff; //输出流创建
    ff.open("F:\\cpp\\t2\\build\\history.txt",std::ios::in); //打开文件
    std::string ss,t,ans1;
    std::stack<std::string> sta; //创建栈
    int i = 0;
    while (getline(ff,ss)) //每3行合成一个字符串并存入栈中
    {
        t += ss;
        t += "\n";
        i++;
        if(i % 3 == 0)
        {
            sta.push(t);
            t.clear();
        }
    }
    while(!sta.empty()) //从栈中输出并
    {
        ans1 += sta.top();
        sta.pop();
    }
    ui->textBrowser->setText(QString::fromStdString(ans1)); //输出框输出
    ff.close();
}

history::~history()
{
    delete ui;
}
