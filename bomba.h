#ifndef BOMBA_H
#define BOMBA_H
#include <objeto.h>

class Bomba : public Objeto
{
public:
    Bomba();

signals:
    void destroyBomb();

};

#endif // BOMBA_H
