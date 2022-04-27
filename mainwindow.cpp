#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <enemigo.h>
#include <personaje.h>
#include <bloque.h>
#include <bomba.h>
#include <explotion.h>
#include <QTimer>
#include <QKeyEvent>
#include <QtDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    escena = new QGraphicsScene;
    enemigos = new QList<Enemigo*>;
    timer = new QTimer;
    contenedores = new Contenedores(this);
    ui->setupUi(this);
    setGeometry(0,0,size_sprites*sizeMapY*sizeGame,size_sprites*sizeMapY*sizeGame+2*48);
    ui->graphicsView->setGeometry(0,0,width(),height()-2*48);
    //ui->graphicsView->horizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //ui->graphicsView->verticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->VIDAS->setGeometry(1*size_sprites*sizeGame,((sizeMapY)*size_sprites*sizeGame)+(size_sprites*sizeGame)/2,size_sprites*sizeGame,size_sprites*sizeGame);
    ui->lcdVidas->setGeometry(2*size_sprites*sizeGame,((sizeMapY)*size_sprites*sizeGame)+(size_sprites*sizeGame)/2,size_sprites*sizeGame,size_sprites*sizeGame);
    escena->setSceneRect(0,0,ui->graphicsView->width()-2,ui->graphicsView->height()-2);
    createMap();
    loadMap();
    putPlayer();
    putEnemies();
    lcdUpdate();
    ui->graphicsView->setScene(escena);
    timer->start(clockGame);
}

MainWindow::~MainWindow()
{
    delete enemigos;
    delete personaje;
    delete **bloques;
    delete matrizGame;
    delete timer;//no se si daba eliminarlo
    delete escena;//no e si deba eliminarlo
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *i)
{
    if(personaje->getState()){
        if (i->key() == Qt::Key_S) {
            if(personaje->tryMove(0)) personaje->move(0), personaje->moveAnimation(0);
        }
        else if (i->key()  == Qt::Key_A) {
            if(personaje->tryMove(1)) personaje->move(1), personaje->moveAnimation(1);
        }
        else if (i->key() == Qt::Key_D) {
            if(personaje->tryMove(2)) personaje->move(2), personaje->moveAnimation(2);
        }
        else if (i->key() == Qt::Key_W) {
            if(personaje->tryMove(3)) personaje->move(3), personaje->moveAnimation(3);
        }
        else if (i->key() == Qt::Key_Space) {
            if (numBombs < personaje->getBombs()){
                personaje->putBomb();
            }
        }
        if(ui->graphicsView->mapFromScene(personaje->pos()).x() > ui->graphicsView->height()/2 && personaje->x() < 1872) escena->setSceneRect(escena->sceneRect().x()+personaje->getVel(),0,escena->sceneRect().width(),escena->sceneRect().height());
        if(ui->graphicsView->mapFromScene(personaje->pos()).x() < ui->graphicsView->height()/2 && personaje->x() > ui->graphicsView->height()/2) escena->setSceneRect(escena->sceneRect().x()-personaje->getVel(),0,escena->sceneRect().width(),escena->sceneRect().height());
        qDebug() << ui->graphicsView->mapFromScene(personaje->pos()).x();
        qDebug() << ui->graphicsView->height()/2;
        qDebug() << "Coordendas en Scene: " << personaje->pos();
        qDebug() << "Coordendas en GV: " << ui->graphicsView->mapFromScene(personaje->pos());
    }
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
    for (int mY=0; mY<sizeMapY; mY++) {
        for (int mX=0; mX<sizeMapX; mX++) {
            new Bloque(mX, mY, this);
        }
    }
}

void MainWindow::putPlayer()
{
    personaje = new Personaje(this);
}

void MainWindow::putEnemies()
{
    for(short i = 0; i<MAX_ENEMIES; i++){
        new Enemigo(this);
    }
}

void MainWindow::lcdUpdate()
{
    ui->lcdVidas->display(personaje->getLifes());
}

short MainWindow::getNumBombs() const
{
    return numBombs;
}

void MainWindow::setNumBombs(short newNumBombs)
{
    numBombs = newNumBombs;
}

QList<Enemigo *> *MainWindow::getEnemigos() const
{
    return enemigos;
}

int **MainWindow::getMatrizGame() const
{
    return matrizGame;
}

Personaje *MainWindow::getPersonaje() const
{
    return personaje;
}

QTimer *MainWindow::getTimer() const
{
    return timer;
}

QGraphicsScene *MainWindow::getEscena() const
{
    return escena;
}

short *MainWindow::getNumBombas() const
{
    return numBombas;
}

void MainWindow::setPersonaje(Personaje *newPersonaje)
{
    personaje = newPersonaje;
}

void MainWindow::on_pushButton_clicked()
{
    ui->graphicsView->scale(1.1,1.1);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->graphicsView->scale(0.9,0.9);
}


void MainWindow::on_pushButton_3_clicked()
{
    escena->setSceneRect(escena->sceneRect().x()-personaje->getSize(),0,escena->sceneRect().width(),escena->sceneRect().height()); //escena->sceneRect().width(),escena->sceneRect().height()
}

void MainWindow::on_pushButton_4_clicked()
{
    escena->setSceneRect(escena->sceneRect().x()+personaje->getSize(),0,escena->sceneRect().width(),escena->sceneRect().height());
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->graphicsView->rotate(180);
}

void MainWindow::on_pushButton_8_clicked()
{
    personaje->setRotation(personaje->rotation()+180);
}

