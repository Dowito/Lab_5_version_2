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
    static short direction = 0;
    if (tryMove(direction)) { //si es posible el movimiento
        int mX = x()/(size_sprites*sizeGame);
        int mY = y()/(size_sprites*sizeGame);
        if ((int)x()%(size_sprites*sizeGame)==0 && (int)x()%(size_sprites*sizeGame)==0 && mX%2!=2 && mY%2!=0) { //si se esta en una intercepcion
            //cambiar direccion 50/50
            //si cambia, cambiar mover
            //si no cambia, mover.
        }
        else { //si no se esta en una intercepccion, entonces se realiza el movimiento
            move(direction);
        }
    }
    else {//si no es posible el movimiento
        //cambiar direccion direccion
        //mover
        //si no existe una direccion valida, quedarce quieto
    }
}
