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
    bloque->setType(2);
    bloque->setPos(48,48);
    //agregando elementos a mostrar en pantalla a la escena
    escena->addItem(personaje);
    escena->addItem(bloque);
    //agregando la escena a graphcisview
    ui->graphicsView->setScene(escena);
}

MainWindow::~MainWindow()
{
    delete personaje;
    delete ui;
}

