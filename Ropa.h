#ifndef ROPA_H
#define ROPA_H

#include "Producto.h"

class Ropa : public Producto {
    QString talla;

public:
    Ropa(const QString& nombre, double precio, int cantidad, const QString& talla)
        : Producto(nombre, precio, cantidad), talla(talla) {}

    QString getTalla() const { return talla; }
    void setTalla(const QString& talla) { this->talla = talla; }

    QString getInfo() const override {
        return QString("Ropa: %1, Talla: %2, Precio: %3, Cantidad: %4")
        .arg(nombre).arg(talla).arg(precio).arg(cantidad);
    }
};

#endif // ROPA_H
