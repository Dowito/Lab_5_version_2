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

    void moveEnemy();
     //tiene toda la logica de movimiento
 public slots:

private:
    short changeDirection();
};

#endif // ENEMIGO_H
