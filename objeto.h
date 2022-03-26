#ifndef OBJETO_H
#define OBJETO_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <macros.h>
#include <auxiliar.h>

class Objeto : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Objeto();

    void setSize(unsigned short size);
    unsigned short getSize() const;

    void setFrame(int typeX = 0, int typeY = 0);

    short getVel() const;
    void setVel(short newVel);

    int **getMatrizGame() const;
    void setMatrizGame(int **newMatrizGame);

    /*!
     * \brief tryMove Si es valido el movimiento a realizar en dicha direccion
     * \param direction direccion a la que se quiere mover el objeto (0, 1, 2 o 3)
     * \return true si es valido el movimiento hacia dicha direccion, false de lo contrario.
     */
    bool tryMove(short direction);

    /*!
     * \brief move mueve el objeto
     * \param direction direccion hacia donde se mueva el objeto (0, 1, 2 o 3).
     */
    void move(short direction);

protected:
    int **matrizGame;
    QPixmap sprite; //aqui se guarda, por defecto, los sprites que corresponden a cada objeto.
    QPixmap type; //se crearan funciones que solo cojan la parte de sprite que se quiere ver en pantalla
    short vel = 0;
    unsigned short size;
    unsigned short width;
    unsigned short height;
};

#endif // OBJETO_H
