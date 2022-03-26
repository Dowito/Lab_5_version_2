#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <objeto.h>
#include <bomba.h>
/*!
 * \brief The Personaje class
 * Types:
 * y = 0
 * 0, 1, 2 frente, 1 estatico, 0 y 2 moviendoce
 * y = 1
 * 0, 1, 2 mirando lado izquierdo
 * y = 2
 * 0, 1, 2 mirando lado derecho
 * y = 3
 * 0, 1, 2 de espaldas
 */
class Personaje : public Objeto
{
public:
    Personaje(); //cargamos el sprite por difecto en el constructor

    bool putBomb(Bomba *bomba);

    short getBombs() const;
    void setBombs(short newBombs);

private:
    short bombs;
};

#endif // PERSONAJE_H
