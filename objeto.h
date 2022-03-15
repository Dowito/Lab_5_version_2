#ifndef OBJETO_H
#define OBJETO_H
#include <QObject>
#include <QGraphicsPixmapItem>

#define size_sprites 48

class Objeto : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Objeto();

    void setSize(unsigned short size);

    void setFrame(int typeX = 0, int typeY = 0);

protected:
    QPixmap sprite; //aqui se guarda, por defecto, los sprites que corresponden a cada objeto.
    QPixmap type; //se crearan funciones que solo cojan la parte de sprite que se quiere ver en pantalla
    unsigned short size;
    unsigned short width;
    unsigned short height;
};

#endif // OBJETO_H
