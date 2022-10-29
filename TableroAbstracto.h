#ifndef MI_TABLEROABSTRACTO
#define MI_TABLEROABSTRACTO
using namespace std;
#include "Dado.h"


class TableroAbstracto
{
public:
	TableroAbstracto() {};
	~TableroAbstracto() {
        //delete jugadores
        //delete dado
    };
    

	virtual void asignarJugadores(int cantidadJugadores) = 0; 
	virtual void ubicarJugadores()= 0; // Fichas enel vector zona segurado
	virtual void iniciarPartida(){
    
    // dado = new dado()

    }
    virtual void pasarTurno() = 0; //Cambia al jugador actual //controlador 
    virtual void jugarTurno() = 0;      // Tira dado y ubica las fichas  // controlador
	
	void obtenerJugador(/*color jugador*/){}
	void obtenerJugadorActual(){}
    void asignarJugadorActual(/*jugador actual*/){}
	void obtenerJugadores(){}
	int lanzarDado(){
      return dado.lanzar();
	}
    

	private:
	// vector  *jugadores
	// jugador actual
    Dado  dado;
    int juegoTerminado;
};

#endif



