#include "bomba.h"

Bomba::Bomba()
{
    sprite.load(":/images/Sprites/bomba.png");
    setSize(sizeGame);
    setFrame(1);
    delay = DELAY;
    pot = POT;
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

void Bomba::mX()
{

}

void Bomba::mY()
{

}

void Bomba::startExplotion()
{
    disconnect(&timer, &QTimer::timeout, this, &Bomba::startExplotion);
    timer.stop();
    emit remove(this);
}

void Bomba::startBomb()
{
    connect(&timer, &QTimer::timeout, this, &Bomba::startExplotion);
    timer.start(delay);
}
