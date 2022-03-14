#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setGeometry(0,0,width(),height());
    //inicializando la escena
    escena = new QGraphicsScene;
    escena->setSceneRect(0,0,ui->graphicsView->width()-2,ui->graphicsView->height()-2);
    //iniciando personaje
    personaje = new Personaje;
    personaje->setType(1, 0);
    bloque = new Bloque;
    bloque->setType(1);
    bloque->setPos(48,48);
    //agregando elementos a mostrar en pantalla a la escena
    escena->addItem(personaje);
    escena->addItem(bloque);
    //agregando la escena a graphcisview
    ui->graphicsView->setScene(escena);
}

MainWindow::~MainWindow()
{
    delete bloque;
    delete personaje;
    delete ui;
}

void MainWindow::createMap()
{
    for (int y=0; y<sizeMapY; y++) {
        for (int x=0; x<sizeMapX; x++) {
            if (y==0 || x==0 || y==sizeMapY-1 || x==sizeMapX || (x%2==0 && y%2==0)) { //imprimir los bloques no destructible
                matrizGame[y][x] = 1;
            }
            else if (even_aleatorio(dificult)) { //imprimir destruibles
                matrizGame[y][x] = 2;
            }
            else matrizGame[y][x] = 0;
        }
    }
}

bool MainWindow::even_aleatorio(float p)
{
    int num_rand = rand(),x;
    x = p*(RAND_MAX+1)-1;

    return num_rand<=x;
}

