#include "contenedores.h"
#include <mainwindow.h>
Contenedores::Contenedores(MainWindow *mainwindow)
{
    numBombs = mainwindow->getNumBombas();
    matrizGame = mainwindow->getMatrizGame();
    personaje = mainwindow->getPersonaje();
    timer = mainwindow->getTimer();
    escena = mainwindow->getEscena();
    enemigos = mainwindow->getEnemigos();
    //Bloque *bloques[sizeMapY][sizeMapX];
    //bombas = mainwindow->getBombas();
}
