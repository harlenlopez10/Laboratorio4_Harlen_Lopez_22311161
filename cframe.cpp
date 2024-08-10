#include "cframe.h"
#include "ui_cframe.h"
#include "Tarea.h"

#include "Electronico.h"
#include "Ropa.h"
#include "Alimento.h"

#include <QCoreApplication>
#include <QApplication>

cframe::cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cframe)
    , scene(new QGraphicsScene(this))
{
    ui->setupUi(this);

    // Configurar la escena
    setupScene();

    // Añadir figuras
    addFigures();

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

    for (Producto* producto : inventario) {
        delete producto;
    }
}


void cframe::setupScene() {
    // Configurar la vista para usar la escena
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);  // Mejor calidad de renderizado
}

void cframe::addFigures() {
    // Crear y añadir un rectángulo
    Rectangulo *rect = new Rectangulo(100, 50, Qt::blue);
    rect->setPos(0, 0);
    scene->addItem(rect);

    // Crear y añadir un círculo
    Circulo *ellipse = new Circulo(25, Qt::green);
    ellipse->setPos(150, 25);  // Centramos el círculo
    scene->addItem(ellipse);

    // Crear y añadir un triángulo
    Triangulo *triangle = new Triangulo(100, 86.6, Qt::red);  // Base y altura
    triangle->setPos(250, 50);  // Posicionarlo
    scene->addItem(triangle);
}

//EJERCICIO 1
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
//FIN EJERCICIO 1

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

//EJERCICIO 3
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
    if (cursor.hasSelection()) {
        subrayado.aplicar(cursor);
    } else {

        cursor.select(QTextCursor::Document);
        subrayado.aplicar(cursor);
    }
}

//FIN EJERCICIO 3


//EJERCICIO 4
void cframe::on_btnAgg_clicked()
{
    QString nombre = ui->nombreEdit->text();
    double precio = ui->SBprecioEdit->value();
    int cantidad = ui->spinBoxCantidad->value();

    if (ui->comboBoxTipoProducto->currentText() == "Electronico") {
        QString marca = ui->lineEditMarca->text();
        inventario.append(new Electronico(nombre, precio, cantidad, marca));
    } else if (ui->comboBoxTipoProducto->currentText() == "Ropa") {
        QString talla = ui->lineEditTalla->text();
        inventario.append(new Ropa(nombre, precio, cantidad, talla));
    } else if (ui->comboBoxTipoProducto->currentText() == "Alimento") {
        QString fechaCaducidad = ui->dateCaducidadEdit->text();
        inventario.append(new Alimento(nombre, precio, cantidad, fechaCaducidad));
    }

    actualizarLista();

}


void cframe::on_btnDelete_clicked()
{
    int index = ui->listWidget->currentRow();
    if (index != -1) {
        delete inventario[index];
        inventario.removeAt(index);
        actualizarLista();
    }
}


void cframe::on_btnMod_clicked()
{
    int index = ui->listWidget->currentRow();
    if (index != -1) {
        Producto* producto = inventario[index];
        producto->setNombre(ui->nombreEdit->text());
        producto->setPrecio(ui->SBprecioEdit->text().toDouble());
        producto->setCantidad(ui->spinBoxCantidad->value());


        if (Electronico* electronico = dynamic_cast<Electronico*>(producto)) {
            electronico->setMarca(ui->lineEditMarca->text());
        } else if (Ropa* ropa = dynamic_cast<Ropa*>(producto)) {
            ropa->setTalla(ui->lineEditTalla->text());
        } else if (Alimento* alimento = dynamic_cast<Alimento*>(producto)) {
            alimento->setFechaCaducidad(ui->dateCaducidadEdit->text());
        }

        actualizarLista();
    }
}

void cframe::actualizarLista() {
    ui->listWidget->clear();
    for (const Producto* producto : inventario) {
        ui->listWidget->addItem(producto->getInfo());
    }
}
//FIN EJERCICIO 4

