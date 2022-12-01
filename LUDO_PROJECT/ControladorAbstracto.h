/**
 * @file ControladorAbstracto.h
 * @authors Esteban José Mora García (C05126),
 * José Andrés Matarrita Miranda (C04668), Joseph Fernando Núñez Solano (C05582)
 * @brief Controlador abstracto para los juegos del MARDA.
 * @version 0.1
 * @date 2022-12-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _CONTROLADOR_ABSTRACTO
#define _CONTROLADOR_ABSTRACTO

class ControladorAbstracto {

    public:
        /**
         * @brief Construct a new Controlador Abstracto object
         * 
         */
        ControladorAbstracto(){}

        /**
         * @brief Destroy the Controlador Abstracto object
         * 
         */
        virtual ~ControladorAbstracto(){}

        /**
         * @brief Crea el tablero de juego.
         * 
         */
        virtual void crearTablero() = 0;

        /**
         * @brief Solicita que se seleccione la cantidad de jugadores.
         * 
         */
        virtual void asignarCantidadJugadores() = 0;

        /**
         * @brief Llama a ubicar los jugadores, es decir, a que se construyan
         * y se guarden en el vector de jugadores.
         * 
         */
        virtual void ubicarJugadores() = 0;

        /**
         * @brief Llama a asignar el primer jugador.
         * 
         */
        virtual void asignarPrimerJugador() = 0;

        /**
         * @brief Inicia la partida usando el tablero.
         * 
         */
        virtual void iniciarPartida() = 0;

        /**
         * @brief Pausa la partida usando el tablero y el serializador.
         * 
         */
        virtual void pausarPartida() = 0;

        /**
         * @brief Reanuda la partida usando el tablero y el deserializador.
         * 
         */
        virtual void renaudarPartida() = 0;

};

#endif
