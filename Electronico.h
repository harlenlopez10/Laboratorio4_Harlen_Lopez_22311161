#ifndef ELECTRONICO_H
#define ELECTRONICO_H

#include "Producto.h"

class Electronico : public Producto {
    QString marca;

public:
    Electronico(const QString& nombre, double precio, int cantidad, const QString& marca)
        : Producto(nombre, precio, cantidad), marca(marca) {}

    QString getMarca() const { return marca; }
    void setMarca(const QString& marca) { this->marca = marca; }

    QString getInfo() const override {
        return QString("Electrónico: %1, Marca: %2, Precio: %3, Cantidad: %4")
            .arg(nombre).arg(marca).arg(precio).arg(cantidad);
    }
};

#endif // ELECTRONICO_H
