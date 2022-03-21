#ifndef OBJETO_H
#define OBJETO_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <macros.h>
#define size_sprites 48

class Objeto : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Objeto();

    void setSize(unsigned short size);

    void setFrame(int typeX = 0, int typeY = 0);

    short getVel() const;
    void setVel(short newVel);

    int **getMatrizGame() const;
    void setMatrizGame(int **newMatrizGame);

    bool tryMove(short direction);

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
