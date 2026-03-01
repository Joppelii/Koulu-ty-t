#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    public slots:

        void timeout();


private:

    short player1Time;
    short player2Time;
    short CurrentPlayer;
    short gameTime;

    QTimer* pQTimer;

    void updateProgressBar();
    void setGameInfoText(QString, short);

    Ui::MainWindow *ui;


private slots:
    void on_Sekuntikello_clicked();
    void on_Minuuttikello_clicked();
    void on_AloitaPeli1_clicked();
    void on_AloitaPeli2_clicked();
    void on_Pelaaja1_clicked();
    void on_Pelaaja2_clicked();
};
#endif // MAINWINDOW_H
