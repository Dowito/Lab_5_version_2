#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <macros.h>
#include <QMainWindow>
#include <time.h>
#include <QGraphicsScene> //Para mostrar objetos enel graphicsview por medio de la escena
#include <QKeyEvent> //para leer las señales de las teclas
#include <QTimer> //temporalizador
#include <QKeyEvent>
#include <QVector>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class Enemigo;
class Personaje;
class Bomba;
class Bloque;
class Explotion;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *i);
    void createMap();//CACA
    void loadMap();//CACA
    void putPlayer();//CACA
    void putEnemies();//CACA
    void lcdUpdate();

    short getNumBombs() const;
    void setNumBombs(short newNumBombs);
    int **getMatrizGame() const;
    QList<Enemigo *> *getEnemigos() const;
    Personaje *getPersonaje() const;
    void setPersonaje(Personaje *newPersonaje);
    QTimer *getTimer() const;
    QGraphicsScene *getEscena() const;

    Bloque *bloques[sizeMapY][sizeMapX];
    QList<Bomba*> bombas;

private:
    short numBombs = 0;
    QList<Enemigo*> *enemigos; //Cambiar a vector<vector<Bloque>> o usar una matriz bonica como la que use en matrizGames
    int **matrizGame; //Cambiar a vector<vector<int>>
    Personaje *personaje;
    QTimer *timer;
    QGraphicsScene *escena;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
