/**
 * @file JugadorLudo.h
 * @authors Esteban José Mora García (C05126),
 * José Andrés Matarrita Miranda (C04668), Joseph Fernando Núñez Solano (C05582)
 * @brief Implementacion del jugador para el juego de LUDO.
 * @version 0.1
 * @date 2022-11-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _JUGADOR_LUDO
#define _JUGADOR_LUDO
#include<iostream>
#include "Jugador.h"
#include "tableroLUDO.h"
#include "TableroAbstracto.h"
#include "ValidadorLudo.h"
using namespace std;

class JugadorLudo : public Jugador {



    public :
        /**
         * @brief Construct a new Jugador Ludo object by arguments.
         * 
         * @param color El color del jugador.
         * @param zonaSegura La zona segura del jugador en el tablero.
         * @param nombre El nombre del jugador. Todo lo anterior se guarda en
         * los atributos.
         */
        JugadorLudo(string color,int zonaSegura,string nombre);

        /**
         * @brief Construct a new Jugador Ludo object
         * 
         */
        JugadorLudo();

        /**
         * @brief Destroy the Jugador Ludo object
         * 
         */
        ~JugadorLudo()override;



        
        /**
         * El jugador ejecuta la opcion de mover la ficha para el juego LUDO.
         * 
         * @param ficha La ficha que se va a mover.
         * @param pasos Los pasos que se va a mover la ficha.
         * @param tablero El tablero en el que se va a mover la ficha.
         * @return int Indica si el jugador tiene la opcion de volver a jugar su
         * turno.
         */
        int moverFicha(FichaAbstracta * ficha, int pasos, TableroAbstracto* tablero) override;    
        

        /**
         * @brief El jugador elige la ficha que va a mover
         * 
         * @param TableroAbstracto* El tablero en el que se va a mover.
         * @param int los pasos que se va a mover.
         * @return FichaAbstracta* Debe devolver la ficha elegida.
         */
        FichaAbstracta * elegirFicha(TableroAbstracto*,int)override;

        /**
         * @brief Busca las barreras en el tablero implementadas para el juego
         * LUDO que podrian obstaculizar el movimiento de una ficha.
         * 
         * @param posicion La posicion a la que la ficha se va a mover.
         * @param mover La ficha que se va a mover.
         * @param tablero El tablero en el que se esta jugando.
         * @return int 0 si no hay una barrera en el camino, 1 si la hay.
         */
        int encontrarBarrera(int posicion, FichaLudo * mover, TableroLudo* tablero);
        
 

  

        /**
         * @brief Determina como sera el movimiento de una ficha en la recta
         * final para el juego LUDO. El jugador necesita obtener la cantidad
         * exacta llegar al final, no puede obtener mas.
         * 
         * @param ficha La ficha que se encuentra en la recta final.
         * @param pasos Los pasos que se puede mover la ficha.
         * @param tablero El tablero en el que se esta jugando.
         * @param validador Para determinar la validez del movimiento.
         */
        void moverFichaRectaFinal(FichaLudo * ficha, int pasos, TableroLudo* tablero , ValidadorLudo * validador);


        /**
         * @brief El jugador escoge que hacer en relacion a las reglas de juego
         * LUDO.
         * 
         * @param tablero El tablero en el que se esta jugando el juego. 
         * @return int La eleccion del jugador, representada siempre por un
         * valor entero.
         */
        int elegirQueHacer(TableroAbstracto* tablero)override;
  
};

#endif
