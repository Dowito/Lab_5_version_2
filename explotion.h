#ifndef EXPLOTION_H
#define EXPLOTION_H
#include <objeto.h>
#include <QTimer>
class Personaje;
class Bloque;
class Enemigo;
class Explotion : public Objeto
{
    Q_OBJECT
public:
    Explotion();
    void setExploteBlockSprite();
    void start();
    void setEnemigos(QList<Enemigo *> *newEnemigos);
    void setPersonaje(Personaje *newPersonaje);

    void setBloque(Bloque *newBloque);


    void setGameClock(QTimer *newGameClock);

public slots:
    void animation();
    void removeExplotion();
    void collidingWithEnemy();
    void collidingWithPlayer();

signals:
    void remove(Explotion *explotion);

private:
    int count;
    int typeX;
    int typeY;
    Bloque *bloque = nullptr;
    Personaje *personaje;
    QList<Enemigo*> *enemigos;
    QTimer timerAnimation;
    QTimer timer;
    QTimer *gameClock;
};

#endif // EXPLOTION_H
