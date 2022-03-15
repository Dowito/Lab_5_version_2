#ifndef BLOQUE_H
#define BLOQUE_H
#include <objeto.h>

/*!
 * \brief The Bloque class
 * type:
 * 0.Bloque
 * 1.Ladrillo
 */
class Bloque : public Objeto
{
public:
    Bloque();
    /*!
     * \brief setTypeFloor sprite de piso.
     */
    void setTypeFloor();
private:
    QPixmap floor;//sprite del piso.
};

#endif // BLOQUE_H
