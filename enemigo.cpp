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
    static short direction = 0;
    if (firts) { //el primer movimiento se hace aqui
        if(tryMove(direction)){ //si se choca cambiar de direcion.
            firts = false;
        }
        else {
            //generar una nueva direccion segun las adyacencia disponibles, si no hay disponibles, quedarce quieto.
            firts = false;
        }
    }
    else {  //despues del primer movimiento.
        int mX = x()/(size_sprites*sizeGame);
        int mY = y()/(size_sprites*sizeGame);
        if ((int)x()%(size_sprites*sizeGame)==0 && (int)x()%(size_sprites*sizeGame)==0 && mX%2!=2 && mY%2!=0) { //Si esta juntamente en una unica casilla y si dicha casilla corresponde a un X e Y impar en la matriz, las cuales serian las intercepciones.

        }
        else {
            tryMove(direction);
        }
    }
}
