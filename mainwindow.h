#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QString>

#include <personaje.h>
#include <bloque.h>

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
    Bloque *bloque;
    Personaje *personaje;
    QTimer *time;
    QGraphicsScene *escena;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
