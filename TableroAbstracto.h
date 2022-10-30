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
	~TableroAbstracto() {
        //delete jugadores
        //delete dado
    };
    

	virtual void asignarCantidadJugadores(int ) = 0; 
	virtual void ubicarJugadores()= 0; // Fichas enel vector zona segurado
	virtual void iniciarPartida(){
       jugarTurno();

    }
    virtual void pasarTurno() = 0; //Cambia al jugador actual //controlador 
    virtual void jugarTurno() = 0;      // Tira dado y ubica las fichas  // controlador
	virtual void asignarPrimerJugador() =0;
	void obtenerJugador(/*color jugador*/){}
	void obtenerJugadorActual(){}
    void asignarJugadorActual(/*jugador actual*/){}
	void obtenerJugadores(){}
	int lanzarDado(){
      return dado.lanzar();
	}

	protected:
	  vector<Jugador*> jugadores;
	  Jugador * jugadorActual;
      Dado  dado;
      int juegoTerminado;
      Validador * validador;


};

#endif



