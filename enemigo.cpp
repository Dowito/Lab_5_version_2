#include "enemigo.h"

Enemigo::Enemigo(short type)
{
    if (type == 0) {
        sprite.load(":/images/Sprites/hombre_lobo.png");
        vel = 2;
    }
    else if (type == 1) {
        sprite.load(":/images/Sprites/furro.png");
        vel = 3;
    }
    else {
        sprite.load(":/images/Sprites/demonio.png");
        vel = 5;
    }
}

void Enemigo::moveEnemy()
{
    //setX(x()+vel); //posicion actual en x y la cambia en vel.
    static bool firts = true;
    static int direction = 0;
    if (firts) {
        tryMove(direction); //si se choca cambiar de direcion.
        firts = false;
    }
    else {


    }
    direction = 2;
    tryMove(direction);
}
