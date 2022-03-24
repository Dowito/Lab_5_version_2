#ifndef BOMBA_H
#define BOMBA_H
#include <objeto.h>
#include <QTimer>

class Bomba : public Objeto
{

public:
    Bomba();

public slots:
    void explotion();
    void startBomb();

signals:
    void bombDestroyed() {};

private:

    QTimer timer;
    int delay;
};

#endif // BOMBA_H
