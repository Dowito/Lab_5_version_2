#include "bomba.h"

Bomba::Bomba()
{
    sprite.load(":/images/Sprites/bomba.png");
    setSize(sizeGame);
    setFrame(1);
    delay = DELAY;
}

void Bomba::explote(QVector<Explotion *> &explotions)
{
    Explotion *explotion;
    explotion = new Explotion;
    explotion->setPos(x(), y());
    explotions.push_back(explotion);
}

void Bomba::remove()
{
    setFrame(1,50);
    emit bombDestroyed();
}

void Bomba::startBomb()
{
    connect(&timer, &QTimer::timeout, this, &Bomba::remove);
    timer.start(delay);
}
