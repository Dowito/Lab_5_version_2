#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <contenedores.h>
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
    void createMap();//CACA
    void loadMap();//CACA
    void putPlayer();//CACA
    void putEnemies();//CACA
    void lcdUpdate();
    void updateContainers();

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

    short *getNumBombas() const;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

private:
    short *numBombas;
    short numBombs = 0;
    QList<Enemigo*> *enemigos; //Cambiar a vector<vector<Bloque>> o usar una matriz bonica como la que use en matrizGames
    int **matrizGame; //Cambiar a vector<vector<int>>
    Personaje *personaje;
    QTimer *timer;
    QGraphicsScene *escena;
    Ui::MainWindow *ui;
    Contenedores *contenedores;
};
#endif // MAINWINDOW_H
