#ifndef BOMBA_H
#define BOMBA_H
#include <objeto.h>
#include <QTimer>
#include <explotion.h>
#include <QVector>
class Bomba : public Objeto
{
    Q_OBJECT
public:
    Bomba();
    void explote(QVector<Explotion*> &explotions);

public slots:
    void remove();
    void startBomb();

signals:
    void bombDestroyed();

private:
    QTimer timer;
    short pot;
    int delay;
};

#endif // BOMBA_H
