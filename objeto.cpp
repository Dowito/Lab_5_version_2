#include "objeto.h"

Objeto::Objeto()
{

}

void Objeto::setSize(unsigned short size)
{
    this->size = size_sprites*size;
}

void Objeto::setFrame(int typeX, int typeY)
{
    type = sprite.copy(typeX*size_sprites, typeY*size_sprites, size_sprites, size_sprites)
            .scaled(this->size, this->size);
    setPixmap(type);
}

unsigned short Objeto::getSize() const
{
    return size;
}

int **Objeto::getMatrizGame() const
{
    return matrizGame;
}

void Objeto::setMatrizGame(int **newMatrizGame)
{
    matrizGame = newMatrizGame;
}
