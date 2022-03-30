#ifndef BOMBA_H
#define BOMBA_H
#include <objeto.h>
#include <explotion.h>
#include <QTimer>
#include <QVector>
class MainWindow;
class Bomba : public Objeto
{
    Q_OBJECT
public:
    Bomba();
    Bomba(QPointF pos, MainWindow mainwindow);
    void explote(QVector<Explotion*> &explotions, QVector<QVector<int>> &mBlocks, QVector<QVector<int>> &mBombs);
    int mX();
    int mY();

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
