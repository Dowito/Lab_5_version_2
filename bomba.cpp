#include "bomba.h"

Bomba::Bomba()
{
    sprite.load(":/images/Sprites/bomba.png");
    setSize(sizeGame);
    setFrame(1);
    setMatrizGame(matrizGame);
    delay = DELAY;
}

void Bomba::explotion()
{
    setFrame(1,50);
    emit bombDestroyed();
}

void Bomba::startBomb()
{
    connect(&timer, &QTimer::timeout, this, &Bomba::explotion);
    timer.start(delay);
}
