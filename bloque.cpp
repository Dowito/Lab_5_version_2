#include "bloque.h"
#include <explotion.h>
#include <mainwindow.h>
#include <QGraphicsScene>
Bloque::Bloque()
{
    sprite.load(":/images/Sprites/Bloques.png");
    floor.load(":/images/Sprites/piso.png");
    count = 0;
}

Bloque::Bloque(int mX, int mY, MainWindow *mainwindow)
{
    matrizGame = mainwindow->getMatrizGame();
    escena = mainwindow->getEscena();
    mainwindow->bloques[mY][mX] = this;
    sprite.load(":/images/Sprites/Bloques.png");
    floor.load(":/images/Sprites/piso.png");
    setSize(sizeGame);
    setType(matrizGame[mY][mX]);
    setPos(mX*size, mY*size);
    count = 0;
    escena->addItem(this);
}
void Bloque::setType(int type)
{
    if(type!=9) this->type = sprite.copy(type*size_sprites, 0, size_sprites, size_sprites).scaled(this->size, this->size);
    else this->type = floor.scaled(this->size, this->size);
    setPixmap(this->type);
}

void Bloque::setTypeFloor()
{
    setPixmap(floor.scaled(this->size, this->size));
}

int Bloque::mX()
{
    return x()/size;
}

int Bloque::mY()
{
    return y()/size;
}

int Bloque::getCount() const
{
    return count;
}

void Bloque::setCount(int newCount)
{
    count = newCount;
}
