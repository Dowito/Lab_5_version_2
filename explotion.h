#ifndef EXPLOTION_H
#define EXPLOTION_H
#include <objeto.h>
#include <enemigo.h>
#include <QTimer>
class Personaje;

class Explotion : public Objeto
{
    Q_OBJECT
public:
    Explotion();
    void start();

    void setTimer(QTimer *newTimer);

    void setEnemigos(QList<Enemigo *> *newEnemigos);

    void setPersonaje(Personaje *newPersonaje);

public slots:
    void removeExplotion();
    void collidingWithEnemy();
    void collidingWithPlayer();

signals:
    void remove(Explotion *explotion);

private:
    Personaje *personaje;
    QList<Enemigo*> *enemigos;
    QTimer timer;
};

#endif // EXPLOTION_H
