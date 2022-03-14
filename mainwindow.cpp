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
    //agregando elementos a mostrar en pantalla a la escena
    //escena->addItem(bloque);
    //agregando la escena a graphcisview
    //ui->display->setScene(escena);
}

MainWindow::~MainWindow()
{
    delete ui;
}

