#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_count_clicked()
{
    int value = ui->Laskuri->text().toInt();
    value++;
    ui->Laskuri->setText(QString::number(value));
}



void MainWindow::on_reset_clicked()
{
    ui->Laskuri->setText("0");
}
