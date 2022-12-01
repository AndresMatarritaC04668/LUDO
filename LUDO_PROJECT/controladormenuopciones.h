/**
 * @file controladormenuopciones.h
 * @author Joseph Fernando Núñez Solano (C05582)
 * @brief Implementacion del controlador del menu de opciones.
 * @version 0.1
 * @date 2022-12-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CONTROLADORMENUOPCIONES_H
#define CONTROLADORMENUOPCIONES_H
#include "controlador_ventanas.h"

class MenuOpciones;

class ControladorMenuOpciones
{
public:
    /**
     * @brief Construct a new Controlador Menu Opciones object by arguments.
     * Iniciar y settear atributos.
     * 
     * @param controlador El controlador de ventadas.
     */
    ControladorMenuOpciones(controlador_Ventanas * controlador);

    /**
     * @brief Llama a iniciar el menu de opciones usando el atributo con ese
     * nombre.
     * 
     */
    void iniciar();

    /**
     * @brief Cierra la ventana segun la opcion seleccionada.
     * 
     * @param opcion Valor numerico que representa la opcion seleccionada.
     */
    void cerrarVentana(int opcion);

    /**
     * @brief Muestra las reglas usando el controlador de ventanas.
     * 
     */
    void mostrarReglas();

    /**
     * @brief Grafica las reglas en la interfaz usando una string que las
     * contiene.
     * 
     * @param reglas Contiene las reglas que se van a graficar.
     */
    void graficarReglas(string);

 private:
    MenuOpciones * menuOpciones;
    controlador_Ventanas * controlador;
};

#endif // CONTROLADORMENUOPCIONES_H
