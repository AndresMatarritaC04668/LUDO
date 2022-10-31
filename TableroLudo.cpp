#include "TableroLudo.h"
#include "JugadorLudo.h"
#include "Jugador.h"
#include "Validador.h"
#include "ValidadorLudo.h"

TableroLudo::TableroLudo(){
  for(int i = 0 ; i < 52 ; i++){
    this->tablero[0][i] = nullptr;
    this->tablero[1][i] = nullptr;
  }
  this->validador = new ValidadorLudo(this);
}
void TableroLudo::asignarCantidadJugadores(int cantidadJugadores){
  this->cantidadJugadores = cantidadJugadores;
} 
void TableroLudo::ubicarJugadores(){
 
 JugadorLudo * jugador1 = new JugadorLudo("ROJO",0);
 jugadores.push_back(jugador1);
 JugadorLudo * jugador2 = new JugadorLudo("AZUL",13);
 jugadores.push_back(jugador2);

 if(cantidadJugadores >=3){
   JugadorLudo * jugador3 = new JugadorLudo("AMARILLO",26);
   jugadores.push_back(jugador3);
 }
 
 if(cantidadJugadores == 4){
   JugadorLudo * jugador4 = new JugadorLudo("VERDE",39);
   jugadores.push_back(jugador4);
 }

}
void TableroLudo::pasarTurno(){

  jugadorActual = jugadores[(this->jugadorPresente+1)%cantidadJugadores];
  this->jugadorPresente = (this->jugadorPresente+1)%cantidadJugadores;

}
void TableroLudo::jugarTurno(){
   jugadorActual->jugarTurno(this);
}


void TableroLudo::asignarPrimerJugador(){
  int numeroCorrecto = 0;
  while(!numeroCorrecto){
    int prueba = lanzarDado();
    if(prueba >= 0 && prueba < cantidadJugadores ){
      numeroCorrecto = prueba;
    }
  }
  jugadorActual = jugadores[numeroCorrecto];
  jugadorPresente = numeroCorrecto;
}

void TableroLudo::toString(){
  
  for(int i = 0 ; i < 52 ; i++){
    if( this->tablero[0][i]){
        cout<<tablero[0][i]->getColor();
    } else { 
      cout<< "Vacio";
    }
    if( this->tablero[1][i]){
        cout<<tablero[1][i]->getColor();
    } else { 
      cout<< "Vacio";
    }
    cout<<endl;
  }

}



