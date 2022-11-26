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
       * @brief Asigna la cantidad de jugadores, numero dado por parametro.
       * 
       * @param cantidadJugadores Es el numero de jugadores que tendra el juego.
       */
      void asignarCantidadJugadores(int cantidadJugadores)override;

      /**
       * @brief Crea y coloca a los jugadores en el tablero de juego por medio de
       * la interfaz.
       * 
       */
	void ubicarJugadores()override; // Fichas enel vector zona segurado

      /**
       * @brief Pasa al siguiente turno.
       * 
       */
      void pasarTurno()override; //Cambia al jugador actual
      
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
       * @brief Set the Jugadores object.
       * 
       * @param jugadores se guarda en el atributo de jugadores.
       */
      void setJugadores(vector<Jugador*>)override;

      /**
       * @brief Detiene la partida pausandola, mas no la termina.
       * 
       */
      void detenerPartida()override;
      
      /**
       * @brief Termina el juego.
       * 
       */
      void finalizarJuego()override;
      
      /**
       * @brief Establece los parametros controlador y controladorLudo con los
       * parametros dados.
       * 
       * @param controlador va en el atributo controlador.
       * @param controladorLudo va en el parametro controladorLudo.
       */
      void setControlador(controlador_Ventanas* , ControladorAbstracto *);

      /**
       * @brief Get the jugadorActual object
       * 
       * @return Jugador* el jugador actual. 
       */
      Jugador * getJugadorActual()override;

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
      
      /**
       * @brief Get the jugadores object
       * 
       * @return vector<Jugador*> el atributo jugadores.
       */
      vector<Jugador*> getjugadores()override;

      // El tablero del juego.
      FichaLudo * tablero[2][52];

      // Controlador de ventanas
      controlador_Ventanas *controlador;

      /**
       * @brief Obtiene la cantidad de jugadores.
       * 
       * @return int la cantidad de jugadores.
       */
      int getCantidadJugadores()override;

      /**
       * @brief Establece la cantidad de jugadores mediante un parametro.
       * 
       * @param cantidadJugadores El numero de jugadores.
       */
      void setCantidadJugadores(int)override;
      
      /**
       * @brief Devuelve el numero del jugador que esta ejecutando su turno.
       * 
       * @return int El numero del jugador actual.
       */
      int getNumeroJugadorActual()override;

      /**
       * @brief Establece el numero del jugador actual por medio de un parametro.
       * Establece el numero por el que el jugador sera reconocido en el juego.
       * 
       * @param jugadorPresente El numero que correspondera al jugador actual.
       */
      void setNumeroJugadorActual(int)override;
};

#endif



