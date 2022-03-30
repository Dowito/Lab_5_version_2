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
    int mX();
    int mY();

private:
    void generateExplotions();
    int steps;
    short pot;
    QTimer *timer;
    QGraphicsScene *escena;
    MainWindow *mainwindow;

private slots:
    void explote();
};

#endif // BOMBA_H
