#ifndef ROPA_H
#define ROPA_H

#include "Producto.h"

class Ropa : public Producto {
public:
    Ropa(const QString &nombre, double precio, int cantidad, const QString &tamaño)
        : Producto(nombre, precio, cantidad), tamaño(tamaño) {}

    QString tipo() const override { return "Ropa"; }

    QString getTamaño() const { return tamaño; }
    void setTamaño(const QString &tamaño) { this->tamaño = tamaño; }

private:
    QString tamaño;
};

#endif // ROPA_H
