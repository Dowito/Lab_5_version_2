#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setGeometry(0,0,width(),height());
    escena = new QGraphicsScene;
    escena->setSceneRect(0,0,ui->graphicsView->width()-2,ui->graphicsView->height()-2);
    createMap();
    loadMap();
    //iniciando personaje
    personaje = new Personaje;
    personaje->setSize(sizeGame);
    personaje->setType(1, 0);
    //agregando elementos a mostrar en pantalla a la escena
    escena->addItem(personaje);
    //agregando la escena a graphcisview
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
            if (x==0 || y==0 || x==sizeMapX-1 || y==sizeMapY-1 || (x%2==0 && y%2==0)) { //imprimir los bloques no destructibles
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
    Bloque *bloque;
    for (int y=0; y<sizeMapY; y++) {
        for (int x=0; x<sizeMapX; x++) {
            bloque = new Bloque; //creamos un nuevo bloque en cada ciclo
            if (matrizGame[y][x] != 9) { //si no es piso
                bloque->setSize(sizeGame);
                bloque->setType(matrizGame[y][x]);
                bloque->setPos(x*size_sprites*sizeGame, y*size_sprites*sizeGame); //con hacemos una cuadicula, en al que cada casilla sera del tamaño de los sprites
                bloques.push_back(bloque);
                escena->addItem(bloque);
                //ui->graphicsView->setScene(escena); //igualmente al final se monta la escena
            }
            else { //piso
                bloque->setSize(sizeGame);
                bloque->setTypeFloor();
                bloque->setPos(x*size_sprites*sizeGame, y*size_sprites*sizeGame);
                escena->addItem(bloque);
                //ui->graphicsView->setScene(escena);
            }
        }
    }
}

bool MainWindow::even_aleatorio(float p)
{
    int num_rand = rand(),x;
    x = p*(RAND_MAX+1)-1;

    return num_rand<=x;
}

