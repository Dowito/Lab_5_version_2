#ifndef BOMBA_H
#define BOMBA_H
#include <objeto.h>
#include <contenedores.h>
class Bomba : public Objeto
{
    Q_OBJECT
public:
    Bomba();
    Bomba(QPointF pos, MainWindow *mainwindow);
    int mX();
    int mY();
    void chainExplote();

private:
    void generateExplotions();
    int steps;
    short pot;
    QList<Bomba*> *bombas;
    QTimer *timer;
    QGraphicsScene *escena;
    MainWindow *mainwindow;

private slots:
    void explote();
};

#endif // BOMBA_H
