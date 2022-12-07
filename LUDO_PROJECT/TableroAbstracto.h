/**
 * @file TableroAbstracto.h
 * @authors Esteban José Mora García (C05126),
 * José Andrés Matarrita Miranda (C04668), Joseph Fernando Núñez Solano (C05582)
 * @brief Clase plantilla para un tablero abstracto.
 * @version 0.1
 * @date 2022-11-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MI_TABLEROABSTRACTO
#define MI_TABLEROABSTRACTO

#include "Validador.h"
#include "Dado.h"
#include "Jugador.h"
#include <vector>
#include "Objeto.h"
#include "ControladorAbstracto.h"
#include "Hilera.h"

class Validador;

class TableroAbstracto : public Objeto{
public:
    /**
     * @brief Construct a new Tablero Abstracto object
     * 
     */
	TableroAbstracto() {};

    /**
     * @brief Destroy the Tablero Abstracto object
     * 
     */
    virtual ~TableroAbstracto() {};

    /**
     * @brief Asigna la cantidad de jugadores, numero dado por parametro.
     * 
     * @param cantidadJugadores Es el numero de jugadores que tendra el juego.
     */
    void asignarCantidadJugadores(int cantidadJugadores){
        setCantidadJugadores(cantidadJugadores);
    }

    /**
     * @brief Crea y coloca a los jugadores en el tablero de juego por medio de
     * la interfaz.
     * 
     */
	virtual void ubicarJugadores()= 0; // Fichas enel vector zona segurado

    /**
     * @brief Determina si un jugador ya gano el juego y envia el mensaje de
     * victoria.
     * 
     * @return int 1 si hay ganador, 0 si aun no hay.
     */
	virtual int  hayGanador() = 0;

    /**
     * @brief Termina el juego.
     * 
     */
    void finalizarJuego(){
        string mensaje = "";
        mensaje += "Gracias por jugar\n";
        mensaje += "El ganador es: " + jugadorActual->getNombre();
    }

    /**
     * @brief Detiene la partida pausandola, mas no la termina.
     * 
     */
    void detenerPartida(){
       this->controladorJuego->pausarPartida();
    }

    /**
     * @brief Set the Jugadores object.
     * 
     * @param jugadores se guarda en el atributo de jugadores.
     */
    void setJugadores(vector<Jugador*> jugadores){
        this->jugadores = jugadores;
    }

    /**
     * @brief Comienza el mecanismo para iniciar el juego, se encarga de otras
     * labores como pausar la partida si es solicitado o llamar a determinar si
     * hay ganador.
     * 
     */
    void iniciarPartida(){

	 int finalizado = 0;
     int seguir = 1;
     while(!finalizado){ 

       seguir = jugarTurno();
       if(!seguir){
           detenerPartida();
           break;
       }
       finalizado = hayGanador();
       if(finalizado){
          break;
        }
	   pasarTurno();   
	  }
	  finalizarJuego();
    }

    /**
     * @brief Pasa al siguiente turno.Cambia al jugador actual
     * 
     */
    void pasarTurno(){
        jugadorActual = jugadores[(getNumeroJugadorActual()+1)%getCantidadJugadores()];
        int siguiente =  (getNumeroJugadorActual()+1)%getCantidadJugadores();
        setNumeroJugadorActual(siguiente);
    } 

    /**
     * @brief Un jugador ejecuta su turno tirando el dado y moviendo las fichas.
     * 
     * @return int 
     */
    virtual int jugarTurno() = 0;   // Tira dado y ubica las fichas  // controlador

    /**
     * @brief Ejecuta un mecanismo para determinar cual jugador va primero.
     * 
     */
	virtual void asignarPrimerJugador() =0;

    /**
     * @brief Get the jugadorActual object
     * 
     * @return Jugador* el jugador actual. 
     */
	Jugador * getJugadorActual(){
        return this->jugadorActual;
    }

    /**
     * @brief Get the jugadores object
     * 
     * @return vector<Jugador*> el atributo jugadores.
     */
    vector<Jugador*> getjugadores(){
      return this->jugadores;
    }

    /**
     * @brief Obtiene la cantidad de jugadores.
     * 
     * @return int la cantidad de jugadores.
     */
    int getCantidadJugadores(){
        std::string cantidadJugadores = "";
        Valor* valor = obtenerAtributo("cantidadJugadores");
        if (valor != nullptr) {
            cantidadJugadores = ((Hilera*) valor)->obt();
        }
        return stoi(cantidadJugadores);
    }

    /**
     * @brief Establece la cantidad de jugadores mediante un parametro.
     * 
     * @param cantidadJugadores El numero de jugadores.
     */
    void setCantidadJugadores(int cantidadJugadores){
        agregarAtributo("cantidadJugadores",new Hilera(to_string(cantidadJugadores)));
    }

    /**
     * @brief Devuelve el numero del jugador que esta ejecutando su turno.
     * 
     * @return int El numero del jugador actual.
     */
    int getNumeroJugadorActual(){
        std::string jugadorPresente = "";
        Valor* valor = obtenerAtributo("jugadorPresente");
        if (valor != nullptr) {
            jugadorPresente = ((Hilera*) valor)->obt();
        }
        return stoi(jugadorPresente);
    }

    /**
     * @brief Establece el numero del jugador actual por medio de un parametro.
     * Establece el numero por el que el jugador sera reconocido en el juego.
     * 
     * @param jugadorPresente El numero que correspondera al jugador actual.
     */
    void setNumeroJugadorActual(int jugadorPresente){
            agregarAtributo("jugadorPresente",new Hilera(to_string(jugadorPresente)));
    }

    /**
     * @brief Lanza el objeto dado.
     * 
     * @return int el numero resultante del lanzamiento.
     */
	int lanzarDado(){
      return dado.lanzar();
	}
    
    /**
     * @brief Get the validador object
     * 
     * @return Validador* El parametro validador.
     */
	Validador* getValidador() {
		return this->validador;
	}

    /**
     * @brief Get the jugadores object
     * 
     * @return vector<Jugador *> El parametro jugadores.
     */
    vector<Jugador *> getJugadores() {
        return this->jugadores;
	}

	protected:
	  vector<Jugador*> jugadores;
	  Jugador * jugadorActual;
      Dado  dado;
      int juegoTerminado;
      Validador * validador;
      ControladorAbstracto * controladorJuego;


};

#endif



