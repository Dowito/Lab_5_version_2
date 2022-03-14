#include "bloque.h"

Bloque::Bloque()
{
    sprite.load(":/images/Sprites/Bloques.png");
    floor.load(":/images/Sprites/piso.png");
}

void Bloque::setTypeFloor()
{
    setPixmap(floor.scaled(this->size, this->size));
}
