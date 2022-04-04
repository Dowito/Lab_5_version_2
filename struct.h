#ifndef STRUCT_H
#define STRUCT_H
#include <macros.h>
#include <QVector>
#include <QList>
#include <time.h>
#include <auxiliar.h>
class Bomba;
class Explotion;
class Enemigo;
class Bloque;
class Personaje;
class MainWindow;
class QGraphicsScene;
class QTimer;

class Datos
{
public:
    Datos() {};

    short getNumBombas() const;
    void setNumBombas(short newNumBombas);
    QList<Explotion *> *getExplosiones() const;
    void setExplosiones(QList<Explotion *> *newExplosiones);
    const QList<Bomba *> &getBombas() const;
    void setBombas(const QList<Bomba *> &newBombas);
    QList<Enemigo *> *getEnemigos() const;
    void setEnemigos(QList<Enemigo *> *newEnemigos);
    int **getMatrizGame() const;
    void setMatrizGame(int **newMatrizGame);
    Personaje *getPersonaje() const;
    void setPersonaje(Personaje *newPersonaje);
    QTimer *getTimer() const;
    void setTimer(QTimer *newTimer);
    QGraphicsScene *getEscena() const;
    void setEscena(QGraphicsScene *newEscena);
    MainWindow *getMainwindow() const;
    void setMainwindow(MainWindow *newMainwindow);

private:
    short numBombas;
    QList<Explotion*> *explosiones;
    QList<Bomba*> bombas;
    QList<Enemigo*> *enemigos;
    Bloque *bloques[sizeMapY][sizeMapX]; //Cambiar a vector<vector<Bloque>> o usar una matriz bonica como la que use en matrizGames
    int **matrizGame; //Cambiar a vector<vector<int>>
    Personaje *personaje;
    QTimer *timer;
    QGraphicsScene *escena;
    MainWindow *mainwindow;
};

#endif // STRUCT_H
