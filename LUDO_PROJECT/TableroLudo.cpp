#include "tableroLUDO.h"
#include "JugadorLudo.h"
#include "Jugador.h"
#include "Validador.h"
#include "ValidadorLudo.h"
#include "controlador_ventanas.h"
#include <qinputdialog.h>
#include <qstring.h>
#include <qmessagebox.h>
#include "Hilera.h"
#include <Controlador_Memento.h>

TableroLudo::TableroLudo(){
  for(int i = 0 ; i < 52 ; i++){
    this->tablero[0][i] = nullptr;
    this->tablero[1][i] = nullptr;
  }
  this->validador = new ValidadorLudo(this);
}

TableroLudo::~TableroLudo(){
  for(int i = 0 ; i < getCantidadJugadores(); i++){
    delete jugadores[i];
  }
}

void TableroLudo::setControlador(controlador_Ventanas* controlador , ControladorAbstracto * controladorJuego){
   this->controlador = controlador;
   this->controladorJuego = controladorJuego;
}

void TableroLudo::ubicarJugadores(){
 QString nombre = "";
 nombre = QInputDialog::getText(controlador->input,"Nombre jugador",
                                  "Ingrese el nombre del jugador rojo");
 //cin>>getCantidadJugadores();
 JugadorLudo * jugador1 = new JugadorLudo("ROJO",10,nombre.toStdString());
 jugadores.push_back(jugador1);

 nombre = QInputDialog::getText(controlador->input,"Nombre jugador",
                                  "Ingrese el nombre del jugador azul");
JugadorLudo * jugador2 = new JugadorLudo("AZUL",23,nombre.toStdString());
 jugadores.push_back(jugador2);

 if(getCantidadJugadores() >=3){
     nombre = QInputDialog::getText(controlador->input,"Nombre jugador",
                                      "Ingrese el nombre del jugador amarillo");
   JugadorLudo * jugador3 = new JugadorLudo("AMARILLO",36,nombre.toStdString());
   jugadores.push_back(jugador3);
 }else{
  jugadores.push_back(nullptr);
}
 
 if(getCantidadJugadores() == 4){
     nombre = QInputDialog::getText(controlador->input,"Nombre jugador",
                                      "Ingrese el nombre del jugador verde");
   JugadorLudo * jugador4 = new JugadorLudo("VERDE",49,nombre.toStdString());
   jugadores.push_back(jugador4);
 }else{
  jugadores.push_back(nullptr);
 }

 controlador->graficarCarcel(jugadores);

}


int TableroLudo::jugarTurno(){
  jugadorActual = jugadores[this->getNumeroJugadorActual()];
  int seguir = jugadorActual->jugarTurno(this);

  return seguir;

}

void TableroLudo::asignarPrimerJugador(){
  int numeroCorrecto = 0;
  while(!numeroCorrecto){
    int prueba = lanzarDado();
    if(prueba >= 0 && prueba < getCantidadJugadores() ){
      numeroCorrecto = prueba;
    }
  }
  jugadorActual = jugadores[numeroCorrecto];
  setNumeroJugadorActual( numeroCorrecto);
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

void  TableroLudo::graficarInformacion(string mensaje){
    controlador->mensajeGrafico(mensaje);
}

int TableroLudo::graficoElejirFicha(string mensaje){
   return controlador->elegirFicha(mensaje);
}

void TableroLudo::rellenarMesa(){
    for(FichaAbstracta * ficha : jugadores[0]->getFichas()){
        if(ficha->getEstado() == 1 && ficha->getPasosDados() <= 54){
            this->tablero[ficha->getX()][ficha->getY()] = dynamic_cast<FichaLudo* >(ficha);
        }
    }

    for(FichaAbstracta * ficha : jugadores[1]->getFichas()){
        if(ficha->getEstado() == 1 && ficha->getPasosDados() <= 54){
            this->tablero[ficha->getX()][ficha->getY()] = dynamic_cast<FichaLudo* >(ficha);
        }
    }

    if(this->getCantidadJugadores() >= 3){

        for(FichaAbstracta * ficha : jugadores[2]->getFichas()){
            if(ficha->getEstado() == 1 && ficha->getPasosDados() <= 54){
                this->tablero[ficha->getX()][ficha->getY()] = dynamic_cast<FichaLudo* >(ficha);
            }
        }
    }

    if(this->getCantidadJugadores() ==4 ){

        for(FichaAbstracta * ficha : jugadores[3]->getFichas()){
            if(ficha->getEstado() == 1 && ficha->getPasosDados() <= 54){
                this->tablero[ficha->getX()][ficha->getY()] = dynamic_cast<FichaLudo* >(ficha);
            }
        }
    }


}



