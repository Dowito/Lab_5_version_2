#ifndef EXPLOTION_H
#define EXPLOTION_H
#include <objeto.h>
#include <QTimer>
class Explotion : public Objeto
{
    Q_OBJECT
public:
    Explotion();
    void start();

    void setTimer(QTimer *newTimer);

public slots:
    void removeExplotion();

signals:
    void remove(Explotion *explotion);

private:
    QTimer timer;
};

#endif // EXPLOTION_H
