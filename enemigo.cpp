#include "enemigo.h"

Enemigo::Enemigo(short type)
{
    if (type == 0) {
        sprite.load(":/images/Sprites/hombre_lobo.png");
        vel = 3;
    }
    else if (type == 1) {
        sprite.load(":/images/Sprites/furro.png");
        vel = 6;
    }
    else if (type == 2) {
        sprite.load(":/images/Sprites/demonio.png");
        vel = 12;
    }
    else {
        sprite.load(":/images/Sprites/explosion.png");
        vel = 999;
    }
    direction = 0;
    setSize(sizeGame);
    setFrame(1);
}

void Enemigo::startEnemy()
{
    connect(&timer, &QTimer::timeout, this, &Enemigo::moveEnemy);
    timer.start(TIMER_ENEMY);
}

void Enemigo::moveEnemy()
{
    timer.stop();
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
    timer.start(TIMER_ENEMY);
}

bool Enemigo::tryMove(short direction)
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

void Enemigo::move(short direction)
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
