#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
#include <iostream>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <btn.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsScene *background;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;
    QMediaPlayer * bgm;
    //the follow is the button will add into the graphic scene
    Btn *btn_start;
    Btn *btn_exit;

};

#endif // MAINWINDOW_H
