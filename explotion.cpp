#include <explotion.h>
#include <mainwindow.h>
#include <personaje.h>
#include <bloque.h>
#include <bomba.h>
#include <enemigo.h>
#include <QTimer>
#include <QGraphicsScene>
Explotion::Explotion(QPointF pos, MainWindow *mainwindow)
{
    this->mainwindow = mainwindow;
    matrizGame = mainwindow->getMatrizGame();
    personaje = mainwindow->getPersonaje();
    enemigos = mainwindow->getEnemigos();
    escena = mainwindow->getEscena();
    timer = mainwindow->getTimer();
    sprite.load(":/images/Sprites/explosion.png");
    setSize(sizeGame);
    setFrame(0,1);
    setPos(pos);
    typeX = 0;
    typeY = 1;
    steps = STEPS_EXPLOTION_ANIMATION;
    connect(timer, SIGNAL(timeout()), this, SLOT(animation()));
    connect(timer, SIGNAL(timeout()), this, SLOT(collidingWithEnemy()));
    connect(timer, SIGNAL(timeout()), this, SLOT(collidingWithPlayer()));
    connect(timer, SIGNAL(timeout()), this, SLOT(collidingWithBomb()));
    escena->addItem(this);
}

int Explotion::mX()
{
    int mX = (int)(x()/(size_sprites*sizeGame));
    return mX;
}

int Explotion::mY()
{
    int mY = (int)(y()/(size_sprites*sizeGame));
    return mY;
}

void Explotion::animation()
{
    if (steps >= STEPS_EXPLOTION_ANIMATION) {
        setFrame(typeX, typeY);
        typeX+=1;
        steps = 0;
        if(typeX==3) {
            if(typeY == 0) {
                remove();
            }
            else {
                typeX = 0;
                typeY = 0;
            }
        }
    }else steps++;
}

void Explotion::remove()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(remove()));
    escena->removeItem(this);
    if(matrizGame[mY()][mX()] == 1){
        matrizGame[mY()][mX()] = 9;
        mainwindow->bloques[mY()][mX()]->setTypeFloor();
    }
    delete this;
}

void Explotion::collidingWithEnemy()
{
    for (auto enemy : *enemigos) {
        if (collidesWithItem(enemy)) {
            enemy->die();
            break;
        }
    }
}

void Explotion::collidingWithPlayer()
{
    if(!personaje->getImmuneExplotions() && personaje->getState()) {
        if(collidesWithItem(personaje)){
            personaje->die();
        }
    }
}

void Explotion::collidingWithBomb()
{
    for (auto bomb : mainwindow->bombas) {
        if (collidesWithItem(bomb)) {
            bomb->chainExplote();
            break;
        }
    }
}


