#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>
#include <QTextEdit>
#include <QAction>
#include <QMenuBar>
#include <QVBoxLayout>

#include <QListWidget>
#include <QLineEdit>

#include <QListWidget>
#include "Electronico.h"
#include "Ropa.h"
#include "Alimento.h"

#include <QVector>

#include "ComandoCursiva.h"
#include "ComandoNegrita.h"
#include "ComandoSubrayado.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include "Circulo.h"
#include "Rectangulo.h"
#include "Triangulo.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class cframe;
}
QT_END_NAMESPACE

class cframe : public QMainWindow
{
    Q_OBJECT

public:
    cframe(QWidget *parent = nullptr);
    ~cframe();

private slots:
    void on_btnAgregarTarea_clicked();

    void on_pushButton_clicked();

    void on_BTNSALIR_clicked();

    void on_pushButton_2_clicked();

    void on_btnEjercicio2_clicked();

    void on_btnEjercicio3_clicked();

    void on_btnEjercicio2_2_clicked();

    void on_pushButton_3_clicked();

    void on_btnCursiva_clicked();

    void on_btnSubrayado_clicked();

    void on_btnAgg_clicked();

    void on_btnDelete_clicked();

    void on_btnMod_clicked();

private:
    void actualizarLista();
     QVector<Producto*> inventario;
    Ui::cframe *ui;

    QTextEdit *textEdit;
    Negrita negrita;
    Cursiva cursiva;
    Subrayado subrayado;

    QListWidget *listaProductos;
    QLineEdit *nombreEdit;
    QLineEdit *precioEdit;
    QLineEdit *cantidadEdit;
    QLineEdit *extraEdit;

    QGraphicsScene *scene;

    void setupScene();
    void addFigures();


};
#endif // CFRAME_H
