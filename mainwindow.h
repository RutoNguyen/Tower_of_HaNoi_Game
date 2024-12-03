#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "disc.h"
#include "column.h"
#include<QGraphicsScene>
#include<stack>
#include<QQueue>
#include<QPair>
#include<QTimer>

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
    //int count_Disc = 3;
    bool isValidMove(int from, int to);
    void moveDisc(Disc *disc, int from, int to);
    int spaceColumn; //Khoảng cách giữa các cột
    std::stack<int> towers[3]; // Mảng lưu trữ trạng thái các cột;
private slots:
    void on_pbtn_up_clicked();
    void on_pbtn_down_clicked();
    void on_pbtn_replay_clicked();
    void on_pbtn_solve_clicked();
    void performNextMove();

    void on_pbt_exit_clicked();

private:
    Ui::MainWindow *ui;
    int count_Disc = 3;
    int turn = 0;
    QGraphicsScene *scene;
    Column *c1, *c2, *c3;
    QQueue<QPair<int,int>> moveQueue;
    QTimer *solveTimer;

    void setupGame();
    bool checkWin();
    void solveHaNoiTower(int n, int source, int dest, int aux);
    Disc* getDiscByNumber(int Number);
};
#endif // MAINWINDOW_H
