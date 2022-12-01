/**
 * @file controlador_ventanas.cpp
 * @author 
 * @brief Controla las ventanas del juego.
 * @version 0.1
 * @date 2022-12-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CONTROLADOR_VENTANAS_H
#define CONTROLADOR_VENTANAS_H

#include "ventanainformacion.h"
#include <string.h>
#include <TableroAbstracto.h>
#include <QLabel>
#include "ControladorLudo.h"

class ControladorMenuOpciones;
class ControladorVentanaPrincipal;
using namespace std;

class controlador_Ventanas
{
public:
    /**
     * @brief Construct a new controlador Ventanas::controlador Ventanas object by
     * arguments.
     * 
     * @param controlador el controlador del juego LUDO.
     */
    controlador_Ventanas(ControladorLudo * controlador);

    /**
     * @brief Empieza a graficar el tablero con el controlador de la ventana
     * principal.
     * 
     * @param mesa El tablero del juego.
     */
    void graficarTablero(TableroAbstracto*);

    /**
     * @brief Inicia las ventanas usando el controlador del menu de opciones.
     * 
     */
    void iniciar();

    /**
     * @brief Actualiza lo que muestra el tablero segun la opcion escogida por
     * el jugador.
     * 
     * @param opcion Variable numerica que representa la opcion del jugador.
     */
    void mostrarTablero(int);

    /**
     * @brief Cierra la ventana principal y muestra el menu de opciones.
     * 
     */
    void mostrarMenu();

    /**
     * @brief Usa el controlador de la ventana principal para graficar la carcel
     * del juego.
     * 
     * @param jugadores Los jugadores de la partida.
     */
    void graficarCarcel(vector<Jugador*> jugadores);

    /**
     * @brief Muestra la lista de reglas.
     * 
     */
    void mostrarReglas();

    /**
     * @brief Devuelve el nombre del jugador en relacion al numero que lo
     * representa.
     * 
     * @param numeroJugador el numero del jugador cuyo nombre se quiere obtener.
     * @return string el nombre del jugador.
     */
    string getNombre(string numeroJugador);

    /**
     * @brief Pide el nombre de la partida para usarlo en los savestates.
     * 
     * @return string Nombre de la partida.
     */
    string getNombreCSV();

    /**
     * @brief Pide que se elija el numero de ficha que se quiere mover. En
     * realidad, se tiene que digitar un numero de 1 al numero de fichas
     * disponibles.
     * 
     * @param mensaje Se le envia al usuario para que elija una ficha.
     * @return int El numero de ficha seleccionada.
     */
    int elegirFicha(string);

    /**
     * @brief Pide que el jugador escoja que hacer en su turno. Puede elegir
     * continuar con la jugada o salir y guardar la partida.
     * 
     * @param nombre del jugador. 
     * @return int La eleccion del jugador representada por un valor numerico.
     */
    int eleccionJugador(string turno);
    ventanaInformacion * input;

    /**
     * @brief Muestra un mensaje grafico por medio de la interfaz.
     * 
     * @param mensaje El mensaje a mostrar
     */
    void mensajeGrafico(string);

private:
  ControladorMenuOpciones * controladorMenuOpciones;
  ControladorVentanaPrincipal * controladorVentanaPrincipal;
  ControladorLudo * controladorLudo;
};

#endif // CONTROLADOR_VENTANAS_H
