#include "bomba.h"
#include <mainwindow.h>
#include <explotion.h>
#include <QTimer>
#include <QGraphicsScene>
Bomba::Bomba()
{
    sprite.load(":/images/Sprites/bomba.png");
    setSize(sizeGame);
    setFrame(1);
}

Bomba::Bomba(QPointF pos, MainWindow *mainwindow)
{
    mainwindow->bombas.push_back(this);
    this->mainwindow = mainwindow;
    matrizGame = mainwindow->getMatrizGame();
    escena = mainwindow->getEscena();
    timer = mainwindow->getTimer();
    sprite.load(":/images/Sprites/bomba.png");
    setSize(sizeGame);
    setFrame(1);
    setPos(pos);
    steps = 0;
    pot = POT;
    matrizGame[mY()][mX()] = 2;
    connect(timer, SIGNAL(timeout()), this, SLOT(explote()));
    mainwindow->setNumBombs(mainwindow->getNumBombs()+1);
    escena->addItem(this);
}

int Bomba::mX()
{
    int mX = (int)(x()/(size_sprites*sizeGame));
    return mX;
}

int Bomba::mY()
{
    int mY = (int)(y()/(size_sprites*sizeGame));
    return mY;
}

void Bomba::chainExplote()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(explote()));
    mainwindow->bombas.removeOne(this);
    mainwindow->setNumBombs(mainwindow->getNumBombs()-1);
    matrizGame[mY()][mX()] = 9;
    escena->removeItem(this);
    generateExplotions();
    delete this;
}

void Bomba::explote()
{
    if(steps >= ((int)(STEPS_BOMB))){
        disconnect(timer, SIGNAL(timeout()), this, SLOT(explote()));
        mainwindow->bombas.removeOne(this);
        mainwindow->setNumBombs(mainwindow->getNumBombs()-1);
        matrizGame[mY()][mX()] = 9;
        escena->removeItem(this);
        generateExplotions();
        delete this;
    }else steps++;
}

void Bomba::generateExplotions()
{
    new Explotion(pos(), mainwindow);
    for (short i = 1; i<=pot; i++) { //direccion 0
        if (matrizGame[mY()+i][mX()] != 0) {
            new Explotion({x(), y()+(i*size)}, mainwindow);
            if (matrizGame[mY()+i][mX()] == 1 || matrizGame[mY()+i][mX()] == 2) break;
        }else break;
    }
    for (short i = 1; i<=pot; i++) { //direccion 1
        if (matrizGame[mY()][mX()-i] != 0) {
            new Explotion({x()-(i*size), y()}, mainwindow);
            if(matrizGame[mY()][mX()-i] == 1 || matrizGame[mY()][mX()-i] == 2) break;
        }else break;
    }
    for (short i = 1; i<=pot; i++) { //direccion 2
        if (matrizGame[mY()][mX()+i] != 0) {
            new Explotion({x()+(i*size), y()}, mainwindow);
            if(matrizGame[mY()][mX()+i] == 1 || matrizGame[mY()][mX()+i] == 2) break;
        } else break;
    }
    for (short i = 1; i<=pot; i++) { //direccion 3
        if (matrizGame[mY()-i][mX()] != 0) {
            new Explotion({x(), y()-(i*size)}, mainwindow);
            if(matrizGame[mY()-i][mX()] == 1 || matrizGame[mY()-i][mX()] == 2) break;
        }else break;
    }
}
