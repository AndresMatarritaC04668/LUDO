#include "tableroLUDO.h"
#include "JugadorLudo.h"
#include "Jugador.h"
#include "Validador.h"
#include "ValidadorLudo.h"
#include "controlador_ventanas.h"
#include <qinputdialog.h>
#include <qstring.h>
#include <qmessagebox.h>

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

void TableroLudo::setControlador(controlador_Ventanas* controlador){
   this->controlador = controlador;
}

void TableroLudo::ubicarJugadores(){
 QString nombre = "";
 nombre = QInputDialog::getText(controlador->input,"Nombre jugador",
                                  "Ingrese el nombre del jugador rojo");
 cin>>cantidadJugadores;
 JugadorLudo * jugador1 = new JugadorLudo("ROJO",10,nombre.toStdString());
 jugadores.push_back(jugador1);

 nombre = QInputDialog::getText(controlador->input,"Nombre jugador",
                                  "Ingrese el nombre del jugador azul");
JugadorLudo * jugador2 = new JugadorLudo("AZUL",23,nombre.toStdString());
 jugadores.push_back(jugador2);

 if(cantidadJugadores >=3){
     nombre = QInputDialog::getText(controlador->input,"Nombre jugador",
                                      "Ingrese el nombre del jugador amarillo");
   JugadorLudo * jugador3 = new JugadorLudo("AMARILLO",36,nombre.toStdString());
   jugadores.push_back(jugador3);
 }else{
  jugadores.push_back(nullptr);
}
 
 if(cantidadJugadores == 4){
     nombre = QInputDialog::getText(controlador->input,"Nombre jugador",
                                      "Ingrese el nombre del jugador verde");
   JugadorLudo * jugador4 = new JugadorLudo("VERDE",49,nombre.toStdString());
   jugadores.push_back(jugador4);
 }else{
  jugadores.push_back(nullptr);
 }

 controlador->graficarCarcel(jugadores);

}
void TableroLudo::pasarTurno(){

  jugadorActual = jugadores[(this->jugadorPresente+1)%cantidadJugadores];
  this->jugadorPresente = (this->jugadorPresente+1)%cantidadJugadores;
  JugadorLudo * jugadorActualLudo = dynamic_cast<JugadorLudo* >(jugadorActual);
  cout<<"Turno del jugador "<<jugadorActualLudo->getColor();
 

}
void TableroLudo::jugarTurno(){
   int situacion = jugadorActual->jugarTurno(this);
   string mensaje = "";
   if(situacion == 0){
     mensaje += "No sacas 6 no sacas ficha de la carcel";
     graficarInformacion(mensaje);
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
  string mensaje = "";
  mensaje = "Comienza el jugador: " + jugadorActualLudo->getNombre();
  graficarInformacion(mensaje);
}

int TableroLudo::hayGanador(){ 
   int opcion =  validador->esGanador(jugadorActual->getFichas());
   if(opcion == 1){
       string mensaje = "Ganador: " + jugadorActual->getNombre() + "felicidades  " + "gracias por jugar";
       controlador->mensajeGrafico(mensaje);
   }
   return opcion;
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
   string mensaje = "";
   mensaje += "Gracias por jugar\n";
   mensaje += "El ganador es: " + jugadorActual->getNombre();
}

void  TableroLudo::graficarInformacion(string mensaje){
    controlador->mensajeGrafico(mensaje);
}

int TableroLudo::graficoElejirFicha(string mensaje){
   return controlador->elegirFicha(mensaje);
}

vector<Jugador*> TableroLudo::getjugadores(){

    return this->jugadores;
}



