#include "struct.h"
#include <bloque.h>
#include <enemigo.h>
#include <explotion.h>
#include <objeto.h>
#include <personaje.h>
#include <QGraphicsScene>
#include <QTimer>

short Datos::getNumBombas() const
{
    return numBombas;
}

void Datos::setNumBombas(short newNumBombas)
{
    numBombas = newNumBombas;
}

QList<Explotion *> *Datos::getExplosiones() const
{
    return explosiones;
}

void Datos::setExplosiones(QList<Explotion *> *newExplosiones)
{
    explosiones = newExplosiones;
}

const QList<Bomba *> &Datos::getBombas() const
{
    return bombas;
}

void Datos::setBombas(const QList<Bomba *> &newBombas)
{
    bombas = newBombas;
}

QList<Enemigo *> *Datos::getEnemigos() const
{
    return enemigos;
}

void Datos::setEnemigos(QList<Enemigo *> *newEnemigos)
{
    enemigos = newEnemigos;
}

int **Datos::getMatrizGame() const
{
    return matrizGame;
}

void Datos::setMatrizGame(int **newMatrizGame)
{
    matrizGame = newMatrizGame;
}

Personaje *Datos::getPersonaje() const
{
    return personaje;
}

void Datos::setPersonaje(Personaje *newPersonaje)
{
    personaje = newPersonaje;
}

QTimer *Datos::getTimer() const
{
    return timer;
}

void Datos::setTimer(QTimer *newTimer)
{
    timer = newTimer;
}

QGraphicsScene *Datos::getEscena() const
{
    return escena;
}

void Datos::setEscena(QGraphicsScene *newEscena)
{
    escena = newEscena;
}

MainWindow *Datos::getMainwindow() const
{
    return mainwindow;
}

void Datos::setMainwindow(MainWindow *newMainwindow)
{
    mainwindow = newMainwindow;
}
