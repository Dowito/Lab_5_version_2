#include "bomba.h"
#include <mainwindow.h>
Bomba::Bomba()
{
    sprite.load(":/images/Sprites/bomba.png");
    setSize(sizeGame);
    setFrame(1);
    delay = DELAY;
    pot = POT;
}

Bomba::Bomba(QPointF pos, MainWindow *mainwindow)
{
    this->mainwindow = mainwindow;
    matrizGame = mainwindow->getMatrizGame();
    //bombas = mainwindow->getBombas();
    timer = mainwindow->getTimer();
    sprite.load(":/images/Sprites/bomba.png");
    setSize(sizeGame);
    setFrame(1);
    delay = DELAY;
    pot = POT;
    setPos(pos);
    matrizGame[mY()][mX()] = 2;
    connect(this, &Bomba::remove, mainwindow, &MainWindow::removeBomb);
    startBomb();
    mainwindow->setNumBombas(mainwindow->getNumBombas()+1);
    mainwindow->getEscena()->addItem(this);
}

void Bomba::explote(QVector<Explotion *> &explotions, QVector<QVector<int> > &mBlocks, QVector<QVector<int> > &mBombs)
{
    Explotion *explotion;
    explotion = new Explotion;
    explotion->setPos(x(), y());
    explotions.push_back(explotion);
    int mX = (int)x()/size;
    int mY = (int)y()/size;
    for (short i = 1; i<=pot; i++) {
        if (matrizGame[mY+i][mX] == 9) { //direccion 0
            explotion = new Explotion;
            explotion->setPos(x(), y()+(i*size));
            explotions.push_back(explotion);
        }
        else if (matrizGame[mY+i][mX] == 1) {
            mBlocks.push_back({mX,mY+i});
            break;
        }
        else break;
    }
    for (short i = 1; i<=pot; i++) {
        if (matrizGame[mY][mX-i] == 9) { //direccion 1
            explotion = new Explotion; //si hay piso se crea una explosion
            explotion->setPos(x()-(i*size), y());
            explotions.push_back(explotion);
        }
        else if (matrizGame[mY][mX-i] == 1) {
            mBlocks.push_back({mX-i, mY});
            break;
        }
        /*
        else if (matrizGame[mY][mX-i] == 2) {
            mBombs.push_back({mX-i, mY});
        }
        */
        else break;
    }
    for (short i = 1; i<=pot; i++) {
        if (matrizGame[mY][mX+i] == 9) { //direccion 2
            explotion = new Explotion; //si hay piso se crea una explosion
            explotion->setPos(x()+(i*size), y());
            explotions.push_back(explotion);
        }
        else if (matrizGame[mY][mX+i] == 1) {
            mBlocks.push_back({mX+i,mY});
            break;
        }
        else break;
    }
    for (short i = 1; i<=pot; i++) {
        if (matrizGame[mY-i][mX] == 9) { //direccion 3
            explotion = new Explotion; //si hay piso se crea una explosion
            explotion->setPos(x(), y()-(i*size));
            explotions.push_back(explotion);
        }
        else if (matrizGame[mY-i][mX] == 1) {
            mBlocks.push_back({mX,mY-i});
            break;
        }
        else break;
    }
}

int Bomba::mX()
{
    int mX = x()/(size_sprites*sizeGame);
    return mX;
}

int Bomba::mY()
{
    int mY = y()/(size_sprites*sizeGame);
    return mY;
}

void Bomba::startExplotion()
{
    disconnect(&bombTimer, &QTimer::timeout, this, &Bomba::startExplotion);
    bombTimer.stop();
    emit remove(this);
}

void Bomba::startBomb()
{
    connect(&bombTimer, &QTimer::timeout, this, &Bomba::startExplotion);
    bombTimer.start(delay);
}
