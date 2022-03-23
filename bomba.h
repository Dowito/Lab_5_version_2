#ifndef BOMBA_H
#define BOMBA_H
#include <objeto.h>

class Bomba : public Objeto
{
public:
    Bomba();
    bool putBomb(int x, int y);
};

#endif // BOMBA_H
