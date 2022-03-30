#ifndef BOMBA_H
#define BOMBA_H
#include <objeto.h>
#include <explotion.h>
#include <QTimer>
#include <QVector>
#include <QList>
class MainWindow;
class Bomba : public Objeto
{
    Q_OBJECT
public:
    Bomba();
    Bomba(QPointF pos, MainWindow *mainwindow);
    void explote(QVector<Explotion*> &explotions, QVector<QVector<int>> &mBlocks, QVector<QVector<int>> &mBombs);
    int mX();
    int mY();

public slots:
    void startExplotion();
    void startBomb();

signals:
    void remove(Bomba *reBomba); //manda las coordenadas de la bomba a destruir

private:
    int count;
    short pot;
    int delay;
    QList<Bomba*> *bombas;
    MainWindow *mainwindow;
    QTimer *timer;
    QTimer bombTimer;
};

#endif // BOMBA_H
