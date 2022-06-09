#include "dictionary.h"
//#include "history.h"
#include <QApplication>
#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dictionary w;
    w.show();
    //m_second = new history;
    return a.exec();
}