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
    //hacia la derecha
    static int piso = 9;
    if(direction == 0){//Abajo
        int mY = (y()+vel)/size; //se parte desde la posicion, al divir sobre size, es como si obtuviera la posicion del personaje en la matriz.
        int mX1 = x()/size; //se revisa la ezquina mas a la izquierda de la hitbox
        int mX2 = (x()+size)/size; //se revisa la ezquina mas a l derecha de la hitbox
        if (matrizGame[mY][mX1] != 9 || matrizGame[mY][mX2] != 9) { //partiendo desde las ezquinas, si la casilla encima de ellas al moverce vel es distinta de 9, eso quiere decir que no de podra mover
            return;
        }
        setY(y()+vel);
        return;
    }
    else if(direction == 1){ //Izquierda
        int mX = (x()-vel)/size; //se parte desde la posicion, al divir sobre size, es como si obtuviera la posicion del personaje en la matriz.
        int mY1 = y()/size; //se revisa la ezquina izquierda superior de la hitbox
        int mY2 = (y()+size)/size; //se revisa la ezquina izquierda inferior de la hitbox
        if (matrizGame[mY1][mX] != 9 || matrizGame[mY2][mX] != 9) { //partiendo desde las ezquinas, si la casilla encima de ellas al moverce vel es distinta de 9, eso quiere decir que no de podra mover
            return;
        }
        setX(x()-vel);
        return;
    }
    else if (direction == 2) { //Derecha
        int ezDX = x()+size_sprites*sizeGame-1;
        int ezSDY = y();
        int ezIDY = y()+size_sprites*sizeGame-1;
        int newX = ezDX+vel;
        int mX = newX/size;
        int mY1 = ezSDY/size;
        int mY2 = ezIDY/size;
        if (matrizGame[mY1][mX] == piso && matrizGame[mY2][mX] == piso) { //partiendo desde las ezquinas, si la casilla encima de ellas al moverce vel es distinta de 9, eso quiere decir que no de podra mover
            setX(x()+vel);
            return;
        }
        else return;
    }
    else if (direction == 3) { //arriba
        int mY = (y()-vel)/size; //se parte desde la posicion, al divir sobre size, es como si obtuviera la posicion del personaje en la matriz.
        int mX1 = x()/size; //se revisa la ezquina izquierda superior
        int mX2 = (x()+size)/size; //se revisa la ezquina mas a l derecha superior
        if (matrizGame[mY][mX1] != 9 || matrizGame[mY][mX2] != 9) { //partiendo desde las ezquinas, si la casilla encima de ellas al moverce vel es distinta de 9, eso quiere decir que no de podra mover
            return;
        }
        setY(y()-vel);
        return;
    }
}
