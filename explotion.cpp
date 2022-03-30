#include <explotion.h>
#include <mainwindow.h>
#include <personaje.h>
#include <bloque.h>
#include <enemigo.h>
Explotion::Explotion()
{
    sprite.load(":/images/Sprites/explosion.png");
    setSize(sizeGame);
    setFrame(0,1);
}

Explotion::Explotion(QPointF pos, MainWindow *mainwindow)
{
    this->mainwindow = mainwindow;
    //matrizGame = mainwindow->getMatrizGame();
    personaje = mainwindow->getPersonaje();
    enemigos = mainwindow->getEnemigos();
    gameClock = mainwindow->getTimer();
    escena = mainwindow->getEscena();
    sprite.load(":/images/Sprites/explosion.png");
    setSize(sizeGame);
    setFrame(0,1);
    setPos(pos);
    typeX = 0;
    typeY = 1;
    steps = 0;
    connect(gameClock, SIGNAL(timeout()), this, SLOT(die()));
    connect(gameClock, &QTimer::timeout, this, &Explotion::collidingWithEnemy);
    connect(gameClock, &QTimer::timeout, this, &Explotion::collidingWithPlayer);
    escena->addItem(this);
}

int Explotion::mX()
{
    int mX = (int)(x()/(size_sprites*sizeGame));
    return mX;
}

int Explotion::mY()
{
    int mY = (int)(x()/(size_sprites*sizeGame));
    return mY;
}

void Explotion::collidingWithEnemy()
{
    for (auto enemy : *enemigos) {
        if (collidesWithItem(enemy)) {
            enemy->setState(false);
            disconnect(gameClock, &QTimer::timeout, enemy, &Enemigo::deadAnimation);
            enemy->prepare2Die();
            connect(gameClock, &QTimer::timeout, enemy, &Enemigo::deadAnimation);
            break;
        }
    }
}

void Explotion::collidingWithPlayer()
{
    if(!personaje->getImmuneExplotions()) {
        if(collidesWithItem(personaje)){
            personaje->setState(false); //Con la escena, simplmente lo eliminaria aqui mismo sin encesidad de señales.
        }
    }
}

void Explotion::die()
{
    //Animacion
    if (steps >= 50) {
        disconnect(gameClock, SIGNAL(timeout()), this, SLOT(die()));
        escena->removeItem(this);
        /*if(matrizGame[mY()][mX()] == 1){
            matrizGame[mY()][mX()] = 9;
            mainwindow->bloques[mY()][mX()]->setTypeFloor();
        }*/
        delete this;
    }else steps++;
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
