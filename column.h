#ifndef COLUMN_H
#define COLUMN_H

#include <QGraphicsItem>

class Column : public QGraphicsItem{
public:
    Column();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
};

#endif // COLUMN_H
