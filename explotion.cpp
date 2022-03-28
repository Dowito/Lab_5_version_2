#include <explotion.h>
#include <personaje.h>
Explotion::Explotion()
{
    sprite.load(":/images/Sprites/explosion.png");
    setSize(sizeGame);
    setFrame(0,1);
}

void Explotion::setExploteBlockSprite()
{
    sprite.load(":/images/Sprites/bloque_Explosion.png");
    count = 0;
}

void Explotion::start()
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(removeExplotion()));
    connect(&timerAnimation, SIGNAL(timeout()), this, SLOT(animation()));
    typeX = 0;
    typeY = 1;
    timer.start(DELAY_EXPLOCION);
    timerAnimation.start((int)(DELAY_EXPLOCION/6));
}

void Explotion::removeExplotion()
{
    disconnect(&timer, SIGNAL(timeout()), this, SLOT(removeExplotion()));
    emit remove(this);
}

void Explotion::collidingWithEnemy()
{
    for (auto enemy : *enemigos) {
        if (collidesWithItem(enemy)) {
            enemy->setState(false);
            break;
        }
    }
}

void Explotion::collidingWithPlayer()
{
    if(!personaje->getImmuneExplotions()) {
        if(collidesWithItem(personaje)){
            personaje->setState(false);
        }
    }
}

void Explotion::setPersonaje(Personaje *newPersonaje)
{
    personaje = newPersonaje;
}

void Explotion::animation()
{
    setFrame(typeX, typeY);
    typeX+=1;
    if(typeX==3) {
        if(typeY == 0) disconnect(&timerAnimation, SIGNAL(timeout()), this, SLOT(animation()));
        typeX = 0;
        typeY = 0;
    }
}

void Explotion::setEnemigos(QList<Enemigo *> *newEnemigos)
{
    enemigos = newEnemigos;
}
