#ifndef BLOQUE_H
#define BLOQUE_H
#include <objeto.h>

class Bloque : public Objeto
{
public:
    Bloque();
    /*!
     * \brief setType sprite de piso.
     */
    void setTypeFloor();
private:
    QPixmap floor;//sprite del piso.
};

#endif // BLOQUE_H
