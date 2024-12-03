#ifndef COLUMN_CPP
#define COLUMN_CPP
#include "column.h"
#include<QPainter>

Column::Column(){
}

QRectF Column::boundingRect() const{
    // Cột rộng 30, cao 200
    return QRectF(0, 0, 30, 200);
}

void Column::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget) {
    //painter->fillRect(boundingRect(),QBrush(QColor(0,255,0)));
    painter->fillRect(boundingRect(),Qt::blue);
}
#endif // COLUMN_CPP
