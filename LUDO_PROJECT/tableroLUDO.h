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
	TableroLudo();
     ~TableroLudo()override;
    
      void asignarCantidadJugadores(int cantidadJugadores)override; 
	void ubicarJugadores()override; // Fichas enel vector zona segurado
      void pasarTurno()override; //Cambia al jugador actual
      int jugarTurno()override;
      void asignarPrimerJugador()override;
      void toString();
      int hayGanador()override; 
      int elegirFicha();
      void rellenarMesa();
      void setJugadores(vector<Jugador*>)override;
      void detenerPartida()override;
      void finalizarJuego()override;
      void setControlador(controlador_Ventanas* , ControladorAbstracto *);
      Jugador * getJugadorActual()override;
      void graficarInformacion(string);
      int graficoElejirFicha(string);
      vector<Jugador*> getjugadores()override;
      FichaLudo * tablero[2][52];
      controlador_Ventanas *controlador;
      int getCantidadJugadores()override;
      void setCantidadJugadores(int)override;
      int getNumeroJugadorActual()override;
      void setNumeroJugadorActual(int)override;

};

#endif



