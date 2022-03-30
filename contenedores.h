#ifndef CONTENEDORES_H
#define CONTENEDORES_H
#include <macros.h>
#include <time.h>
#include <auxiliar.h>
#include <QList>
class MainWindow;
class Bloque;
class Enemigo;
class Explotion;
class Personaje;
class QGraphicsScene;
class Bomba;
class QTimer;
class QKeyEvent;
class Contenedores
{
public:
    Contenedores(MainWindow *mainwindow);
    short *numBombs;
    int **matrizGame;
    Personaje *personaje;
    QTimer *timer;
    QGraphicsScene *escena;
    Bloque *bloques[sizeMapY][sizeMapX];
    QList<Bomba*> *bombas;
    QList<Enemigo*> *enemigos;
};

#endif // CONTENEDORES_H
