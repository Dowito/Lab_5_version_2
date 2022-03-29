#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <macros.h>
#include <QMainWindow>
#include <QGraphicsScene> //Para mostrar objetos enel graphicsview por medio de la escena
#include <QKeyEvent> //para leer las señales de las teclas
#include <QTimer> //temporalizador
#include <QKeyEvent>
#include <QVector>
#include <QList>
#include <bloque.h>
#include <enemigo.h>
#include <bomba.h>
#include <time.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Personaje;

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
    Ui::MainWindow *getUi() const;
    void setUi(Ui::MainWindow *newUi);

private slots:
    void removeExplotion(Explotion* explosion); //CACA
    void removeBomb(Bomba *reBomba);//CACA
    void removeEnemy(Enemigo *enemy);//CACA
    void removeBlock(Bloque *block);//CACA
    void lcdUpdate();//CACA

private:

    Bomba* findBomb(QPointF pos);
    short numBombas;
    QList<Explotion*> *explosiones;
    QList<Bomba*> bombas;
    QList<Enemigo*> *enemigos;
    Bloque *bloques[sizeMapY][sizeMapX]; //Cambiar a vector<vector<Bloque>> o usar una matriz bonica como la que use en matrizGames
    int **matrizGame; //Cambiar a vector<vector<int>>
    Personaje *personaje;
    QTimer *timer;
    QGraphicsScene *escena;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
