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
