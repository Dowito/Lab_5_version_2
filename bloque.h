#ifndef BLOQUE_H
#define BLOQUE_H
#include <objeto.h>
#include <contenedores.h>
class QGraphicsScene;
/*!
 * \brief The Bloque class
 * type:
 * 0.Bloque
 * 1.Ladrillo
 */
class Bloque : public Objeto
{
    Q_OBJECT
public:
    Bloque();
    Bloque(int mX, int mY, MainWindow *mainwindow);
    void setType(int type);
    void setTypeFloor();
    int mX();
    int mY();

    const QTimer &getTimer() const;
    void setTimer(const QTimer &newTimer);
    int getCount() const;
    void setCount(int newCount);

private:
    int count;
    QPixmap floor;//sprite del piso.
    QGraphicsScene *escena;
};

#endif // BLOQUE_H
