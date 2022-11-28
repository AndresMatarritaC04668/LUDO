/**
 * @file ventanaprincipal.h
 * @author Joseph Fernando Núñez Solano (C05582)
 * @brief Implementacion de la ventana principal del MARDA en QT.
 * @version 0.1
 * @date 2022-11-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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
    /**
     * @brief Construct a new Ventana Principal object by parameters
     * 
     * @param parent Widget padre de la ventana principal.
     */
    VentanaPrincipal(QWidget *parent = nullptr);

    /**
     * @brief Set the controlador object
     * 
     * @param controlador Un puntero a un puntero ControladorVentanaPrincipal,
     * se guarda en el atributo controlador.
     */
    void setControlador(ControladorVentanaPrincipal * controlador);

    /**
     * @brief Destroy the Ventana Principal object
     * 
     */
    ~VentanaPrincipal();
    Ui::VentanaPrincipal *ui;

private:
    ControladorVentanaPrincipal * controlador;

};
#endif // VENTANAPRINCIPAL_H
