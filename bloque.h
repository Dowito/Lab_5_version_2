#ifndef BLOQUE_H
#define BLOQUE_H
#include <objeto.h>
class Explosion;

/*!
 * \brief The Bloque class
 * type:
 * 0.Bloque
 * 1.Ladrillo
 */
class Bloque : public Objeto
{
public:
    Bloque();

    void setType(int type);
    /*!
     * \brief setTypeFloor sprite de piso.
     */
    void setTypeFloor();
    int mX();
    int mY();

    void start();
    const QTimer &getTimer() const;
    void setTimer(const QTimer &newTimer);

    int getCount() const;
    void setCount(int newCount);

public slots:
    void destroy();

private:
    int count;
    QPixmap floor;//sprite del piso.
};

#endif // BLOQUE_H
