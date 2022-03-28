#include "enemigo.h"

Enemigo::Enemigo(short type)
{
    //vel solo puede tomar valores multiplos de 48
    if (type == 0) {
        sprite.load(":/images/Sprites/hombre_lobo.png");
        spriteDead.load(":/images/Sprites/hombre_lobo_dead.png");
        vel = 2;
    }
    else if (type == 1) {
        sprite.load(":/images/Sprites/furro.png");
        spriteDead.load(":/images/Sprites/furro_dead.png");
        vel = 4;
    }
    else if (type == 2) {
        sprite.load(":/images/Sprites/demonio.png");
        spriteDead.load(":/images/Sprites/demonio_dead.png");
        vel = 6;
    }
    else {
        sprite.load(":/images/Sprites/explosion.png");
        spriteDead.load(":/images/Sprites/personaje_herido.png");
        vel = 999;
    }
    state = true;
    frame = 0;
    count = 0;
    direction = 0;
    setSize(sizeGame);
    setFrame(1);
}

void Enemigo::startEnemy()
{
    if(IFMOVE) connect(timer, &QTimer::timeout, this, &Enemigo::moveEnemy),
               connect(this, SIGNAL(stateChanged()), this, SLOT(startDead()));
}

void Enemigo::moveEnemy()
{
    if(state){
        if (tryMove(direction)) { //si es posible el movimiento
            int mX = ((int)x())/(size_sprites*sizeGame);
            int mY = ((int)y())/(size_sprites*sizeGame);
            if ((int)x()%(size_sprites*sizeGame)==0 && (int)y()%(size_sprites*sizeGame)==0 && mX%2!=0 && mY%2!=0) { //si se esta en una intercepcion
                if (even_aleatorio(0.5)) { //si cambia de direccion
                    direction = changeDirection();
                    setFrame(frame, direction);
                }
            }
        }
        else {//si no es posible el movimiento
            direction = changeDirection();
        }
        move(direction);
        moveAnimation();
    }
}

void Enemigo::moveAnimation()
{
    if(direction>3) {
        setFrame(1);
    }
    else setFrame(frame, direction); //Siempre se tiene que actualizar la nueva direccion
    if(count == SPEED_MOVE_ANIMATION){
        if(direction>3) {
            setFrame(1);
        }
        else setFrame(frame, direction);
        count = 0;
        frame++;
        if (frame == 3) frame = 0;
    }
    else count++;
}

void Enemigo::startDead()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveAnimation()));
    count = SPEED_DEAD;
    frame = 0;
    connect(timer, SIGNAL(timeout()), this, SLOT(deadAnimation()));
}

void Enemigo::deadAnimation()
{
    if (count == SPEED_DEAD) {
        if(frame == 3) {
            disconnect(timer, SIGNAL(timeout()), this, SLOT(deadAnimation()));
            emit remove(this);
            return;
        }
        setTypeDead(frame);
        count = 0;
        frame+=1;

    }
    count++;
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

bool Enemigo::getState() const
{
    return state;
}

void Enemigo::setState(bool newState)
{
    if (state == newState)
        return;
    state = newState;
    emit stateChanged();
}

void Enemigo::setTypeDead(int typeX, int typeY)
{
    typeDead = spriteDead.copy(typeX*size_sprites, typeY*size_sprites, size_sprites, size_sprites)
            .scaled(size, size);
    setPixmap(typeDead);
}

QTimer *Enemigo::getTimer() const
{
    return timer;
}

void Enemigo::setTimer(QTimer *newTimer)
{
    timer = newTimer;
}
