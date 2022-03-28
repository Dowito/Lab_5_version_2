#ifndef EXPLOTION_H
#define EXPLOTION_H
#include <objeto.h>
#include <enemigo.h>
#include <QTimer>
class Explotion : public Objeto
{
    Q_OBJECT
public:
    Explotion();
    void start();

    void setTimer(QTimer *newTimer);

    void setEnemigos(QList<Enemigo *> *newEnemigos);

public slots:
    void removeExplotion();
    void collidingWithEnemy();

signals:
    void remove(Explotion *explotion);

private:
    QList<Enemigo*> *enemigos;
    QTimer timer;
};

#endif // EXPLOTION_H
