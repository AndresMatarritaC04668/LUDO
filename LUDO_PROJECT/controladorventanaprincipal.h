/**
 * @file controladorventanaprincipal.h
 * @author Joseph Fernando Núñez Solano (C05582)
 * @brief Controlador de la ventana principal del juego.
 * @version 0.1
 * @date 2022-12-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CONTROLADORVENTANAPRINCIPAL_H
#define CONTROLADORVENTANAPRINCIPAL_H

#include "controlador_ventanas.h"

class VentanaPrincipal;

class ControladorVentanaPrincipal
{
public:
    /**
     * @brief Construct a new Controlador Ventana Principal object by arguments.
     * 
     * @param controlador Controlador de ventanas se asigna al atributo
     * controlador.
     */
    ControladorVentanaPrincipal(controlador_Ventanas * controlador);

    /**
     * @brief Inicia el controlador. Inicia y settea los atributos. A ventana
     * principal se le debe pasar el mismo controlador como argumento en el
     * constructor.
     * 
     */
    void iniciar();

    /**
     * @brief Cierra y elimina la ventana principal.
     * 
     */
    void cerrarVentana();

    /**
     * @brief Grafica el tablero usando la matriz de fichas que lo representa.
     * 
     * @param mesa Es el tablero del juego, de aqui se saca la matriz del
     * tablero.
     */
    void graficarTablero(TableroAbstracto*);
    
    /**
     * @brief Grafica la carcel del juego, colocando a las fichas de los
     * jugadores de estar aun ahí.
     * 
     * @param jugadores El vector que guarda a los jugadores de la partida. Se
     * extraen las fichas de cada jugador para graficar. 
     */
    void graficarCarcel(vector<Jugador*> jugadores );

    /**
     * @brief Grafica la linea final de las fichas de un jugador en el juego.
     * 
     * @param mesa La mesa de juego, de aqui se extrae el jugador actual, y de
     * ahí, las fichas del jugador. La linea final se grafica si una o mas de
     * las fichas tienen una cantidad de pasos dados suficientes para entrar a
     * esta recta (mayor o igual a 55).
     */
    void graficarLineaFinal(TableroAbstracto*);
    
    /**
     * @brief Grafica las celdas del tablero segun el color que se quiere
     * empezar a graficar.
     * 
     * @param label Se usa el metodo setStyleSheet para guardar el color.
     * @param color El color que se quiere empezar a graficar, el codigo hara
     * procesos ligeramente diferentes dependiendo de su contenido.
     * @param numero string de caracteres unicode para QT, en realidad contiene
     * un numero.
     */
    void graficarCeldas(QLabel * , string color , QString numero);

private:
    controlador_Ventanas * controlador;
    VentanaPrincipal * ventanaPrincipal;
};

#endif // CONTROLADORVENTANAPRINCIPAL_H
