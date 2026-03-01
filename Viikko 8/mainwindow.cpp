#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pQTimer = new QTimer(this);

    connect(pQTimer, SIGNAL(timeout()), this, SLOT(timeout()));

    player1Time = 0;
    player2Time = 0;
    CurrentPlayer = 0;
    gameTime = 0;
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::timeout()
{
    if(CurrentPlayer == 1)
    {
        player1Time--;

        if(player1Time <= 0)
        {
            player1Time = 0;
            pQTimer->stop();
            setGameInfoText("Player 2 WON!!", 20);
        }
    }

    if(CurrentPlayer == 2)
    {
        player2Time--;

        if(player2Time <= 0)
        {
            player2Time = 0;
            pQTimer->stop();
            setGameInfoText("Player 1 WON!!", 20);
        }
    }

    updateProgressBar();
}



void MainWindow::updateProgressBar()
{
    if(gameTime == 0)
        return;

    int p1percent = (player1Time * 100) / gameTime;
    int p2percent = (player2Time * 100) / gameTime;

    ui->Aika1->setValue(p1percent);
    ui->Aika2->setValue(p2percent);
}



void MainWindow::setGameInfoText(QString text, short size)
{
    ui->statusbar->showMessage(text);
}


void MainWindow::on_Sekuntikello_clicked()
{
    gameTime = 120;

    player1Time = gameTime;
    player2Time = gameTime;

    updateProgressBar();
    setGameInfoText("Ready to play", 18);
}


void MainWindow::on_Minuuttikello_clicked()
{
    gameTime = 300;

    player1Time = gameTime;
    player2Time = gameTime;

    updateProgressBar();
    setGameInfoText("Ready to play", 18);
}


void MainWindow::on_AloitaPeli1_clicked()
{
    if(gameTime == 0)
    {
        setGameInfoText("Select playtime first!", 18);
        return;
    }

    player1Time = gameTime;
    player2Time = gameTime;

    CurrentPlayer = 1;

    pQTimer->start(1000);

    setGameInfoText("Game ongoing", 18);
}




void MainWindow::on_AloitaPeli2_clicked()
{
    pQTimer->stop();
    CurrentPlayer = 0;

    setGameInfoText("Game stopped", 18);
}


void MainWindow::on_Pelaaja1_clicked()
{
    if(CurrentPlayer == 1)
        CurrentPlayer = 2;
}




void MainWindow::on_Pelaaja2_clicked()
{
    if(CurrentPlayer == 2)
        CurrentPlayer = 1;
}


