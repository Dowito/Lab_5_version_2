#ifndef NIVEL_H
#define NIVEL_H
#include <QObject>
#include <QList>
#include <bomba.h>
#include <macros.h>
#include <QGraphicsScene>

class Nivel : QObject
{
    Q_OBJECT
public:
    Nivel();

    QGraphicsScene *getEscena() const;
    void setEscena(QGraphicsScene *newEscena);

public slots:
    void removeBomb();

private:
    QGraphicsScene *escena;
    short numBombas;
    QList<Bomba*> bombas;
};

#endif // NIVEL_H
