#include "disc.h"
#include "mainwindow.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

Disc::Disc(int discNumber) : m_discNumber(discNumber){
    setFlag(QGraphicsItem::ItemIsMovable);// Cho phép di chuyển
}
int Disc::getDiscNumber() const{
    return m_discNumber;
}

QRectF Disc::boundingRect() const{
    // Trả về hình chữ nhật bao quanh đĩa QRectF(x,y,width,height)
    int discWidth = 50 + 10 * m_discNumber; // Chiều rộng đĩa
    return QRectF(0,0,discWidth,20); //đĩa cao 20
}

void Disc::paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->fillRect(boundingRect(),Qt::red);
}

void Disc::mousePressEvent(QGraphicsSceneMouseEvent *event){
    //Lấy MainWindow
    MainWindow *mainWindow = qobject_cast<MainWindow *>(scene()->parent());
    //Xác định cột hiện tại của đĩa
    int sourceColumn = data(0).toString().remove("column").toInt() -1 ;
    //Kiểm tra đĩa có phải là đĩa trên cùng không
    if(mainWindow->towers[sourceColumn].top() != m_discNumber){
        return;
    }
    selectedDisc = this;
    initialpos = pos();
}
void Disc::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if(selectedDisc == this){
        setPos(event->scenePos() - QPointF(boundingRect().width()/2,
                                           boundingRect().height()/2));
    }
}
void Disc::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    if(selectedDisc == this){
        selectedDisc = nullptr;
        //Lấy mainwindow
        MainWindow *mainWindow = qobject_cast<MainWindow *>(scene()->parent())  ;
        //Xác định cột đích dựa trên toạ độ x
        int destColumn = int(pos().x() / mainWindow->spaceColumn); // Sử dụng columnSpacing
        //int destColumn = int(pos().x()) / 200;
        int sourceColumn = data(0).toString().remove("column").toInt()-1;

        if(mainWindow->isValidMove(sourceColumn, destColumn)){
            mainWindow->moveDisc(this, sourceColumn, destColumn);
        } else{
            setPos(initialpos);
        }
    }
}


