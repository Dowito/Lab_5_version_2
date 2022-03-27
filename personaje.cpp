#include "personaje.h"

Personaje::Personaje()
{
    sprite.load(":/images/Sprites/personaje.png");
    vel = velPlayer;
    bombs = bombsPlayer;
}

void Personaje::move(short direction)
{
    if(direction == 0){//Abajo
        setY(y()+vel);
    }
    else if(direction == 1){ //Izquierda
        setX(x()-vel);
    }
    else if (direction == 2) { //Derecha
        setX(x()+vel);
    }
    else if(direction == 3){//Arriba
        setY(y()-vel);
    }
    else return;
}

bool Personaje::tryMove(short direction)
{
    static int piso = 9;
    if(direction == 0){//Abajo
        int ezY = y()+size_sprites*sizeGame-1;
        int ezXI = x();
        int ezXD = x()+size_sprites*sizeGame-1;
        int newY = ezY+vel;
        int mY = newY/size;
        int mX1 = ezXI/size;
        int mX2 = ezXD/size;
        if (matrizGame[mY][mX1] == piso && matrizGame[mY][mX2] == piso) {
            return true;
        }
        else return false;
    }
    else if(direction == 1){ //Izquierda
        int ezX = x();
        int ezYS = y();
        int ezYI = y()+size_sprites*sizeGame-1;
        int newX = ezX-vel;
        int mX = newX/size;
        int mY1 = ezYS/size;
        int mY2 = ezYI/size;
        if (matrizGame[mY1][mX] == piso && matrizGame[mY2][mX] == piso) {
            return true;
        }
        else return false;
    }
    else if (direction == 2) { //Derecha
        int ezX = x()+size_sprites*sizeGame-1;
        int ezYS = y();
        int ezYI = y()+size_sprites*sizeGame-1;
        int newX = ezX+vel;
        int mX = newX/size;
        int mY1 = ezYS/size;
        int mY2 = ezYI/size;
        if (matrizGame[mY1][mX] == piso && matrizGame[mY2][mX] == piso) {
            return true;
        }
        else return false;
    }
    else if(direction == 3){//Arriba
        int ezY = y();
        int ezXI = x();
        int ezXD = x()+size_sprites*sizeGame-1;
        int newY = ezY-vel;
        int mY = newY/size;
        int mX1 = ezXI/size;
        int mX2 = ezXD/size;
        if (matrizGame[mY][mX1] == piso && matrizGame[mY][mX2] == piso) {
            return true;
        }
        else return false;
    }
    else return false;
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
