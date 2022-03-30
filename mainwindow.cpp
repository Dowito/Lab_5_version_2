#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <enemigo.h>
#include <personaje.h>
#include <bloque.h>
#include <bomba.h>
#include <explotion.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    escena = new QGraphicsScene;
    enemigos = new QList<Enemigo*>;
    timer = new QTimer;
    ui->setupUi(this);
    setGeometry(0,0,48*sizeMapX*sizeGame,48*sizeMapY*sizeGame+2*48);
    ui->graphicsView->setGeometry(0,0,width(),height()-2*48);
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
            if (numBombas < personaje->getBombs()){
                personaje->putBomb();
            }
        }
        else return;
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
    for (int y=0; y<sizeMapY; y++) {
        for (int x=0; x<sizeMapX; x++) {
            bloques[y][x] = new Bloque;
            bloques[y][x]->setSize(sizeGame);
            bloques[y][x]->setType(matrizGame[y][x]); //lo inicio segun el tipo que me de la matriz
            bloques[y][x]->setPos(x*size_sprites*sizeGame, y*size_sprites*sizeGame); //con hacemos una cuadicula, en al que cada casilla sera del tamaño de los sprites
            escena->addItem(bloques[y][x]);
        }
    }
}

void MainWindow::putPlayer()
{
    new Personaje(this);
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

void MainWindow::removeBomb(Bomba *reBomba)
{
    disconnect(reBomba, &Bomba::remove, this, &MainWindow::removeBomb);
    QVector<Explotion*> explotions;
    QVector<QVector<int>> mBlocks;
    numBombas -= 1;
    reBomba->explote(explotions, mBlocks);
    int mY = reBomba->y()/(size_sprites*sizeGame);
    int mX = reBomba->x()/(size_sprites*sizeGame);
    matrizGame[mY][mX] = 9;
    escena->removeItem(reBomba);
    delete reBomba;
    for (auto mPos : qAsConst(mBlocks)) {
        Explotion *explotion;
        explotion = new Explotion;
        explotion->setPos(bloques[mPos[1]][mPos[0]]->pos());
        explotion->setBloque(bloques[mPos[1]][mPos[0]]);
        connect(explotion, &Explotion::remove, this, &MainWindow::removeExplotion);
        connect(bloques[mPos[1]][mPos[0]], &Bloque::remove, this, &MainWindow::removeBlock);
        explotion->start();
        escena->addItem(explotion);
    }
    for (Explotion *explotion : qAsConst(explotions)) {
        //explosiones->push_back(explotion);
        connect(explotion, &Explotion::remove, this, &MainWindow::removeExplotion);
        connect(timer, &QTimer::timeout, explotion, &Explotion::collidingWithEnemy);
        connect(timer, &QTimer::timeout, explotion, &Explotion::collidingWithPlayer);
        explotion->setEnemigos(enemigos);
        explotion->setPersonaje(personaje);
        explotion->setGameClock(timer);
        explotion->start();
        escena->addItem(explotion);
    }
}

void MainWindow::removeBlock(Bloque *block)
{

    matrizGame[block->mY()][block->mX()] = 9;
    block->setTypeFloor();
}

void MainWindow::removeExplotion(Explotion *explosion)
{
    //explosiones->removeOne(explosion);
    escena->removeItem(explosion);
    delete explosion;
}

short MainWindow::getNumBombas() const
{
    return numBombas;
}

void MainWindow::setNumBombas(short newNumBombas)
{
    numBombas = newNumBombas;
}

QList<Explotion *> *MainWindow::getExplosiones() const
{
    return explosiones;
}

void MainWindow::setExplosiones(QList<Explotion *> *newExplosiones)
{
    explosiones = newExplosiones;
}

QList<Enemigo *> *MainWindow::getEnemigos() const
{
    return enemigos;
}

void MainWindow::setEnemigos(QList<Enemigo *> *newEnemigos)
{
    enemigos = newEnemigos;
}

int **MainWindow::getMatrizGame() const
{
    return matrizGame;
}

void MainWindow::setMatrizGame(int **newMatrizGame)
{
    matrizGame = newMatrizGame;
}

Personaje *MainWindow::getPersonaje() const
{
    return personaje;
}

void MainWindow::setPersonaje(Personaje *newPersonaje)
{
    personaje = newPersonaje;
}

QTimer *MainWindow::getTimer() const
{
    return timer;
}

void MainWindow::setTimer(QTimer *newTimer)
{
    timer = newTimer;
}

QGraphicsScene *MainWindow::getEscena() const
{
    return escena;
}

void MainWindow::setEscena(QGraphicsScene *newEscena)
{
    escena = newEscena;
}

Ui::MainWindow *MainWindow::getUi() const
{
    return ui;
}

void MainWindow::setUi(Ui::MainWindow *newUi)
{
    ui = newUi;
}

