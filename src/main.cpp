#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QDesktopWidget wid;
    int screenW = 700;//W means the weight
    int screenH = 700;//H means the height

    w.setGeometry(wid.screen()->width()/2 - (screenW/2) , wid.screen()->height()/2 - (screenH/2) , screenW , screenH);


    //reference the :https://github.com/kevinbird61/BBTAN-on-Qt/blob/master/BBtan-Tutoial(1)/main.cpp
    //The TA's article.
    // ================= Setting Windows Title and Icon =================
    w.setWindowTitle("AngryBird-modifie by csiebear");
    w.setWindowIcon(QIcon(":/image/theBearIcon.png"));
    w.show();

    w.show();

    return a.exec();
}
