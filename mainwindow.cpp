#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Bombersouls"));
    ui->graphicsView->setGeometry(0,0,width(),height());
    escena = new QGraphicsScene;
    escena->setSceneRect(0,0,ui->graphicsView->width()-2,ui->graphicsView->height()-2);
    createMap();
    loadMap();

    //connect(time, SIGNAL(timeout()), this, SLOT(moveEnemigo()));
    //connect(time, &QTimer::timeout, this, &Juego::moveEnemigo);
    //QObject::connect(&timer, &QTimer::timeout, &scene, &QGraphicsScene::advance);
    //iniciando personaje

    enemigo[0] = new Enemigo (1);
    enemigo[0]->setSize(sizeGame);
    enemigo[0]->setFrame(1,1);
    enemigo[0]->setPos(3*48,1*48);

    escena->addItem(enemigo[0]);
    ui->graphicsView->setScene(escena);
}

MainWindow::~MainWindow()
{
    delete personaje;
    //delete time;//no se si daba eliminarlo
    //delete escena;//no e si deba eliminarlo
    delete ui;
}

void MainWindow::createMap()
{
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
    escena->addItem(personaje);//Aqui pa que aparesca
}

bool MainWindow::even_aleatorio(float p)
{
    int num_rand = rand(),x;
    x = p*(RAND_MAX+1)-1;

    return num_rand<=x;
}

