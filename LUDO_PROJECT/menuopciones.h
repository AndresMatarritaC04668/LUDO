#ifndef MENUOPCIONES_H
#define MENUOPCIONES_H
#include "controladormenuopciones.h"
#include <QMainWindow>

namespace Ui {
class MenuOpciones;
}

class MenuOpciones : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuOpciones(QWidget *parent = nullptr);
    ~MenuOpciones();
    void setControlador(ControladorMenuOpciones * controlador);
    Ui::MenuOpciones *ui;

private slots:
    void on_botonReglas_clicked();

    void on_botonRenaudar_clicked();

    void on_botonJugar_clicked();

private:

    ControladorMenuOpciones * controlador;


};

#endif // MENUOPCIONES_H
