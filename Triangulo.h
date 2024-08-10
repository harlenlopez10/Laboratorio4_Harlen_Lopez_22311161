#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Figura.h"
#include <QPolygonF>
#include <QGraphicsSceneMouseEvent>

class Triangulo : public Figura {
    QPolygonF triangulo;

public:
    Triangulo(int base, int altura, QColor color) : Figura(color) {
        triangulo << QPointF(0, 0) << QPointF(base, 0) << QPointF(base / 2, altura);
    }

    QRectF boundingRect() const override {
        return triangulo.boundingRect();
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override {
        painter->setBrush(color);
        painter->drawPolygon(triangulo);
    }

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override {
        if (isSelected()) {
            int nuevaBase = event->pos().x();
            int nuevaAltura = event->pos().y();
            triangulo[1] = QPointF(nuevaBase, 0);
            triangulo[2] = QPointF(nuevaBase / 2, nuevaAltura);
            update();
        }
        Figura::mouseMoveEvent(event);
    }
};
#endif // TRIANGULO_H
