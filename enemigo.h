#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <objeto.h>
#include <QTimer>
/*!
 * \brief The Enemigo class:
 * sprites: Los sprites son iguales a los del personajes
 * existiran varios tipos de enemigos, unos mas veloces que otros.
 */
class Enemigo : public Objeto
{
    Q_OBJECT
public:
    Enemigo() {};
    Enemigo(short type);
    void startEnemy();

    QTimer *getTimer() const;
    void setTimer(QTimer *newTimer);

private slots:
    void moveEnemy();

private:
    /*!
     * \brief changeDirection cambia la direccion por una direccion valida.
     * \return 0=abajo, 1=izquierda, 2=derecha, 3=arriba, de lo contrario significa que es no hay ninguna direccion donde moverce.
     */
    short changeDirection();
    short direction;
    QTimer *timer;
};

#endif // ENEMIGO_H
