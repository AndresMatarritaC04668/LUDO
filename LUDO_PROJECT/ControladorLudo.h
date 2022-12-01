/**
 * @file ControladorLudo.h
 * @authors Esteban José Mora García (C05126),
 * José Andrés Matarrita Miranda (C04668), Joseph Fernando Núñez Solano (C05582)
 * @brief Implementacion del controlador para el juego LUDO.
 * @version 0.1
 * @date 2022-12-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _CONTROLADOR_LUDO
#define _CONTROLADOR_LUDO

#include "ControladorAbstracto.h"

class controlador_Ventanas;
class TableroLudo;

class ControladorLudo : public ControladorAbstracto {

    public:
        /**
         * @brief Construct a new Controlador Ludo object
         * 
         */
        ControladorLudo();

        /**
         * @brief Llama a crear el tablero para el juego LUDO. Le asigna el
         * controlador grafico.
         * 
         */
        void crearTablero() override;

        /**
         * @brief Llama al tablero a asignar la cantidad de jugadores segun la
         * cantidad introducida por el jugador por medio de la interfaz.
         * 
         */
        void asignarCantidadJugadores() override;
        
        /**
         * @brief Llama a que el tablero ubique a los jugadores. Es decir a que
         * se construyan y se guarden en el vector de jugadores.
         * 
         */
        void ubicarJugadores() override;

        /**
         * @brief Llama a asignar el primer jugador con el tablero. 
         * 
         */
        void asignarPrimerJugador() override;

        /**
         * @brief Inicia la partida usando el tablero.
         * 
         */
        void iniciarPartida()override;

        /**
         * @brief Pausa la partida usando el tablero y el serializador.
         * 
         */
        void pausarPartida()override;

        /**
         * @brief Reanuda la partida usando el tablero y el deserializador.
         * 
         */
        void renaudarPartida()override;

    private:
        TableroLudo * tablero;
        controlador_Ventanas * controladorGrafico;


};

#endif
