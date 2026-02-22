#include "mainwindow.h"
#include "./ui_mainwindow.h"


void MainWindow::on_N0_clicked() { numberClickedHandler("0"); }
void MainWindow::on_N1_clicked() { numberClickedHandler("1"); }
void MainWindow::on_N2_clicked() { numberClickedHandler("2"); }
void MainWindow::on_N3_clicked() { numberClickedHandler("3"); }
void MainWindow::on_N4_clicked() { numberClickedHandler("4"); }
void MainWindow::on_N5_clicked() { numberClickedHandler("5"); }
void MainWindow::on_N6_clicked() { numberClickedHandler("6"); }
void MainWindow::on_N7_clicked() { numberClickedHandler("7"); }
void MainWindow::on_N8_clicked() { numberClickedHandler("8"); }
void MainWindow::on_N9_clicked() { numberClickedHandler("9"); }

void MainWindow::on_add_clicked() { addSubMulDivClickHandler(0); }
void MainWindow::on_sub_clicked() { addSubMulDivClickHandler(1); }
void MainWindow::on_mul_clicked() { addSubMulDivClickHandler(2); }
void MainWindow::on_div_clicked() { addSubMulDivClickHandler(3); }

void MainWindow::on_clear_clicked() { clearAndEnterClickHandler(false); }
void MainWindow::on_enter_clicked() { clearAndEnterClickHandler(true); }


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    state = 1;
    operand = -1;
    result = 0.0f;

    resetLineEdits();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::numberClickedHandler(const QString &digit)
{
    if (state == 1) {
        number1 += digit;
        ui->Num1->setText(number1);
    } else if (state == 2) {
        number2 += digit;
        ui->Num2->setText(number2);
    }
}


void MainWindow::addSubMulDivClickHandler(short op)
{
    operand = op;


    if (number1.isEmpty()) {
        return;
    }

    state = 2;
}


void MainWindow::clearAndEnterClickHandler(bool isEnter)
{
    if (!isEnter) {
        resetLineEdits();
        return;
    }
    if (number1.isEmpty() || number2.isEmpty() || operand < 0) {
        return;
    }

    float n1 = number1.toFloat();
    float n2 = number2.toFloat();
    float res = 0.0f;

    switch (operand) {
    case 0: res = n1 + n2; break;
    case 1: res = n1 - n2; break;
    case 2: res = n1 * n2; break;
    case 3:
        if (n2 == 0.0f) {
            ui->result->setText("Err"); // jako nollalla
            return;
        }
        res = n1 / n2;
        break;
    default:
        return;
    }

    result = res;
    ui->result->setText(QString::number(result));
}


void MainWindow::resetLineEdits()
{
    number1 = "";
    number2 = "";
    operand = -1;
    state = 1;
    result = 0.0f;

    ui->Num1->setText("");
    ui->Num2->setText("");
    ui->result->setText("");
}
