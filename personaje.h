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
    /*!
     * \brief move mueve el objeto
     * \param direction direccion hacia donde se mueva el objeto (0, 1, 2 o 3).
     */
    void move(short direction);
    /*!
     * \brief tryMove Si es valido el movimiento a realizar en dicha direccion
     * \param direction direccion a la que se quiere mover el objeto (0, 1, 2 o 3)
     * \return true si es valido el movimiento hacia dicha direccion, false de lo contrario.
     */
    bool tryMove(short direction);

    bool putBomb(Bomba *bomba);

    short getBombs() const;
    void setBombs(short newBombs);

private:
    short vel;
    short bombs;
};

#endif // PERSONAJE_H
