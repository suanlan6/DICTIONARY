//dictionary.h
#pragma once
#include "ui_dictionary.h"
#include <QMainWindow>
#include <QDialog>
#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QString>
#include "mysqlmanager.h"
#include "history.h"

class dictionary : public QMainWindow {
    Q_OBJECT
    
public:
    dictionary(QWidget* parent = nullptr);
    void history_record(std::string key,std::string ans);
    bool warning(std::string key);
    ~dictionary();
private slots:
    void on_lineEdit_editingFinished(); //槽函数——输入框
    void on_pushButton_clicked(); //槽函数——清空按钮
    void on_pushButton_2_clicked(); //槽函数——本地查询按钮
    void on_pushButton_3_clicked(); //槽函数——查询历史按钮
    void on_pushButton_4_clicked(); //槽函数——网络查询按钮
    void on_textBrowser_destroyed(); //槽函数——输出框
private:
    Ui_dictionary* ui;
    history *m_second; //新建窗口
};
