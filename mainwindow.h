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
#include <macros.h>


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
    Enemigo *enemigo[3];
    Bloque *bloques[sizeMapY][sizeMapX];
    int **matrizGame;
    Personaje *personaje;
    QTimer *timer[2];
    QGraphicsScene *escena;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
