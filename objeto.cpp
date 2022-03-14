#include "objeto.h"

Objeto::Objeto()
{

}

void Objeto::setSize(unsigned short size)
{
    this->size = size_sprites*size;
    type = type.scaled(this->size, this->size);
}

void Objeto::setType(int typeX, int typeY)
{
    type = sprite.copy(typeX*size_sprites, typeY*size_sprites, size_sprites, size_sprites);
    setPixmap(type);
}
