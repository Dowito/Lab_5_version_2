#ifndef BOMBA_H
#define BOMBA_H
#include <objeto.h>
#include <explotion.h>
#include <QTimer>
#include <QVector>
class Bomba : public Objeto
{
    Q_OBJECT
public:
    Bomba();
    void explote(QVector<Explotion*> &explotions, QVector<QVector<int>> &mBlocks, QVector<QVector<int>> &mBombs);
    void mX();
    void mY();

public slots:
    void startExplotion();
    void startBomb();

signals:
    void remove(Bomba *reBomba); //manda las coordenadas de la bomba a destruir

private:
    QTimer timer;
    short pot;
    int delay;
};

#endif // BOMBA_H
