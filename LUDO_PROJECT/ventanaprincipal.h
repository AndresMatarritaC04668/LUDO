#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include "controladorventanaprincipal.h"

QT_BEGIN_NAMESPACE
namespace Ui { class VentanaPrincipal; }
QT_END_NAMESPACE

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    VentanaPrincipal(QWidget *parent = nullptr);
    void setControlador(ControladorVentanaPrincipal * controlador);
    ~VentanaPrincipal();
    Ui::VentanaPrincipal *ui;

private:
    ControladorVentanaPrincipal * controlador;

};
#endif // VENTANAPRINCIPAL_H
