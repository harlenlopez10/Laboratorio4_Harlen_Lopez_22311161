#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Figura.h"
#include <QGraphicsSceneMouseEvent>

class Rectangulo : public Figura {
    int ancho, alto;

public:
    Rectangulo(int ancho, int alto, QColor color) : Figura(color), ancho(ancho), alto(alto) {}

    QRectF boundingRect() const override {
        return QRectF(0, 0, ancho, alto);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override {
        painter->setBrush(color);
        painter->drawRect(boundingRect());
    }

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override {
        if (isSelected()) {
            int nuevoAncho = event->pos().x();
            int nuevoAlto = event->pos().y();
            ancho = nuevoAncho > 10 ? nuevoAncho : 10;  // Limita el tamaño mínimo
            alto = nuevoAlto > 10 ? nuevoAlto : 10;
            update();
        }
        Figura::mouseMoveEvent(event);
    }
};

#endif // RECTANGULO_H
