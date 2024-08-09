#include "cframe.h"
#include "ui_cframe.h"
#include "Tarea.h"

#include <QCoreApplication>
#include <QApplication>

cframe::cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cframe)
{
    ui->setupUi(this);

    Negrita negrita;

    // Añadir el menú y la acción para negrita
    QMenu *formatMenu = menuBar()->addMenu(tr("Formato"));
    QAction *negritaAction = formatMenu->addAction(tr("Negrita"));

    connect(negritaAction, &QAction::triggered, [this, &negrita]() {
        QTextCursor cursor = ui->textEdit->textCursor();
        negrita.aplicar(cursor);
    });
}


cframe::~cframe()
{
    delete ui;
}

void cframe::on_btnAgregarTarea_clicked()
{
    QString titulo = ui->TituloTarea->text();
    QString descripcion = ui->DescripcionTarea->toPlainText();
    QDate fecha = ui->Fecha->date();
    QString tipo = ui->TipoTarea->currentText();

    Tarea* nuevaTarea = nullptr;
    if (tipo == "Diaria") {
        nuevaTarea = new TareaDiaria(titulo, descripcion, fecha);
    } else if (tipo == "Semanal") {
        nuevaTarea = new TareaSemanal(titulo, descripcion, fecha);
    }

    if (nuevaTarea) {
        QString detalles = nuevaTarea->obtenerTipo() + ": " + nuevaTarea->obtenerTitulo() +
                           " - " + nuevaTarea->obtenerDescripcion() + " (" + nuevaTarea->obtenerFecha().toString() + ")";
        ui->ListaTareas->addItem(detalles);
        nuevaTarea->mostrarDetalles();
    }
}


void cframe::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void cframe::on_BTNSALIR_clicked()
{
    QCoreApplication::quit();
}


void cframe::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void cframe::on_btnEjercicio2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void cframe::on_btnEjercicio3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void cframe::on_btnEjercicio2_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void cframe::on_pushButton_3_clicked()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    if (cursor.hasSelection()) {
        negrita.aplicar(cursor);
    } else {

        cursor.select(QTextCursor::Document);
        negrita.aplicar(cursor);
    }
}


void cframe::on_btnCursiva_clicked()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    if (cursor.hasSelection()) {
        cursiva.aplicar(cursor);
    } else {

        cursor.select(QTextCursor::Document);
        cursiva.aplicar(cursor);
    }
}



void cframe::on_btnSubrayado_clicked()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    if (cursor.hasSelection()) { // Verifica si hay texto seleccionado
        subrayado.aplicar(cursor);
    } else {
        // Si no hay texto seleccionado, podrías opcionalmente seleccionar todo el texto
        cursor.select(QTextCursor::Document);
        subrayado.aplicar(cursor);
    }
}


void cframe::on_btnAgg_clicked()
{
    QString nombre = nombreEdit->text();
    double precio = precioEdit->text().toDouble();
    int cantidad = cantidadEdit->text().toInt();
    QString extra = extraEdit->text();

    Producto *producto = nullptr;

    QString tipoSeleccionado = ui->comboBoxTipoProducto->currentText();

    if (tipoSeleccionado == "Electronico") {
        producto = new Electronico(nombre, precio, cantidad, extra);
    } else if (tipoSeleccionado == "Ropa") {
        producto = new Ropa(nombre, precio, cantidad, extra);
    } else if (tipoSeleccionado == "Alimento") {
        producto = new Alimento(nombre, precio, cantidad, extra);
    }

    if (producto) {
        productos.append(producto);
        actualizarLista();
    }
}


void cframe::on_btnDelete_clicked()
{
    int index = listaProductos->currentRow();
    if (index >= 0 && index < productos.size()) {
        delete productos.takeAt(index);
        actualizarLista();
    }
}


void cframe::on_btnMod_clicked()
{
    int index = listaProductos->currentRow();
    if (index >= 0 && index < productos.size()) {
        Producto *producto = productos[index];
        producto->setNombre(nombreEdit->text());
        producto->setPrecio(precioEdit->text().toDouble());
        producto->setCantidad(cantidadEdit->text().toInt());
        // Actualiza atributos específicos aquí
        actualizarLista();
    }
}

void cframe::actualizarLista() {
    listaProductos->clear();
    for (Producto *producto : productos) {
        listaProductos->addItem(producto->getNombre() + " (" + producto->tipo() + ")");
    }
}

