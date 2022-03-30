#ifndef EXPLOTION_H
#define EXPLOTION_H
#include <objeto.h>
#include <contenedores.h>
class Explotion : public Objeto
{
    Q_OBJECT
public:
    Explotion(QPointF pos, MainWindow *mainwindow);
    int mX();
    int mY();

private:
    int steps;
    int typeX;
    int typeY;
    Personaje *personaje;
    QList<Enemigo*> *enemigos;
    QTimer *timer;
    QGraphicsScene *escena;
    MainWindow *mainwindow;

private slots:
    void animation();
    void remove();
    void collidingWithEnemy();
    void collidingWithPlayer();
    void collidingWithBomb();
};

#endif // EXPLOTION_H
