#include "bomba.h"

Bomba::Bomba()
{
    sprite.load(":/images/Sprites/bomba.png");
    setSize(sizeGame);
    setFrame(1);
    setMatrizGame(matrizGame);
}

bool Bomba::putBomb(int x, int y)
{
    int pX = (x/size)*size;
    int pY = (y/size)*size;
    if (pX == x && pY == y) {
        setPos(x, y);
        return true;
    }
    else if (pY == y) { //el personajes esta por debajo

        return true;
    }
    else if (pX == x) { //el personaje esta en la derecha

        return true;
    }
    else return false;
}
