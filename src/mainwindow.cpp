#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());

    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);

    /* first , change background picture */
    QImage bg;
    bg.load(":/image/back.jpg");
    bg = bg.scaled(width(),height());
    scene->setBackgroundBrush(bg);


    // Setting the sound
    bgm = new QMediaPlayer;
    bgm->setMedia(QUrl("qrc:/sound/bgm.mp3"));
    bgm->play();
    //std::cout<<"music play"<<std::endl;

    //creating an start button and it's function like the land
    btn_start = new Btn();
    QPixmap start_btn_pic;
    start_btn_pic.load(":/image/start_button.jpg");
    start_btn_pic = start_btn_pic.scaled(start_btn_pic.width(),start_btn_pic.height(),Qt::KeepAspectRatio);
    //set pixmap to the start button
    btn_start->setPixmap(start_btn_pic);
    //set positon in scene(in the mid)
    btn_start->setPos((width()-start_btn_pic.width())/2,(height()-start_btn_pic.height())/2);
    scene->addItem(btn_start);

    //creating an start button and it's function like the land
    btn_exit = new Btn();
    QPixmap exit_btn_pic;
    exit_btn_pic.load(":/image/exit_button.jpg");
    exit_btn_pic = exit_btn_pic.scaled(exit_btn_pic.width(),exit_btn_pic.height(),Qt::KeepAspectRatio);
    //set pixmap to the start button
    btn_exit->setPixmap(exit_btn_pic);
    //set positon in scene(below the start button)
    btn_exit->setPos((width()-exit_btn_pic.width())/2,(height()-exit_btn_pic.height())/2+2*start_btn_pic.height());
    scene->addItem(btn_exit);



    //creating an exit button and it's function like the land
    /*QPixmap exit_btn_pic;
    exit_btn_pic.load(":/image/exit_button.jpg");
    exit_btn_pic = exit_btn_pic.scaled(exit_btn_pic.width(),exit_btn_pic.height(),Qt::KeepAspectRatio);
    exitbutton=new button(16,10,8,2,exit_btn_pic,world,scene);
    itemList.push_back(exitbutton);*/



    // Create ground (You can edit here)
    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/image/GROUND.png").scaled(width(),height()/6.0),world,scene));

    //Create bird (You can edit here)
    Bird *birdie = new Bird(0.0f,10.0f,0.27f,&timer,QPixmap("image/Normal_Bird_1.png").scaled(height()/9.0,height()/9.0),world,scene);
    Bird *birdie2 = new Bird(10.0f,10.0f,0.27f,&timer,QPixmap("image/Normal_Bird_1.png").scaled(height()/9.0,height()/9.0),world,scene);
    //Setting the Velocity
    birdie->setLinearVelocity(b2Vec2(5,5));
    //birdie2->setLinearVelocity(b2Vec2(5,5));
    itemList.push_back(birdie);

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        /* TODO : add your code here */
        //std::cout << "Press !" << std::endl ;
    }
    if(event->type() == QEvent::MouseMove)
    {
        /* TODO : add your code here */
        //std::cout << "Move !" << std::endl ;
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        /* TODO : add your code here */
        //std::cout << "Release !" << std::endl ;
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::QUITSLOT()
{
    // For debug
    //std::cout << "Quit Game Signal receive !" << std::endl ;
}
