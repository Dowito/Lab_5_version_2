#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <objeto.h>
#include <QGraphicsScene>
#include <bomba.h>
#include <enemigo.h>
#include <QTimer>
#include <QList>
class MainWindow;
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
    Personaje(int **matrizGame, QList<Enemigo *> *enemigos, QTimer *timer, QGraphicsScene *escena); //cargamos el sprite por difecto en el constructor
    Personaje(MainWindow *caca);
    bool putBomb(Bomba *bomba);
    void moveAnimation(short direction);
    short getBombs() const;
    void setBombs(short newBombs);
    QList<Enemigo *> *getEnemigos() const;
    void setEnemigos(QList<Enemigo *> *newEnemigos);
    bool getState() const;
    void setState(bool newState);
    void setTypeDead(int typeX = 0, int typeY = 0);
    void setTimer(QTimer *newTimer);
    bool getImmuneExplotions() const;
    void setImmuneExplotions(bool newImmuneExplotions);
    int getLifes() const;
    void setLifes(int newLifes);

public slots:
    void collidingWithEnemy();

signals:
    void lifesChanged();

private slots:
    void startDead();
    void deadAnimation();
    void afterDie();

private:
    int lifes;
    bool state; //Si esta vivo o muerto
    bool immuneExplotions;
    short bombs;
    QPixmap spriteDead;
    QPixmap typeDead;
    QTimer *timer;
    QList<Enemigo*> *enemigos;
    QGraphicsScene *escena;
};

#endif // PERSONAJE_H
