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
    Explotion(QPointF pos, MainWindow *mainwindow);
    int mX();
    int mY();

public slots:
    void collidingWithEnemy();
    void collidingWithPlayer();

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
};

#endif // EXPLOTION_H
