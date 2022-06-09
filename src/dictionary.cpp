#include "dictionary.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QApplication>
#include "word.h"
#include "mysqlmanager.h"

static MySQLManager mysql;
static ConnectionInfo info;

dictionary::dictionary(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_dictionary)
{
    ui->setupUi(this);
    ui->lineEdit->setClearButtonEnabled(true); //一键清除
    ui->lineEdit->setPlaceholderText("请输入你要查询的单词或需要翻译的句子"); //输入框提示语
    ui->lineEdit->setStyleSheet("border-style: outset; border-width: 2px; border-color: rgb(13,118,114);border-radius:10px;padding:2px 4px"); //输入框圆角框
    ui->textBrowser->setStyleSheet("border-style: outset; border-width: 2px; border-color: rgb(13,118,114);border-radius:10px;padding:2px 4px"); //输出框圆角框
}

//输入框
void dictionary::on_lineEdit_editingFinished()
{
    QString str = ui->lineEdit->text();
    //qDebug() << "str:" << str;
    //std::cout << s << std::endl;
    //std::string s = str.toStdString();
    on_textBrowser_destroyed();
}

//清空按钮
void dictionary::on_pushButton_clicked()
{
    ui->lineEdit->clear();
    ui->textBrowser->clear();
    //qDebug() << "str:" << endl;
}

//本地查询按钮
void dictionary::on_pushButton_2_clicked()
{
    QString str = ui->lineEdit->text();
    //qDebug() << "str:" << str;
    std::string s = str.toStdString();
    if(s.empty()){
        QMessageBox mybox;
        QMessageBox::warning(&mybox, "Warning","请输入查询或翻译内容！");
        return;
    }
    int i = 0;
    while(s[i] != '\0'){
        if(isChar(s[i]) || isBlank(s[i]) || isComma(std::string(1, s[i])) || isNum(s[i]))
            i++;
        else{
            QMessageBox mybox;
            QMessageBox::warning(&mybox, "Warning","请输入英文！");
            return;
        }
    }
    //std::cout << s << std::endl;
    on_textBrowser_destroyed();
}


//网络查询按钮
void dictionary::on_pushButton_3_clicked()
{
    QString str = ui->lineEdit->text();
    //qDebug() << "str:" << str;
    std::string s = str.toStdString();
    if(s.empty()){
        QMessageBox mybox;
        QMessageBox::warning(&mybox, "Warning","请输入查询或翻译内容！");
        return;
    }
    int i = 0;
    while(s[i] != '\0'){
        if(isChar(s[i]) || isBlank(s[i]) || isComma(std::string(1, s[i])) || isNum(s[i]))
            i++;
        else{
            QMessageBox mybox;
            QMessageBox::warning(&mybox, "Warning","请输入英文！");
            return;
        }
    }
    //std::cout << s << std::endl;
    on_textBrowser_destroyed();
}

//历史查询按钮
void dictionary::on_pushButton_4_clicked()
{

}

//输出框
void dictionary::on_textBrowser_destroyed()
{
    if (!mysql.Init(info))
       return;
    std::string key = ui->lineEdit->text().toStdString();
    std::vector<std::string> res;
    std::string ans;
    splitSentence(res, key);
    for (int i = 0; i < (int)res.size(); i++) {
        mysql.QueryData((SQLquerry1 + res[i] + SQLend).c_str());
        std::string tp = ans;
        ans += mysql.PrintQueryRes();
        if (tp == ans)
            ans += res[i];
    }
    ui->textBrowser->setText(QString::fromStdString(ans));
    if (!mysql.FreeConnect())
        return; 
}

dictionary::~dictionary()
{
    delete ui; 
}
