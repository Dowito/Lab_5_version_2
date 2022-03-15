#include "bloque.h"

Bloque::Bloque()
{
    sprite.load(":/images/Sprites/Bloques.png");
    floor.load(":/images/Sprites/piso.png");
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
