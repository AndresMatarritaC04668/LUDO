#ifndef MI_TABLEROABSTRACTO
#define MI_TABLEROABSTRACTO

#include "Validador.h"
#include "Dado.h"
#include "Jugador.h"
#include <vector>
#include "Objeto.h"
#include "ControladorAbstracto.h"

class Validador;

class TableroAbstracto : public Objeto{
public:
	TableroAbstracto() {};
    virtual ~TableroAbstracto() {};
	virtual void asignarCantidadJugadores(int ) = 0; 
	virtual void ubicarJugadores()= 0; // Fichas enel vector zona segurado
	virtual int  hayGanador() = 0;
    virtual void finalizarJuego() = 0;
    virtual void detenerPartida() = 0;
    virtual void setJugadores(vector<Jugador*>) = 0;
    virtual void iniciarPartida(){

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
    virtual void pasarTurno() = 0; //Cambia al jugador actual //controlador
    virtual int jugarTurno() = 0;      // Tira dado y ubica las fichas  // controlador
	virtual void asignarPrimerJugador() =0;
	virtual Jugador * getJugadorActual() = 0;
    virtual vector<Jugador*> getjugadores() = 0;
    virtual int getCantidadJugadores() = 0;
    virtual void setCantidadJugadores(int) = 0;
    virtual int getNumeroJugadorActual() = 0;
    virtual void setNumeroJugadorActual(int) = 0;

	int lanzarDado(){
      return dado.lanzar();
	}
	Validador* getValidador() {
		return this->validador;
	}

    vector<Jugador *> getJugadores() {
        return this->jugadores;
	}

	protected:
	  vector<Jugador*> jugadores;
	  Jugador * jugadorActual;
      Dado  dado;
      int juegoTerminado;
      Validador * validador;
      ControladorAbstracto * controladorLudo;


};

#endif



