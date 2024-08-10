#ifndef FIGURA_H
#define FIGURA_H

#include <QGraphicsItem>
#include <QPainter>
#include <QCursor>

class Figura : public QGraphicsItem {
protected:
    QColor color;

public:
    Figura(QColor color) : color(color) {
        setFlag(QGraphicsItem::ItemIsMovable);  // Permitir mover la figura
        setFlag(QGraphicsItem::ItemIsSelectable);  // Permitir seleccionar la figura
        setFlag(QGraphicsItem::ItemSendsGeometryChanges);  // Notificar cambios en la geometría
    }

    virtual ~Figura() {}

    void setColor(QColor nuevoColor) {
        color = nuevoColor;
        update();  // Actualiza la visualización del elemento
    }

    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override {
        if (change == QGraphicsItem::ItemSelectedChange && scene()) {
            if (value.toBool()) {
                // Si el item es seleccionado, cambiar el cursor
                setCursor(Qt::SizeAllCursor);
            } else {
                setCursor(Qt::ArrowCursor);
            }
        }
        return QGraphicsItem::itemChange(change, value);
    }

    // Métodos virtuales puros para ser implementados en las clases derivadas
    virtual QRectF boundingRect() const = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) = 0;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // FIGURA_H
