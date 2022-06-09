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
    on_textBrowser_destroyed();
}

void history::on_pushButton_clicked()
{
    std::ofstream ff;
    ff.open("history.txt");
    ff.close();
    ui->textBrowser->clear();
}

void history::on_textBrowser_destroyed()
{
    std::ifstream ff;
    ff.open("F:\\cpp\\t2\\build\\history.txt",std::ios::in);
    std::string ss,t,ans1;
    std::stack<std::string> sta;
    int i = 0;
    while (getline(ff,ss))
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
    while(!sta.empty())
    {
        ans1 += sta.top();
        sta.pop();
    }
    ui->textBrowser->setText(QString::fromStdString(ans1));
    ff.close();
}

history::~history()
{
    delete ui;
}
