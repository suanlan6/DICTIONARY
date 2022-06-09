/********************************************************************************
** Form generated from reading UI file 'dictionary.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DICTIONARY_H
#define UI_DICTIONARY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dictionary
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextBrowser *textBrowser;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *dictionary)
    {
        if (dictionary->objectName().isEmpty())
            dictionary->setObjectName(QString::fromUtf8("dictionary"));
        dictionary->resize(752, 483);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../full.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        dictionary->setWindowIcon(icon);
        centralwidget = new QWidget(dictionary);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(80, 50, 611, 71));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(370, 30, 54, 12));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 130, 81, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(614, 130, 81, 31));
        pushButton_2->setFont(font1);
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(80, 241, 611, 141));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(370, 220, 54, 12));
        label_2->setFont(font);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(500, 130, 81, 31));
        pushButton_3->setFont(font1);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(190, 130, 71, 31));
        pushButton_4->setFont(font1);
        dictionary->setCentralWidget(centralwidget);
        menubar = new QMenuBar(dictionary);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 752, 23));
        dictionary->setMenuBar(menubar);
        statusbar = new QStatusBar(dictionary);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        dictionary->setStatusBar(statusbar);

        retranslateUi(dictionary);

        QMetaObject::connectSlotsByName(dictionary);
    } // setupUi

    void retranslateUi(QMainWindow *dictionary)
    {
        dictionary->setWindowTitle(QCoreApplication::translate("dictionary", "\350\257\215\345\205\270", nullptr));
        label->setText(QCoreApplication::translate("dictionary", "\350\276\223\345\205\245\346\241\206", nullptr));
        pushButton->setText(QCoreApplication::translate("dictionary", "\346\270\205\347\251\272", nullptr));
        pushButton_2->setText(QCoreApplication::translate("dictionary", "\346\234\254\345\234\260\346\237\245\350\257\242", nullptr));
        label_2->setText(QCoreApplication::translate("dictionary", "\350\276\223\345\207\272\346\241\206", nullptr));
        pushButton_3->setText(QCoreApplication::translate("dictionary", "\347\275\221\347\273\234\346\237\245\350\257\242", nullptr));
        pushButton_4->setText(QCoreApplication::translate("dictionary", "\345\216\206\345\217\262\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dictionary: public Ui_dictionary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICTIONARY_H
