#include "personaje.h"
#include <mainwindow.h>
#include <bomba.h>
#include <bloque.h>
#include <QGraphicsScene>
#include <QTimer>
Personaje::Personaje(MainWindow *mainwindow)
{
    this->mainwindow = mainwindow;
    matrizGame = mainwindow->getMatrizGame();
    timer = mainwindow->getTimer();
    escena = mainwindow->getEscena();
    sprite.load(":/images/Sprites/personaje.png");
    spriteDead.load(":/images/Sprites/personaje_herido.png");
    setSize(sizeGame);
    setFrame(1);
    setPos(size,size);
    state = true;
    frame = 0;
    count = SPEED_DEAD;
    lifes = LIFES;
    vel = velPlayer;
    bombs = bombsPlayer;
    immuneExplotions = IMMUNE_EXPLOTION;
    mainwindow->setPersonaje(this);
    escena->addItem(this);
}

void Personaje::putBomb()
{
    QPointF pos;
    if(tryBomb(pos)) {
        setPos(pos);
        new Bomba(pos, mainwindow);
    }
}

bool Personaje::tryBomb(QPointF &pos)
{
    int pX = ((int)x()/size)*size;
    int pY = ((int)y()/size)*size;
    int mX, mY;
    if (pX == x() && pY == y()) {
        mY = pY/size;
        mX = pX/size;
        if (matrizGame[mY][mX] != 2) {
            pos = {static_cast<qreal>(pX), static_cast<qreal>(pY)};
            return true;
        }
    }
    else if (pY == y()) { //el personaje esta por la derecha
        if (x() <= (pX+((size-1)/2))) {
            mY = pY/size;
            mX = pX/size;
            if (matrizGame[mY][mX] != 2) {
                pos = {static_cast<qreal>(pX), static_cast<qreal>(pY)};
                return true;
            }
        }
        else if (x() > (pX+((size-1)/2))) {
            mY = pY/size;
            mX = (pX+size)/size;
            if (matrizGame[mY][mX] != 2){
                pos = {static_cast<qreal>(pX+size), static_cast<qreal>(pY)};
                return true;
            }
        }else return false;
    }
    else if (pX == x()) { //el personaje esta abajo
        if (y() <= (pY+((size-1)/2))) {
            mY = pY/size;
            mX = pX/size;
            if (matrizGame[mY][mX] != 2) {
                pos = {static_cast<qreal>(pX), static_cast<qreal>(pY)};
                return true;
            }
        }
        else if (y() > (pY+((size-1)/2))) {
            mY = (pY+size)/size;
            mX = pX/size;
            if (matrizGame[mY][mX] != 2) {
                pos = {static_cast<qreal>(pX), static_cast<qreal>(pY+size)};
                return true;
            }
        }else return false;
    }
    return false;
}

void Personaje::setTypeDead(int typeX, int typeY)
{
    typeDead = spriteDead.copy(typeX*size_sprites, typeY*size_sprites, size_sprites, size_sprites)
            .scaled(size, size);
    setPixmap(typeDead);
}

void Personaje::die()
{
    count = SPEED_DEAD;
    frame = 0;
    state = false;
    lifes -= 1;
    mainwindow->lcdUpdate();
    connect(timer, SIGNAL(timeout()), this, SLOT(deadAnimation()));
}

void Personaje::deadAnimation() //se daña a la segunda muerte
{
    if (count >= SPEED_DEAD) {
        if(frame == 3) {
            disconnect(timer, SIGNAL(timeout()), this, SLOT(deadAnimation()));
            frame = 0;
            count = SPEED_DEAD;
            setPos(size,size);
            setFrame(1);
            state = true;
        }
        else{
            setTypeDead(frame);
            count = 0;
            frame+=1;
        }
    }else count++;
}

void Personaje::moveAnimation(short direction)
{
    static short count = 1;
    static short frame = 0;
    if(direction>3) {
        setFrame(1);
    }
    else setFrame(frame, direction); //Siempre se tiene que actualizar la nueva direccion
    if(count == STEPS){
        if(direction>3) {
            setFrame(1);
        }
        else setFrame(frame, direction);
        count = 1;
        frame++;
        if (frame == 3) frame = 0;
    }
    else count++;
}

void Personaje::setImmuneExplotions(bool newImmuneExplotions)
{
    immuneExplotions = newImmuneExplotions;
}

bool Personaje::getImmuneExplotions() const
{
    return immuneExplotions;
}

short Personaje::getBombs() const
{
    return bombs;
}

void Personaje::setBombs(short newBombs)
{
    bombs = newBombs;
}

bool Personaje::getState() const
{
    return state;
}

void Personaje::setState(bool newState)
{
    if (state == newState)
        return;
    state = newState;
}

int Personaje::getLifes() const
{
    return lifes;
}

void Personaje::setLifes(int newLifes)
{
    if (lifes == newLifes)
        return;
    lifes = newLifes;
}
