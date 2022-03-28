#include <explotion.h>
#include <personaje.h>
Explotion::Explotion()
{
    sprite.load(":/images/Sprites/explosion.png");
    setSize(sizeGame);
    setFrame(0,1);
}

void Explotion::start()
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(removeExplotion()));
    timer.start(DELAY_EXPLOCION);
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

void Explotion::setEnemigos(QList<Enemigo *> *newEnemigos)
{
    enemigos = newEnemigos;
}
