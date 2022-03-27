#include "personaje.h"

Personaje::Personaje()
{
    sprite.load(":/images/Sprites/personaje.png");
    spriteDead.load(":/images/Sprites/personaje_herido.png");
    setSize(sizeGame);
    setFrame(1);
    vel = velPlayer;
    bombs = bombsPlayer;

}

void Personaje::setTypeDead(int typeX, int typeY)
{
    typeDead = spriteDead.copy(typeX*size_sprites, typeY*size_sprites, size_sprites, size_sprites)
            .scaled(size, size);
    setPixmap(typeDead);
}

bool Personaje::putBomb(Bomba *bomba)
{
    int pX = ((int)x()/size)*size;
    int pY = ((int)y()/size)*size;
    int mX, mY;
    if (pX == x() && pY == y()) {
        mY = pY/size;
        mX = pX/size;
        if (matrizGame[mY][mX] != 2) {
            bomba->setPos(pX, pY);
            return true;
        }
    }
    else if (pY == y()) { //el personajes esta por la derecha
        if (x() <= (pX+((size-1)/2))) {
            mY = pY/size;
            mX = pX/size;
            if (matrizGame[mY][mX] != 2) {
                bomba->setPos(pX, pY);
                return true;
            }
        }
        else if (x() > (pX+((size-1)/2))) {
            mY = pY/size;
            mX = (pX+size)/size;
            if (matrizGame[mY][mX] != 2){
                bomba->setPos(pX+size, pY);
                return true;
            }
        }
        else return false;
    }
    else if (pX == x()) { //el personaje esta abajo
        if (y() <= (pY+((size-1)/2))) {
            mY = pY/size;
            mX = pX/size;
            if (matrizGame[mY][mX] != 2) {
                bomba->setPos(pX, pY);
                return true;
            }
        }
        else if (y() > (pY+((size-1)/2))) {
            mY = (pY+size)/size;
            mX = pX/size;
            if (matrizGame[mY][mX] != 2) {
                bomba->setPos(pX, pY+size);
                return true;
            }
        }
        else return false;
    }
    else return false;
    return false;
}

short Personaje::getBombs() const
{
    return bombs;
}

void Personaje::setBombs(short newBombs)
{
    bombs = newBombs;
}

QList<Enemigo *> *Personaje::getEnemigos() const
{
    return enemigos;
}

void Personaje::setEnemigos(QList<Enemigo *> *newEnemigos)
{
    enemigos = newEnemigos;
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
    connect(timer, SIGNAL(timeout()), this, SLOT(deadAnimation()));
    emit stateChanged();
}

void Personaje::collidingWithEnemy()
{
    for (auto enemy : *enemigos) {
        if (collidesWithItem(enemy)) {
            setState(false);
            //animacionMuerte
            //setTypeDead(2);
            break;
        }
    }
}

void Personaje::setTimer(QTimer *newTimer)
{
    timer = newTimer;
}

void Personaje::deadAnimation()
{
    static short  frame = 0;
    static short count = 16;
    if (count == 16) {
        setTypeDead(frame);
        count = 0;
        frame+=1;
        if(frame == 3) disconnect(timer, SIGNAL(timeout()), this, SLOT(deadAnimation()));
    }
    count++;
}
