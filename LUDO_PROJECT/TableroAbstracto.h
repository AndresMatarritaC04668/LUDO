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
    virtual ~TableroAbstracto() {};
	virtual void asignarCantidadJugadores(int ) = 0; 
	virtual void ubicarJugadores()= 0; // Fichas enel vector zona segurado
	virtual int  hayGanador() = 0;
    virtual void finalizarJuego() = 0;
	virtual void iniciarPartida(){
	 int finalizado = 0;
     int seguir = 1;
     while(!finalizado){ 
       seguir = jugarTurno();
       if(!seguir){
           // Llama al serializador
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


};

#endif



