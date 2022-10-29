#include "TableroLudo.h"
#include "JugadorLudo.h"
#include "Jugador.h"


TableroLudo::TableroLudo(){
  for(int i = 0 ; i < 52 ; i++){
    this->tablero[0][i] = new FichaLudo("qwrwedcsd",2);
    this->tablero[1][i] = new FichaLudo("qwrwedcsd",2);
  }
  

  
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

}
void TableroLudo::jugarTurno(){


}

void TableroLudo::moverFicha(int pasos){

    

}

void TableroLudo::elegirPrimero(){

   
}