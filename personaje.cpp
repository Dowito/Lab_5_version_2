#include "personaje.h"

Personaje::Personaje()
{
    sprite.load(":/images/Sprites/personaje.png");
    spriteDead.load(":/images/Sprites/personaje_herido.png");
    setSize(sizeGame);
    setFrame(1);
    state = true;
    lifes = LIFES;
    vel = velPlayer;
    bombs = bombsPlayer;
    immuneExplotions = IMMUNE_EXPLOTION;
    connect(this, SIGNAL(stateChanged()), this, SLOT(startDead()));
}

void Personaje::setTypeDead(int typeX, int typeY)
{
    typeDead = spriteDead.copy(typeX*size_sprites, typeY*size_sprites, size_sprites, size_sprites)
            .scaled(size, size);
    setPixmap(typeDead);
}

bool Personaje::putBomb(Bomba *bomba)
{
    int pX = ((int)x()/size)*size;
    int pY = ((int)y()/size)*size;
    int mX, mY;
    if (pX == x() && pY == y()) {
        mY = pY/size;
        mX = pX/size;
        if (matrizGame[mY][mX] != 2) {
            bomba->setPos(pX, pY);
            return true;
        }
    }
    else if (pY == y()) { //el personaje esta por la derecha
        if (x() <= (pX+((size-1)/2))) {
            mY = pY/size;
            mX = pX/size;
            if (matrizGame[mY][mX] != 2) {
                bomba->setPos(pX, pY);
                return true;
            }
        }
        else if (x() > (pX+((size-1)/2))) {
            mY = pY/size;
            mX = (pX+size)/size;
            if (matrizGame[mY][mX] != 2){
                bomba->setPos(pX+size, pY);
                return true;
            }
        }
        else return false;
    }
    else if (pX == x()) { //el personaje esta abajo
        if (y() <= (pY+((size-1)/2))) {
            mY = pY/size;
            mX = pX/size;
            if (matrizGame[mY][mX] != 2) {
                bomba->setPos(pX, pY);
                return true;
            }
        }
        else if (y() > (pY+((size-1)/2))) {
            mY = (pY+size)/size;
            mX = pX/size;
            if (matrizGame[mY][mX] != 2) {
                bomba->setPos(pX, pY+size);
                return true;
            }
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

QList<Enemigo *> *Personaje::getEnemigos() const
{
    return enemigos;
}

void Personaje::setEnemigos(QList<Enemigo *> *newEnemigos)
{
    enemigos = newEnemigos;
}

bool Personaje::getState() const
{
    return state;
}

void Personaje::setState(bool newState)
{
    if (state == newState)
        return;
    state = newState;
    emit stateChanged();
}

void Personaje::collidingWithEnemy()
{
    if(state){
        for (auto enemy : *enemigos) {
            if (collidesWithItem(enemy)) {
                if(enemy->getState()){
                    setState(false);
                    break;
                }
            }
        }
    }
}

void Personaje::startDead()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(deadAnimation()));
}

void Personaje::setTimer(QTimer *newTimer)
{
    timer = newTimer;
}

void Personaje::deadAnimation() //se daña a la segunda muerte
{
    static short  frame = 0;
    static short count = SPEED_DEAD;
    if (count == SPEED_DEAD) {
        setTypeDead(frame);
        count = 0;
        frame+=1;
        if(frame == 3) {
            disconnect(timer, SIGNAL(timeout()), this, SLOT(deadAnimation()));
            setLifes(getLifes()-1);
            frame = 0;
            count = SPEED_DEAD;
            connect(timer, SIGNAL(timeout()), this, SLOT(afterDie()));
        }
    }
    count++;
}

void Personaje::afterDie() //Se daña a la segunda muerte.
{
    static int count = 0;
    if (count == SPEED_DEAD*2) {
        disconnect(timer, SIGNAL(timeout()), this, SLOT(afterDie()));
        setPos(size,size);
        setFrame(1);
        state = true;
        count = 0;
    }else count++;
}

int Personaje::getLifes() const
{
    return lifes;
}

void Personaje::setLifes(int newLifes)
{
    if (lifes == newLifes)
        return;
    lifes = newLifes;
    emit lifesChanged();
}

void Personaje::moveAnimation(short direction)
{
    static short count = 1;
    static short frame = 0;
    if(direction>3) {
        setFrame(1);
    }
    else setFrame(frame, direction); //Siempre se tiene que actualizar la nueva direccion
    if(count == STEPS){
        if(direction>3) {
            setFrame(1);
        }
        else setFrame(frame, direction);
        count = 1;
        frame++;
        if (frame == 3) frame = 0;
    }
    else count++;
}

void Personaje::setImmuneExplotions(bool newImmuneExplotions)
{
    immuneExplotions = newImmuneExplotions;
}

bool Personaje::getImmuneExplotions() const
{
    return immuneExplotions;
}
