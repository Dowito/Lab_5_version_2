#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <objeto.h>

/*!
 * \brief The Enemigo class:
 * sprites: Los sprites son iguales a los del personajes
 * existiran varios tipos de enemigos, unos mas veloces que otros.
 */
class Enemigo : public Objeto
{

public:
    Enemigo() {};
    Enemigo(short type);

public slots:
    void move(); //tiene toda la logica de movimiento

private:

};

#endif // ENEMIGO_H
