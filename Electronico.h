#ifndef ELECTRONICO_H
#define ELECTRONICO_H

#include "Producto.h"

class Electronico : public Producto {
public:
    Electronico(const QString &nombre, double precio, int cantidad, const QString &marca)
        : Producto(nombre, precio, cantidad), marca(marca) {}

    QString tipo() const override { return "Electrónico"; }

    QString getMarca() const { return marca; }
    void setMarca(const QString &marca) { this->marca = marca; }

private:
    QString marca;
};

#endif // ELECTRONICO_H
