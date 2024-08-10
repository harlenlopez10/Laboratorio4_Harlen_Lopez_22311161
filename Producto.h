#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <QString>

class Producto {
protected:
    QString nombre;
    double precio;
    int cantidad;

public:
    Producto(const QString& nombre, double precio, int cantidad)
        : nombre(nombre), precio(precio), cantidad(cantidad) {}

    virtual ~Producto() {}

    QString getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }

    void setNombre(const QString& nombre) { this->nombre = nombre; }
    void setPrecio(double precio) { this->precio = precio; }
    void setCantidad(int cantidad) { this->cantidad = cantidad; }

    virtual QString getInfo() const = 0;
};

#endif // PRODUCTO_H
