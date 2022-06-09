#ifndef HISTORY_H
#define HISTORY_H

#include <QMainWindow>
#include <QMainWindow>
#include <QDialog>
#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QString>
#include "mysqlmanager.h"

namespace Ui {
class history;
}

class history : public QMainWindow
{
    Q_OBJECT

public:
    explicit history(QWidget *parent = nullptr);
    ~history();

private slots:
    void on_pushButton_clicked();

    void on_textBrowser_destroyed();

private:
    Ui::history *ui;
};

#endif // HISTORY_H
