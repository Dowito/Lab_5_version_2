#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene> //Para mostrar objetos enel graphicsview por medio de la escena
#include <QKeyEvent> //para leer las señales de las teclas
#include <QTimer> //temporalizador
#include <QVector>
#include <personaje.h>
#include <bloque.h>
#include <enemigo.h>
#include <QKeyEvent>

#define sizeMapX 15 //Solo numero impares
#define sizeMapY 11 //Solo numero impares
#define sizeGame 1
#define dificult 0.5

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *i);
    void createMap();
    void loadMap();

private:
    bool even_aleatorio(float p);

    Enemigo *enemigo[3];
    Bloque *bloques[sizeMapY][sizeMapX];
    short matrizGame[sizeMapY][sizeMapX];
    Personaje *personaje;
    QTimer *timer;
    QGraphicsScene *escena;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
