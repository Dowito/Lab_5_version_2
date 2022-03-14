#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene> //Para mostrar objetos enel graphicsview por medio de la escena
#include <QKeyEvent> //para leer las señales de las teclas
#include <QTimer> //temporalizador
#include <personaje.h>
#include <bloque.h>
#define sizeMapX 31
#define sizeMapY 13
#define sizeGame 1
#define dificult 0.1

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void createMap();
    bool even_aleatorio(float p);

    short matrizGame[sizeMapX][sizeMapY];
    Bloque *bloque;
    Personaje *personaje;
    QTimer *time;
    QGraphicsScene *escena;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
