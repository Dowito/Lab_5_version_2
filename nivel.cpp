#include "nivel.h"

Nivel::Nivel()
{

}

void Nivel::removeBomb()
{
    auto it = bombas.begin();
    escena->removeItem(bombas.at(0));
    bombas.erase(it);
}

QGraphicsScene *Nivel::getEscena() const
{
    return escena;
}

void Nivel::setEscena(QGraphicsScene *newEscena)
{
    escena = newEscena;
}
