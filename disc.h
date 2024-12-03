#ifndef DISC_H
#define DISC_H

#include <QGraphicsItem>

class Disc : public QGraphicsItem

{
//Q_OBJECT
public :
    Disc(int discNumber);
    int getDiscNumber() const;
    QRectF boundingRect() const override;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
protected :
    //lưu thông tin đĩa được chọn khi nhấp chuột
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    //Di chuyển đĩa theo chuột khi kéo
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    //Xử lý khi thả chuột
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
private :
    int m_discNumber;
    QPointF initialpos;
    Disc *selectedDisc = nullptr;
};
#endif // DISC_H
