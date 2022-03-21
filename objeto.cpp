#include "objeto.h"

Objeto::Objeto()
{

}

void Objeto::setSize(unsigned short size)
{
    this->size = size_sprites*size;
}

void Objeto::setFrame(int typeX, int typeY)
{
    type = sprite.copy(typeX*size_sprites, typeY*size_sprites, size_sprites, size_sprites)
            .scaled(this->size, this->size);
    setPixmap(type);
}

short Objeto::getVel() const
{
    return vel;
}

void Objeto::setVel(short newVel)
{
    vel = newVel;
}

void Objeto::tryMove(short direction)
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
            setY(y()+vel);
            return;
        }
        else return;
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
            setX(x()-vel);
            return;
        }
        else return;
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
            setX(x()+vel);
            return;
        }
        else return;
    }
    if(direction == 3){//Arriba
        int ezY = y();
        int ezXI = x();
        int ezXD = x()+size_sprites*sizeGame-1;
        int newY = ezY-vel;
        int mY = newY/size;
        int mX1 = ezXI/size;
        int mX2 = ezXD/size;
        if (matrizGame[mY][mX1] == piso && matrizGame[mY][mX2] == piso) {
            setY(y()-vel);
            return;
        }
        else return;
    }
}
