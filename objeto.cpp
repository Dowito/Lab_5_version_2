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

short Objeto::getVel() const
{
    return vel;
}

void Objeto::setVel(short newVel)
{
    vel = newVel;
}

void Objeto::tryMove(short direction)
{
    //hacia la derecha
    switch (direction) {
    case 0: //Abajo
        int mY = y()+vel;
        int mX1 = x(); //se revisa la ezquina mas a la izquierda de la hitbox
        int mX2 = x()+size; //se revisa la ezquina mas la aderecha de la hitbox
        if ([y()+vel][x()] != 9 && [y()+vel][x()+size] != 9) {

        }
        break;
    default:
        break;
    }
}
