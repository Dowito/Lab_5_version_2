#include "personaje.h"

Personaje::Personaje()
{
    sprite.load(":/images/Sprites/personaje.png");
    vel = velPlayer;
    bombs = bombsPlayer;
}

bool Personaje::putBomb(Bomba *bomba)
{
    int pX = ((int)x()/size)*size;
    int pY = ((int)y()/size)*size;
    if (pX == x() && pY == y()) {
        bomba->setPos(pX, pY);
        return true;
    }
    else if (pY == y()) { //el personajes esta por la derecha
        if (x() <= (pX+((size-1)/2))) {
            if (matrizGame[pY][pX] != 2) {
                bomba->setPos(pX, pY);
                return true;
            }
        }
        else if (x() > (pX+((size-1)/2))) {
            bomba->setPos(pX+size, pY);
            return true;
        }
        else return false;
    }
    else if (pX == x()) { //el personaje esta abajo
        if (y() <= (pY+((size-1)/2))) {
            bomba->setPos(pX, pY);
            return true;
        }
        else if (y() > (pY+((size-1)/2))) {
            bomba->setPos(pX, pY+size);
            return true;
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
