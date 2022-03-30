#ifndef EXPLOTION_H
#define EXPLOTION_H
#include <objeto.h>
#include <QTimer>
class MainWindow;
class Personaje;
class Bloque;
class Enemigo;
class QGraphicsScene;
class Explotion : public Objeto
{
    Q_OBJECT
public:
    Explotion();
    Explotion(QPointF pos, MainWindow *mainwindow);
    int mX();
    int mY();

public slots:
    void collidingWithEnemy();
    void collidingWithPlayer();

signals:
    void remove(Explotion *explotion);

private:
    int steps;
    int typeX;
    int typeY;
    Bloque *bloque = nullptr;
    Personaje *personaje;
    QList<Enemigo*> *enemigos;
    QTimer timerAnimation;
    QTimer timer;
    QTimer *gameClock;
    QGraphicsScene *escena;
    MainWindow *mainwindow;

private slots:
    void animation();
    void remove();
};

#endif // EXPLOTION_H
