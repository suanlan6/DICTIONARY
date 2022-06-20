//dictionary.cpp
#include "dictionary.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <QString>
#include <QMessageBox>
#include <QApplication>
#include "word.h"
#include "mysqlmanager.h"
#include <fstream>
#include <direct.h>
#include "webTranslate.h"

static MySQLManager mysql;
static ConnectionInfo info;

dictionary::dictionary(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_dictionary)
{
    ui->setupUi(this); //编辑ui
    ui->lineEdit->setClearButtonEnabled(true); //一键清除
    ui->lineEdit->setPlaceholderText("请输入你要查询的单词或需要翻译的句子"); //输入框提示语
    ui->lineEdit->setStyleSheet("font-size:18px; border-style: outset; border-width: 2px; border-color: rgb(13,118,114);border-radius:10px;padding:2px 4px"); //输入框圆角框
    ui->textBrowser->setStyleSheet("font-size:18px; border-style: outset; border-width: 2px; border-color: rgb(13,118,114);border-radius:10px;padding:2px 4px"); //输出框圆角框
}

//输入框
void dictionary::on_lineEdit_editingFinished() //创建输入框
{
}

//清空按钮
void dictionary::on_pushButton_clicked()
{
    ui->lineEdit->clear(); //清空输入框
    ui->textBrowser->clear(); //清空输出框
}

//警告提示框
bool dictionary::warning(std::string key)
{
    if(key.empty()){ //提示框——如果输入框为空则提示
        QMessageBox mybox;
        QMessageBox::warning(&mybox, "Warning","请输入查询或翻译内容！");
        return false;
    }
    int i = 0;
    while(key[i] != '\0'){ //提示框——如果有非法字符则提示
        if(isChar(key[i]) || isBlank(key[i]) || isComma(std::string(1, key[i])) || isNum(key[i]))
            i++;
        else{
            QMessageBox mybox;
            QMessageBox::warning(&mybox, "Warning","请输入英文！");
            return false;
        }
    }
    return true;
}

//本地查询按钮
void dictionary::on_pushButton_2_clicked()
{
    QString str = ui->lineEdit->text(); //获取输入框内容
    std::string key = str.toStdString(); //将Qstring类型转换为string
    if(!warning(key)) //对输入进行非法识别
        return;
    if (!mysql.Init(info)) //开启数据库链接
       return;
    std::vector<std::string> res;
    std::string ans;
    splitSentence(res, key); //分隔单词
    for (int i = 0; i < (int)res.size(); i++) {
        mysql.QueryData((SQLquerry1 + res[i] + SQLend).c_str());//生成查询语句
        std::string tp = ans;
        ans += mysql.PrintQueryRes();
        if (tp == ans)
            ans += res[i];//拼接查询结果
    }
    ui->textBrowser->setText(QString::fromStdString(ans)); //将翻译结果输出到输出框中
    history_record(key,ans); //记录翻译历史
    if (!mysql.FreeConnect()) //关闭数据库链接
        return; 
}

//网络查询按钮
void dictionary::on_pushButton_3_clicked()
{
    QString str = ui->lineEdit->text(); //获取输入框输入
    std::string key = str.toStdString(); //将Qstring类型转换为string
    if(!warning(key)) //对输入进行非法识别
        return;
    std::string ans = translate(key); //进行网络翻译
    ui->textBrowser->setText(QString::fromStdString(ans)); //将翻译结果输出到输出框中
    history_record(key,ans); //记录翻译历史
}

//历史查询按钮
void dictionary::on_pushButton_4_clicked()
{
    m_second = new history; //新建一个historyQt窗口
    m_second->show(); //显示该窗口
}

//输出框
void dictionary::on_textBrowser_destroyed()
{
}

//翻译历史的文件写入
void dictionary::history_record(std::string key,std::string ans)
{
    std::ofstream ofs; //文件流的创建
    char* cwd; //文件路径的寻找
    cwd = _getcwd(NULL, 0);
    std::string* path = new std::string(cwd);
    std::string::size_type p=path->find("\\");
    while (p != std::string::npos) {
        p= p = path->find("\\");
        if (p!=std::string::npos)
        {
            path->replace(p, 1, "/");
        }
    }
    ofs.open(*path + "/history.txt",std::ios::app); //打开txt文件
    ofs << key << std::endl; //将记录保存到文件中
    ofs << ans << std::endl;
    ofs << std::endl;
    ofs.close(); //关闭文件
}

dictionary::~dictionary()
{
    delete ui; 
}
