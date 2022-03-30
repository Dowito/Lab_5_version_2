#ifndef BOMBA_H
#define BOMBA_H
#include <objeto.h>
#include <QGraphicsScene>
#include <QTimer>
#include <QVector>
#include <QList>
class MainWindow;
class Explotion;
class Bomba : public Objeto
{
    Q_OBJECT
public:
    Bomba(QPointF pos, MainWindow *mainwindow);
    void explote(QVector<Explotion*> &explotions, QVector<QVector<int>> &mBlocks);
    int mX();
    int mY();

signals:
    void remove(Bomba *reBomba); //manda las coordenadas de la bomba a destruir

private:
    int steps;
    short pot;
    QTimer *timer;
    QGraphicsScene *escena;
    MainWindow *mainwindow;

private slots:
    void explote();
};

#endif // BOMBA_H
