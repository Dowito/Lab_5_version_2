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

    QList<Explotion *> *getExplosiones() const;
    void setExplosiones(QList<Explotion *> *newExplosiones);
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
    Ui::MainWindow *getUi() const;
    void setUi(Ui::MainWindow *newUi);
    short getNumBombs() const;
    void setNumBombs(short newNumBombs);

    Bloque *bloques[sizeMapY][sizeMapX];

public slots:
    void removeExplotion(Explotion* explosion); //CACA
    void removeBlock(Bloque *block);//CACA

private:
    short numBombs = 0;
    QList<Explotion*> *explosiones;
    QList<Enemigo*> *enemigos; //Cambiar a vector<vector<Bloque>> o usar una matriz bonica como la que use en matrizGames
    int **matrizGame; //Cambiar a vector<vector<int>>
    Personaje *personaje;
    QTimer *timer;
    QGraphicsScene *escena;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
