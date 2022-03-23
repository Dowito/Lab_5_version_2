#include "bomba.h"

Bomba::Bomba()
{
    sprite.load(":/images/Sprites/bomba.png");
    setSize(sizeGame);
    setFrame(1);
    setMatrizGame(matrizGame);
}
