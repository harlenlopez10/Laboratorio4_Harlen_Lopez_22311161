#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <QString>

class Producto {
public:
    Producto(const QString &nombre, double precio, int cantidad)
        : nombre(nombre), precio(precio), cantidad(cantidad) {}

    virtual ~Producto() = default;

    virtual QString tipo() const = 0;

    QString getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }

    void setNombre(const QString &nombre) { this->nombre = nombre; }
    void setPrecio(double precio) { this->precio = precio; }
    void setCantidad(int cantidad) { this->cantidad = cantidad; }

private:
    QString nombre;
    double precio;
    int cantidad;
};

#endif // PRODUCTO_H
