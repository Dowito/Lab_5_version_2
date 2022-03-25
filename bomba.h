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
    void explote(QVector<Explotion*> &explotions, QVector<QVector<int>> &mBlocks);

public slots:
    void remove();
    void startBomb();

signals:
    void bombDestroyed(QPointF pos); //manda las coordenadas de la bomba a destruir

private:
    QTimer timer;
    short pot;
    int delay;
};

#endif // BOMBA_H
