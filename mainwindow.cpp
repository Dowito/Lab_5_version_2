#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setGeometry(0,0,48*sizeMapX*sizeGame,48*sizeMapY*sizeGame+2*48);
    ui->graphicsView->setGeometry(0,0,width(),height()-2*48);
    ui->VIDAS->setGeometry(1*48*sizeGame,12*48*sizeGame,51,20);
    escena = new QGraphicsScene;
    escena->setSceneRect(0,0,ui->graphicsView->width()-2,ui->graphicsView->height()-2);
    createMap();
    loadMap();



    timer[0] = new QTimer;
    timer[1] = new QTimer;

    enemigo[0] = new Enemigo (1);
    enemigo[0]->setSize(sizeGame);
    enemigo[0]->setFrame(1,0);
    enemigo[0]->setPos(4*48,1*48);
    enemigo[0]->setMatrizGame(matrizGame);
    enemigo[0]->setVel(1);
    connect(timer[0], &QTimer::timeout, enemigo[0], &Enemigo::moveEnemy);
    timer[0]->start(10);
    enemigo[1] = new Enemigo (2);
    enemigo[1]->setSize(sizeGame);
    enemigo[1]->setFrame(1,0);
    enemigo[1]->setPos(5*48,4*48);
    enemigo[1]->setMatrizGame(matrizGame);
    enemigo[1]->setVel(1);
    //connect(timer[1], &QTimer::timeout, enemigo[1], &Enemigo::moveEnemy);
    timer[1]->start(100);
    //connect(time, &QTimer::timeout, this, &Juego::moveEnemigo);
    //QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    //QObject::connect(&timer, &QTimer::timeout, &scene, &QGraphicsScene::advance);

    escena->addItem(enemigo[0]);
    escena->addItem(enemigo[1]);
    ui->graphicsView->setScene(escena);

    //timer[0]->start(10);
    //timer[1]->start(100);
}

MainWindow::~MainWindow()
{
    delete personaje;
    delete *enemigo;
    delete **bloques;
    delete matrizGame;
    //delete time;//no se si daba eliminarlo
    delete escena;//no e si deba eliminarlo
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *i)
{
    if (i->key() == Qt::Key_S) {
        if(personaje->tryMove(0)) personaje->move(0);
    }
    else if (i->key()  == Qt::Key_A) {
        if(personaje->tryMove(1)) personaje->move(1);
    }
    else if (i->key() == Qt::Key_D) {
        if(personaje->tryMove(2)) personaje->move(2);
    }
    else if (i->key() == Qt::Key_W) {
        if(personaje->tryMove(3)) personaje->move(3);
    }
    else if (i->key() == Qt::Key_Space) {
        static int numBombs;
        if (numBombs < personaje->getBombs()){
            bomba = new Bomba;
            if(personaje->putBomb(bomba)){
                escena->addItem(bomba);
                numBombs++;
            }
            else delete bomba;
        }
    }
    else return;

}

void MainWindow::createMap()
{
    matrizGame = new int *[sizeMapY];
    for (short i = 0; i<sizeMapY; i++) {
        matrizGame[i] = new int [sizeMapX];
    }
    for (int y=0; y<sizeMapY; y++) {
        for (int x=0; x<sizeMapX; x++) {
            if ((x==1 && y==1) || (x==2 && y==1) || (x==1 && y==2)) matrizGame[y][x] = 9;

            else if (x==0 || y==0 || x==sizeMapX-1 || y==sizeMapY-1 || (x%2==0 && y%2==0)) { //imprimir los bloques no destructibles
                matrizGame[y][x] = 0; //typeX=0 corresponde al bloque
            }
            else if (even_aleatorio(dificult)) { //imprimir destruibles
                matrizGame[y][x] = 1; //typeX=1 corresponde al ladrillo
            }
            else matrizGame[y][x] = 9; //cualquier otra cosa corresponde al piso
        }
    }
}

void MainWindow::loadMap()
{
    for (int y=0; y<sizeMapY; y++) {
        for (int x=0; x<sizeMapX; x++) {
            if(x==1 && y==1) {
                personaje = new Personaje;
                personaje->setMatrizGame(matrizGame); //Le paso la matriz al personaje
                personaje->setSize(sizeGame);
                personaje->setFrame(1);
                personaje->setPos(1*48,1*48);
            }
            bloques[y][x] = new Bloque;
            bloques[y][x]->setSize(sizeGame);
            bloques[y][x]->setType(matrizGame[y][x]); //lo inicio segun el tipo que me de la matriz
            bloques[y][x]->setPos(x*size_sprites*sizeGame, y*size_sprites*sizeGame); //con hacemos una cuadicula, en al que cada casilla sera del tamaño de los sprites
            escena->addItem(bloques[y][x]);
        }
    }
    escena->addItem(personaje);//Aqui pa que aparesca encima de los bloques y no alreves.
}

void MainWindow::on_pushButton_clicked()
{
    bomba = new Bomba;
    bomba->setPos(personaje->x(),personaje->y());
    escena->addItem(bomba);
}


void MainWindow::on_quitarbomba_clicked()
{
    escena->removeItem(bomba);
    bomba = nullptr;
}

