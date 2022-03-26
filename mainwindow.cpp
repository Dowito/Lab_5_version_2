#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    enemigos = new QList<Enemigo*>;
    timer = new QTimer;

    ui->setupUi(this);
    setGeometry(0,0,48*sizeMapX*sizeGame,48*sizeMapY*sizeGame+2*48);
    ui->graphicsView->setGeometry(0,0,width(),height()-2*48);
    ui->VIDAS->setGeometry(1*48*sizeGame,12*48*sizeGame,51,20);
    escena = new QGraphicsScene;
    escena->setSceneRect(0,0,ui->graphicsView->width()-2,ui->graphicsView->height()-2);

    createMap();
    loadMap();
    putEnemies();

    ui->graphicsView->setScene(escena);
    timer->start(clockGame);
}

MainWindow::~MainWindow()
{
    delete personaje;
    delete **bloques;
    delete matrizGame;
    delete timer;//no se si daba eliminarlo
    delete escena;//no e si deba eliminarlo
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *i)
{
    if (i->key() == Qt::Key_S) {
        if(personaje->tryMove(0)) personaje->move(0);
    }
    else if (i->key()  == Qt::Key_A) {
        if(personaje->tryMove(1)) personaje->move(1);
    }
    else if (i->key() == Qt::Key_D) {
        if(personaje->tryMove(2)) personaje->move(2);
    }
    else if (i->key() == Qt::Key_W) {
        if(personaje->tryMove(3)) personaje->move(3);
    }
    else if (i->key() == Qt::Key_Space) {
        if (numBombas < personaje->getBombs()){
            Bomba *bomba = new Bomba;
            bomba->setMatrizGame(matrizGame);
            if(personaje->putBomb(bomba)){
                int mY = bomba->y()/(size_sprites*sizeGame);
                int mX = bomba->x()/(size_sprites*sizeGame);
                matrizGame[mY][mX] = 2;
                bombas.push_back(bomba);
                connect(bomba, &Bomba::bombDestroyed, this, &MainWindow::removeBomb); //manda las coordenadas de la bomba a destruir a la funcion removeBomb
                bomba->startBomb();
                escena->addItem(bomba);
                numBombas++;
            }
            else delete bomba;
        }
    }
    else return;
}

void MainWindow::createMap()
{
    matrizGame = new int *[sizeMapY];
    for (short i = 0; i<sizeMapY; i++) {
        matrizGame[i] = new int [sizeMapX];
    }
    for (int y=0; y<sizeMapY; y++) {
        for (int x=0; x<sizeMapX; x++) {
            if ((x==1 && y==1) || (x==2 && y==1) || (x==1 && y==2)) matrizGame[y][x] = 9;

            else if (x==0 || y==0 || x==sizeMapX-1 || y==sizeMapY-1 || (x%2==0 && y%2==0)) { //imprimir los bloques no destructibles
                matrizGame[y][x] = 0; //typeX=0 corresponde al bloque
            }
            else if (even_aleatorio(dificult)) { //imprimir destruibles
                matrizGame[y][x] = 1; //typeX=1 corresponde al ladrillo
            }
            else matrizGame[y][x] = 9; //cualquier otra cosa corresponde al piso
        }
    }
}

void MainWindow::loadMap()
{
    for (int y=0; y<sizeMapY; y++) {
        for (int x=0; x<sizeMapX; x++) {
            if(x==1 && y==1) {
                personaje = new Personaje;
                personaje->setMatrizGame(matrizGame); //Le paso la matriz al personaje
                personaje->setSize(sizeGame);
                personaje->setFrame(1);
                personaje->setPos(1*48,1*48);
            }
            bloques[y][x] = new Bloque;
            bloques[y][x]->setSize(sizeGame);
            bloques[y][x]->setType(matrizGame[y][x]); //lo inicio segun el tipo que me de la matriz
            bloques[y][x]->setPos(x*size_sprites*sizeGame, y*size_sprites*sizeGame); //con hacemos una cuadicula, en al que cada casilla sera del tamaño de los sprites
            escena->addItem(bloques[y][x]);
        }
    }
    escena->addItem(personaje);//Aqui para que aparesca encima de los bloques y no alreves.
}

void MainWindow::putEnemies()
{
    int y, x;
    for(short i = 0; i<MAX_ENEMIES; i++){
        y = 1+rand()%((sizeMapY-1)-1);
        x = 6+rand()%((sizeMapX-1)-6);
        if (y%2 == 0 && x%2 == 0) x += 1;
        bloques[y][x]->setTypeFloor();
        matrizGame[y][x] = 9;
        short type = 0+rand()%(3-0);
        Enemigo *enemy;
        enemy = new Enemigo(type);
        enemy->setPos(x*enemy->getSize(),y*enemy->getSize());
        enemy->setMatrizGame(matrizGame);
        connect(timer, &QTimer::timeout, enemy, &Enemigo::moveEnemy);

        enemigos->push_back(enemy);
        //pasarcelos a personaje.
        escena->addItem(enemy);
    }
}

void MainWindow::removeBomb(Bomba *reBomba)
{
    disconnect(reBomba, &Bomba::bombDestroyed, this, &MainWindow::removeBomb);
    QVector<Explotion*> explotions;
    QVector<QVector<int>> mBlocks;
    QVector<QVector<int>> mBombs;
    numBombas -= 1;
    reBomba->explote(explotions, mBlocks, mBombs);
    int mY = reBomba->y()/(size_sprites*sizeGame);
    int mX = reBomba->x()/(size_sprites*sizeGame);
    matrizGame[mY][mX] = 9;
    escena->removeItem(reBomba);
    bombas.removeOne(reBomba);
    delete reBomba;
    /*//Cadena de Bombas
    for (auto mChainPos : qAsConst(mBombs)) {
        qreal chainX = mChainPos[0]*(size_sprites*sizeGame);
        qreal chainY = mChainPos[1]*(size_sprites*sizeGame);
        QPointF chainPos = {static_cast<qreal>(chainX),static_cast<qreal>(chainY)};
        auto chainBomb = findBomb(chainPos);
        chainBomb->remove();
    }
    */
    for (auto mPos : qAsConst(mBlocks)) {
        matrizGame[mPos[1]][mPos[0]] = 9;
        //animacion de destruccion bloque
        bloques[mPos[1]][mPos[0]]->setTypeFloor();
    }
    for (Explotion *value : qAsConst(explotions)) {
        escena->addItem(value);
    }
    connect(this, &MainWindow::destroyExplotions, this, &MainWindow::removeExplotion);
    emit destroyExplotions(explotions);
}

void MainWindow::removeExplotion(QVector<Explotion*> &explotions)
{
    disconnect(this, &MainWindow::destroyExplotions, this, &MainWindow::removeExplotion);
    for (Explotion *value : qAsConst(explotions)) {
        escena->removeItem(value);
    }

}

void MainWindow::on_pushButton_clicked()
{
    /*bomba = new Bomba;
    bomba->setPos(personaje->x(),personaje->y());
    escena->addItem(bomba);*/
}


void MainWindow::on_quitarbomba_clicked()
{
    /*escena->removeItem(bomba);
    bomba = nullptr;*/
}

Bomba *MainWindow::findBomb(QPointF pos)
{
    for (auto value : qAsConst(bombas)) {
        if(value->pos() == pos) return value;
    }
    Bomba *bomb = nullptr;
    return bomb;
}

