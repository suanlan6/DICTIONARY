#pragma once
#include "ui_dictionary.h"
#include <QMainWindow>
#include <QDialog>
#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QString>
#include "mysqlmanager.h"
//#include "history.h"

class dictionary : public QMainWindow {
    Q_OBJECT
    
public:
    dictionary(QWidget* parent = nullptr);
    ~dictionary();
private slots:
    void on_lineEdit_editingFinished();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_textBrowser_destroyed();
private:
    Ui_dictionary* ui;
    //history *m_second;
};
