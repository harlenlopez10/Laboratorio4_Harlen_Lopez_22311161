#ifndef TAREA_H
#define TAREA_H

#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QDateEdit>
#include <QComboBox>
#include <QPushButton>
#include <QListWidget>
#include <QMessageBox>
#include <QString>
#include <QDate>

// Clase base: Tarea
class Tarea {
protected:
    QString titulo;
    QString descripcion;
    QDate fecha;

public:
    Tarea(const QString& titulo, const QString& descripcion, const QDate& fecha)
        : titulo(titulo), descripcion(descripcion), fecha(fecha) {}

    virtual ~Tarea() {}

    virtual QString obtenerTipo() const = 0;
    QString obtenerTitulo() const { return titulo; }
    QString obtenerDescripcion() const { return descripcion; }
    QDate obtenerFecha() const { return fecha; }

    virtual void mostrarDetalles() const = 0;
};

// Clase derivada: TareaDiaria
class TareaDiaria : public Tarea {
public:
    TareaDiaria(const QString& titulo, const QString& descripcion, const QDate& fecha)
        : Tarea(titulo, descripcion, fecha) {}

    QString obtenerTipo() const override {
        return "Diaria";
    }

    void mostrarDetalles() const override {
        QString detalles = "Tarea Diaria:\n";
        detalles += "Título: " + obtenerTitulo() + "\n";
        detalles += "Descripción: " + obtenerDescripcion() + "\n";
        detalles += "Fecha: " + obtenerFecha().toString() + "\n";

        QMessageBox::information(nullptr, "Detalles de Tarea Diaria", detalles);
    }
};

// Clase derivada: TareaSemanal
class TareaSemanal : public Tarea {
public:
    TareaSemanal(const QString& titulo, const QString& descripcion, const QDate& fecha)
        : Tarea(titulo, descripcion, fecha) {}

    QString obtenerTipo() const override {
        return "Semanal";
    }

    void mostrarDetalles() const override {
        QString detalles = "Tarea Semanal:\n";
        detalles += "Título: " + obtenerTitulo() + "\n";
        detalles += "Descripción: " + obtenerDescripcion() + "\n";
        detalles += "Fecha: " + obtenerFecha().toString() + "\n";

        QMessageBox::information(nullptr, "Detalles de Tarea Semanal", detalles);
    }
};

#endif // TAREA_H
