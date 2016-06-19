#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //reference the :https://github.com/kevinbird61/BBTAN-on-Qt/blob/master/BBtan-Tutoial(1)/main.cpp
    //The TA's article.
    // ================= Setting Windows Title and Icon =================
    w.setWindowTitle("AngryBird-modifie by csiebear");
    w.setWindowIcon(QIcon(":/image/theBearIcon.png"));
    w.show();

    return a.exec();
}
