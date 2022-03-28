#include "bloque.h"
#include <explotion.h>
Bloque::Bloque()
{
    sprite.load(":/images/Sprites/Bloques.png");
    floor.load(":/images/Sprites/piso.png");
    count = 0;
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

void Bloque::destroy()
{
    emit remove(this);
}

int Bloque::getCount() const
{
    return count;
}

void Bloque::setCount(int newCount)
{
    count = newCount;
}
