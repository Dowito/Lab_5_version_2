#include "enemigo.h"

Enemigo::Enemigo(short type)
{
    vel = 1;
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
    static unsigned short count = 0;
    static short direction = 0;
    //++count;
    //if (count == 5){
        count = 0;
        if (tryMove(direction)) { //si es posible el movimiento
            int mX = ((int)x())/(size_sprites*sizeGame);
            int mY = ((int)y())/(size_sprites*sizeGame);
            if ((int)x()%(size_sprites*sizeGame)==0 && (int)y()%(size_sprites*sizeGame)==0 && mX%2!=0 && mY%2!=0) { //si se esta en una intercepcion
                if (even_aleatorio(0.9)) { //si cambia de direccion
                    direction = changeDirection();
                }
                move(direction);
            }
            else { //si no se esta en una intercepccion, entonces se realiza el movimiento
                move(direction);
            }
        }
        else {//si no es posible el movimiento
            direction = changeDirection();
            move(direction);
        }
    //}
}

short Enemigo::changeDirection()
{
    short buffer[4];
    short count = 0;
    short mX = (int)x()/(size_sprites*sizeGame);
    short mY = (int)y()/(size_sprites*sizeGame);
    if (matrizGame[mY+1][mX] == 9) buffer[count] = 0, count++;
    if (matrizGame[mY][mX-1] == 9) buffer[count] = 1, count++;
    if (matrizGame[mY][mX+1] == 9) buffer[count] = 2, count++;
    if (matrizGame[mY-1][mX] == 9) buffer[count] = 3, count++;
    if (count == 0) return 916;
    count = 0+rand()%(count-0);//genera numeros aleatorios en el rango de 0-count que corresponde a algun indice valido del buffer que contiene una direccion
    return buffer[count];
}
