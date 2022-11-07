#ifndef MI_TABLEROABSTRACTO
#define MI_TABLEROABSTRACTO
using namespace std;
#include "Validador.h"
#include "Dado.h"
#include "Jugador.h"
#include <vector>


class Validador;

class TableroAbstracto
{
public:
	TableroAbstracto() {};
	~TableroAbstracto() {};
	virtual void asignarCantidadJugadores(int ) = 0; 
	virtual void ubicarJugadores()= 0; // Fichas enel vector zona segurado
	virtual int  hayGanador() = 0;
    virtual void finalizarJuego() = 0;
	virtual void iniciarPartida(){
	 int finalizado = 0;
     while(!finalizado){
       jugarTurno();
       finalizado = hayGanador();
       if(finalizado){
          break;
        }
	   pasarTurno();   
	  }
	  finalizarJuego();
    }
    virtual void pasarTurno() = 0; //Cambia al jugador actual //controlador 
    virtual void jugarTurno() = 0;      // Tira dado y ubica las fichas  // controlador
	virtual void asignarPrimerJugador() =0;
	virtual Jugador * getJugadorActual() = 0;
    virtual vector<Jugador*> getjugadores() = 0;
	int lanzarDado(){
      return dado.lanzar();
	}
	Validador* getValidador() {
		return this->validador;
	}

	vector<jugador *> getJugadores() {
		return jugadores;
	}

	protected:
	  vector<Jugador*> jugadores;
	  Jugador * jugadorActual;
      Dado  dado;
      int juegoTerminado;
      Validador * validador;


};

#endif



