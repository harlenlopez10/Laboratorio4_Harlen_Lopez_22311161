#ifndef ALIMENTO_H
#define ALIMENTO_H


#include "producto.h"

class Alimento : public Producto {
public:
    Alimento(const QString &nombre, double precio, int cantidad, const QString &fechaExpiracion)
        : Producto(nombre, precio, cantidad), fechaExpiracion(fechaExpiracion) {}

    QString tipo() const override { return "Alimento"; }

    QString getFechaExpiracion() const { return fechaExpiracion; }
    void setFechaExpiracion(const QString &fechaExpiracion) { this->fechaExpiracion = fechaExpiracion; }

private:
    QString fechaExpiracion;
};

#endif // ALIMENTO_H
