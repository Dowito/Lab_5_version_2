#include "objeto.h"

Objeto::Objeto()
{

}

void Objeto::setType(int typeX, int typeY)
{
    type = sprite.copy(typeX*size_sprites, typeY*size_sprites, size_sprites, size_sprites);
}
