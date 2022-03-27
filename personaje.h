#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <objeto.h>
#include <bomba.h>
#include <enemigo.h>
#include <QTimer>
#include <QList>
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
    Q_OBJECT
public:
    Personaje(); //cargamos el sprite por difecto en el constructor

    bool putBomb(Bomba *bomba);

    short getBombs() const;
    void setBombs(short newBombs);

    QList<Enemigo *> *getEnemigos() const;
    void setEnemigos(QList<Enemigo *> *newEnemigos);

    bool getState() const;
    void setState(bool newState);

    void setTypeDead(int typeX = 0, int typeY = 0);

    void setTimer(QTimer *newTimer);

public slots:
    void collidingWithEnemy();

signals:
    void stateChanged();

private:
    bool state = true; //Si esta vivo o muerto
    short bombs;
    QPixmap spriteDead;
    QPixmap typeDead;
    QTimer *timer;
    QList<Enemigo*> *enemigos;

private slots:
    void deadAnimation();

};

#endif // PERSONAJE_H
