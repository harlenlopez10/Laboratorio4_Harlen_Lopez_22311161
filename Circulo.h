#ifndef CIRCULO_H
#define CIRCULO_H

#include "figura.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>

class Circulo : public Figura {
    int radio;

public:
    Circulo(int radio, QColor color) : Figura(color), radio(radio) {}

    QRectF boundingRect() const override {
        return QRectF(-radio, -radio, 2 * radio, 2 * radio);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override {
        painter->setBrush(color);
        painter->drawEllipse(boundingRect());
    }

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override {
        if (isSelected()) {
            int nuevoRadio = std::sqrt(std::pow(event->pos().x(), 2) + std::pow(event->pos().y(), 2));
            radio = nuevoRadio > 10 ? nuevoRadio : 10;  // Limita el tamaño mínimo
            update();
        }
        Figura::mouseMoveEvent(event);
    }
};

#endif // CIRCULO_H
