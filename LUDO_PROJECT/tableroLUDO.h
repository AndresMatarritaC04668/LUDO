/**
 * @file TableroLUDO.h
 * @authors Esteban José Mora García (C05126),
 * José Andrés Matarrita Miranda (C04668), Joseph Fernando Núñez Solano (C05582)
 * @brief Clase que implementa el tablero para el juego LUDO.
 * @version 0.1
 * @date 2022-11-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MI_TABLEROLUDO
#define MI_TABLEROLUDO
#include <string.h>
#include <iostream>
#include "TableroAbstracto.h"
#include "controlador_ventanas.h"
#include "FichaLudo.h"
using namespace std;


class TableroLudo : public TableroAbstracto {
   public:
      /**
       * @brief Construct a new Tablero Ludo object
       * 
       */
	TableroLudo();

      /**
       * @brief Destroy the Tablero Ludo object
       * 
       */
      ~TableroLudo()override;

      /**
       * @brief Crea y coloca a los jugadores en el tablero de juego por medio de
       * la interfaz.
       * 
       */
	void ubicarJugadores()override; // Fichas enel vector zona segurado

   
      
      /**
       * @brief Un jugador ejecuta su turno tirando el dado y moviendo las fichas.
       * 
       * @return int 
       */
      int jugarTurno()override;

      /**
       * @brief Ejecuta un mecanismo para determinar cual jugador va primero.
       * 
       */
      void asignarPrimerJugador()override;

      /**
       * @brief Pasa a string el contenido del tablero.
       * 
       */
      void toString();

      /**
       * @brief Determina si un jugador ya gano el juego y envia el mensaje de
       * victoria.
       * 
       * @return int 1 si hay ganador, 0 si aun no hay.
       */
      int hayGanador()override; 
      
      /**
       * @brief Llama al metodo elegir ficha del controlador.
       * 
       * @return int 1 si la ficha es elegible, 0 si no lo es.
       */
      int elegirFicha();

      /**
       * @brief Rellena el tablero LUDO con el estado de las fichas de los
       * jugadores.
       * 
       */
      void rellenarMesa();

      /**
       * @brief Establece los parametros controlador y controladorLudo con los
       * parametros dados.
       * 
       * @param controlador va en el atributo controlador.
       * @param controladorLudo va en el parametro controladorLudo.
       */
      void setControlador(controlador_Ventanas* , ControladorAbstracto *);



      /**
       * @brief Pasa informacio en el tablero a la parte grafica por medio de
       * una string.
       * 
       * @param mensaje es el mensaje que se busca graficar en el tablero.
       */
      void graficarInformacion(string);

      /**
       * @brief Grafica la opcion para que el jugador escoja la ficha que quiere
       * mover.
       * 
       * @return int El numero de la ficha que quiere mover. 
       */
      int graficoElejirFicha(string);

      // El tablero del juego.
      FichaLudo * tablero[2][52];

      // Controlador de ventanas
      controlador_Ventanas *controlador;


};

#endif



