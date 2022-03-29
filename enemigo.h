#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <objeto.h>
#include <QTimer>
#include <QList>
/*!
 * \brief The Enemigo class:
 * sprites: Los sprites son iguales a los del personajes
 * existiran varios tipos de enemigos, unos mas veloces que otros.
 */
class MainWindow;
class QGraphicsScene;
class Enemigo : public Objeto
{
    Q_OBJECT
public:
    Enemigo() {};
    Enemigo(MainWindow *mainwindow);
    QTimer *getTimer() const;
    void setTimer(QTimer *newTimer);
    void setState(bool newState);
    void setTypeDead(int typeX = 0, int typeY = 0);
    bool getState() const;

signals:
    void stateChanged();
    void remove(Enemigo *enemy);

private slots:
    void moveAnimation();
    void moveEnemy();
    void startDead();
    void deadAnimation();

private:
    /*!
     * \brief changeDirection cambia la direccion por una direccion valida.
     * \return 0=abajo, 1=izquierda, 2=derecha, 3=arriba, de lo contrario significa que es no hay ninguna direccion donde moverce.
     */
    void generateType();
    void generateRandomPos();
    short changeDirection();
    bool state;
    short direction;
    short  frame;
    short count;
    QTimer *timer;
    QPixmap typeDead;
    QPixmap spriteDead;
    QList<Enemigo*> *enemigos;
    QGraphicsScene *escena;
    MainWindow *mainwindow;
};

#endif // ENEMIGO_H
