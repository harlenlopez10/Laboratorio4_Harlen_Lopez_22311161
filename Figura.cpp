#include "Figura.h"
#include <QGraphicsSceneMouseEvent>

void Figura::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton && isSelected()) {
        setCursor(Qt::SizeAllCursor);
    }
    QGraphicsItem::mousePressEvent(event);
}

void Figura::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mouseMoveEvent(event);
}

void Figura::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    setCursor(Qt::ArrowCursor);
    QGraphicsItem::mouseReleaseEvent(event);
}
