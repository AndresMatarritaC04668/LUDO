/**
 * @file menuopciones.h
 * @author Joseph Fernando Núñez Solano (C05582)
 * @brief Clase que implementa un menu de opciones en QT.
 * @version 0.1
 * @date 2022-11-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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
    /**
     * @brief Construct a new Menu Opciones object by arguments.
     * 
     * @param parent El widget padre del Menu.
     */
    explicit MenuOpciones(QWidget *parent = nullptr);

    /**
     * @brief Destroy the Menu Opciones object
     * 
     */
    ~MenuOpciones();

    /**
     * @brief Set the controlador object.
     * 
     * @param controlador un puntero a objeto ControladorMenuOpciones.
     */
    void setControlador(ControladorMenuOpciones * controlador);
    Ui::MenuOpciones *ui;

private slots:
    /**
     * @brief Llama a mostrar las reglas al clicker en el boton de reglas.
     * 
     */
    void on_botonReglas_clicked();

    /**
     * @brief Llama a reanudar la partida al clickear el boton de reanudar.
     * 
     */
    void on_botonRenaudar_clicked();

    /**
     * @brief Llama a jugar el juego al clickear el boton de jugar.
     * 
     */
    void on_botonJugar_clicked();

private:

    ControladorMenuOpciones * controlador;


};

#endif // MENUOPCIONES_H
