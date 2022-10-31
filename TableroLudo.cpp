#include "tableroLUDO.h"
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

TableroLudo::~TableroLudo(){
  for(int i = 0 ; i < cantidadJugadores ; i++){
    delete jugadores[i];
  }
}
void TableroLudo::asignarCantidadJugadores(int cantidadJugadores){
  this->cantidadJugadores = cantidadJugadores;
} 
void TableroLudo::ubicarJugadores(){
 string nombre = "";
 cout<<"Digite el nombre del jugador rojo";
 cin>> nombre;
 JugadorLudo * jugador1 = new JugadorLudo("ROJO",0,nombre);
 jugadores.push_back(jugador1);

 cout<<"Digite el nombre del jugador azul";
 cin>> nombre;
 JugadorLudo * jugador2 = new JugadorLudo("AZUL",13,nombre);
 jugadores.push_back(jugador2);

 if(cantidadJugadores >=3){
   cout<<"Digite el nombre del jugador amarillo";
   cin>> nombre;
   JugadorLudo * jugador3 = new JugadorLudo("AMARILLO",26,nombre);
   jugadores.push_back(jugador3);
 }
 
 if(cantidadJugadores == 4){
   cout<<"Digite el nombre del jugador verde";
   cin>> nombre;
   JugadorLudo * jugador4 = new JugadorLudo("VERDE",39,nombre);
   jugadores.push_back(jugador4);
 }

}
void TableroLudo::pasarTurno(){

  jugadorActual = jugadores[(this->jugadorPresente+1)%cantidadJugadores];
  this->jugadorPresente = (this->jugadorPresente+1)%cantidadJugadores;
  JugadorLudo * jugadorActualLudo = dynamic_cast<JugadorLudo* >(jugadorActual);
  cout<<"Turno del jugador "<<jugadorActualLudo->getColor();
 

}
void TableroLudo::jugarTurno(){
   int situacion = jugadorActual->jugarTurno(this);
   if(situacion == 0){
     cout<<"No sacas 6 no sacas ficha de la carcel";
   }
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
  JugadorLudo * jugadorActualLudo = dynamic_cast<JugadorLudo* >(jugadorActual);
  cout<<"Comienza el jugador " <<jugadorActualLudo->getColor()<<endl;
}

int TableroLudo::hayGanador(){ 
  return validador->esGanador(jugadorActual->getFichas());
}

Jugador * TableroLudo::getJugadorActual(){
    return this->jugadorActual;
}

void TableroLudo::toString(){
  
  for(int i = 0 ; i < 52 ; i++){
    if( this->tablero[0][i]){
        cout<<" "<<tablero[0][i]->getColor()<<tablero[0][i]->getNumeroFicha()<<" pasos "<< tablero[0][i]->getPasosDados()<<" " ;
    } else { 
      cout<< "  Vacio  ";
    }
    if( this->tablero[1][i]){
        cout<<tablero[1][i]->getColor()<<tablero[1][i]->getNumeroFicha() << " pasos " << tablero[1][i]->getPasosDados()<<" " ;
    } else { 
      cout<< "  Vacio  ";
    }
    cout<<endl;
  }

}

void TableroLudo::finalizarJuego(){
   cout<< "Gracias por jugar";
   cout<< "El ganador es: " << jugadorActual->getNombre();
}



