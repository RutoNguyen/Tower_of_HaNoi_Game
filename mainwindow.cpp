#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "disc.h"
#include "column.h"
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Tạo GraphicsScene
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    setupGame();

    solveTimer = new QTimer(this);
    connect(solveTimer, &QTimer::timeout, this, &MainWindow::performNextMove);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setupGame(){
    // Xóa các đĩa cũ và giải phóng bộ nhớ
    QList<QGraphicsItem *> items = scene->items();
    for (QGraphicsItem *item : items) {
        if (item->type() == Disc::Type) { // Kiểm tra xem item có phải là Disc không
            scene->removeItem(item);
            delete item;
        } else if( item->type() == Column::Type){
            scene->removeItem(item);
            delete item;
        }
    }
    scene->clear();
    // Đặt kích thước cố định cho scene
    scene->setSceneRect(0, 0, 600, 220); // Cố định kích thước scene
    turn = 0;

    //
    //Khởi tạo trạng thái các cột
    for(int i = 0; i < 3; i++){
        towers[i] = std::stack<int>();
    }
    for(int i = count_Disc; i > 0; i--){
        towers[0].push(i); // ban đầu tất cả đĩa ở cột 0
    }
    //Vẽ các cột
    c1 = new Column();
    c2 = new Column();
    c3 = new Column();

    c1->setPos(60,0);
    c2->setPos(260,0);
    c3->setPos(460,0);

    scene->addItem(c1);
    scene->addItem(c2);
    scene->addItem(c3);

    qreal col1 = c1->pos().x();
    qreal col2 = c2->pos().x();
    spaceColumn = col2 - col1; // Khoảng cách giữa cột 1 và cột 2

    //Vẽ các đĩa
    int offset = 21;
    // Tính toán tọa độ x giữa cột 1
    qreal column1X = c1->pos().x() + c1->boundingRect().width() / 2;
    // Chiều cao của cột
    qreal columHeight = c1->boundingRect().height();
    int y = c1->pos().y() + columHeight - offset;
    //int y = (count_Disc - 1 )*offset;

    for(int i = 0; i < count_Disc ; i++){
        Disc *disc = new Disc(count_Disc - i); // Vẽ từ lớn đến nhỏ, từ nhỏ đến lớn lỗi vị trí khi xoá
        int x = column1X - disc->boundingRect().width() / 2;
        //int y = -i*offset;
        disc->setPos(x, y);
        disc->setData(0, "column1");
        scene->addItem(disc);
        y -= offset;
    }
    // Cập nhật giao diện
    ui->graphicsView->update();
    ui->lcd_turn->display(turn);
}
bool MainWindow::isValidMove(int from, int to){
    if(from == to) return false;

    if(towers[from].empty()) return false;

    if(towers[to].empty()) return true;

    return towers[from].top() < towers[to].top();

}
void MainWindow::moveDisc(Disc *disc, int from, int to){
    int offset = 21;
    qreal columnX = 0;
    qreal destColumnY = 0;
    qreal destColumnHeightY = 0;
    if(to == 0){
        columnX = c1->pos().x() + c1->boundingRect().width()/2;

        destColumnY = c1->pos().y();
        destColumnHeightY = c1->boundingRect().height();
    }else if(to == 1){
        columnX = c2->pos().x() + c2->boundingRect().width()/2;

        destColumnY = c2->pos().y();
        destColumnHeightY = c2->boundingRect().height();
    }else if(to == 2){
        columnX = c3->pos().x() + c3->boundingRect().width()/2;

        destColumnY = c3->pos().y();
        destColumnHeightY = c3->boundingRect().height();
    }
    int numDiscOnDescColumn = towers[to].size();
    qreal newY = destColumnY + destColumnHeightY - offset*(numDiscOnDescColumn+1);
    //qreal newY = (count_Disc - numDiscOnDescColumn -1) * offset;

    //
    disc->setPos(columnX - disc->boundingRect().width()/2, newY);
    disc->setData(0,QString("column%1").arg(to +1));

    towers[from].pop();
    towers[to].push(disc->getDiscNumber());

    turn ++;
    ui->lcd_turn->display(turn);
    if(checkWin()){
        QMessageBox::information(this, "Congratulations!", "You Win!");
    }
}
bool MainWindow::checkWin(){
    return towers[2].size() == count_Disc;
}
void MainWindow::on_pbtn_up_clicked()
{
    if(count_Disc<8){
        count_Disc++;
        ui->lcd_Disc->display(count_Disc);
        setupGame();
    }else{
        QMessageBox::information(this,"Notification","Disc limit reached!");
    }
}
void MainWindow::on_pbtn_down_clicked()
{
    if(count_Disc>3){
        count_Disc--;
        ui->lcd_Disc->display(count_Disc);
        setupGame();
    }else{
        QMessageBox::information(this,"Notification","Disc limit reached!");
    }
}
void MainWindow::on_pbtn_replay_clicked()
{
    //count_Disc = 3;
    //ui->lcd_Disc->display(count_Disc);
    setupGame();
}
void MainWindow::performNextMove() {
    if (moveQueue.isEmpty()) {
        solveTimer->stop(); // Dừng Timer khi hàng đợi rỗng
        //QMessageBox::information(this, "Congratulations!", "You Win!");
        return;
    }

    // Lấy bước tiếp theo từ hàng đợi
    QPair<int, int> move = moveQueue.dequeue();
    int from = move.first;
    int to = move.second;

    // Lấy đĩa từ cột nguồn
    Disc *disc = getDiscByNumber(towers[from].top());

    // Di chuyển đĩa (cập nhật giao diện và trạng thái)
    if (disc) {
        moveDisc(disc, from, to);
    }
}

void MainWindow::solveHaNoiTower(int n, int source, int dest, int aux){
    if (n <= 0) { return; }
    if(n == 1){
        //moveDisc(getDiscByNumber(n),source,dest);
        //ui->graphicsView->update();
        moveQueue.enqueue(qMakePair(source,dest));
        return;
    }
    solveHaNoiTower(n - 1, source, aux, dest);
    //moveDisc(getDiscByNumber(n), source, dest);
    //ui->graphicsView->update();
    moveQueue.enqueue(qMakePair(source,dest));
    solveHaNoiTower(n - 1, aux, dest, source);

}
Disc* MainWindow::getDiscByNumber(int number){
    for (int i = 0; i < 3; ++i) {
        if (!towers[i].empty() && towers[i].top() == number) { // Kiểm tra đĩa trên cùng
            // Tìm đĩa trong scene dựa trên số thứ tự và cột
            QList<QGraphicsItem *> items = scene->items();
            for (QGraphicsItem *item : items) {
                //if (item->type() == Disc::Type) {
                    Disc *disc = qgraphicsitem_cast<Disc *>(item);
                    if (disc->getDiscNumber() == number && disc->data(0).toString() == QString("column%1").arg(i + 1)) {
                        return disc;
                    }
                //}
            }
        }
    }
    return nullptr;

}
void MainWindow::on_pbtn_solve_clicked()
{
    moveQueue.clear(); // xoá hàng đợi
    setupGame();
    solveHaNoiTower(count_Disc, 0, 2, 1);
    solveTimer->start(1000);
}


void MainWindow::on_pbt_exit_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,
                                  "Exit confirmation",
                                  "Are you sure you want to exit?",
                                  QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }
}

