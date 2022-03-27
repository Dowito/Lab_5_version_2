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
     * \brief tryMove Si es valido el movimiento a realizar en dicha direccion
     * \param direction direccion a la que se quiere mover el objeto (0, 1, 2 o 3)
     * \return true si es valido el movimiento hacia dicha direccion, false de lo contrario.
     */
    bool tryMove(short direction);
    /*!
     * \brief move mueve el objeto
     * \param direction direccion hacia donde se mueva el objeto (0, 1, 2 o 3).
     */
    void move(short direction);
    /*!
     * \brief changeDirection cambia la direccion por una direccion valida.
     * \return 0=abajo, 1=izquierda, 2=derecha, 3=arriba, de lo contrario significa que es no hay ninguna direccion donde moverce.
     */
    short changeDirection();

    short vel;
    short direction;
    QTimer *timer;
};

#endif // ENEMIGO_H
