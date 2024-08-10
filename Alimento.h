#ifndef ALIMENTO_H
#define ALIMENTO_H


#include "producto.h"

class Alimento : public Producto {
    QString fechaCaducidad;

public:
    Alimento(const QString& nombre, double precio, int cantidad, const QString& fechaCaducidad)
        : Producto(nombre, precio, cantidad), fechaCaducidad(fechaCaducidad) {}

    QString getFechaCaducidad() const { return fechaCaducidad; }
    void setFechaCaducidad(const QString& fechaCaducidad) { this->fechaCaducidad = fechaCaducidad; }

    QString getInfo() const override {
        return QString("Alimento: %1, Fecha de Caducidad: %2, Precio: %3, Cantidad: %4")
        .arg(nombre).arg(fechaCaducidad).arg(precio).arg(cantidad);
    }
};

#endif // ALIMENTO_H
