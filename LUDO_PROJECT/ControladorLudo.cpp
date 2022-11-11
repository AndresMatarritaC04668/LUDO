#include "ControladorLudo.h"
#include "qinputdialog.h"
#include "controlador_ventanas.h"
#include "tableroLUDO.h"
#include "ControladorLudo.h"
#include "Controlador_Memento.h"
ControladorLudo::ControladorLudo() {
    this->controladorGrafico = new controlador_Ventanas(this);
    controladorGrafico->iniciar();

}

void ControladorLudo::crearTablero() {
    this->tablero = new TableroLudo();
    tablero->setControlador(controladorGrafico , this);
}

void ControladorLudo::asignarCantidadJugadores() {
    int cantidadJugadores = QInputDialog::getInt(controladorGrafico->input,"Cantidad de jugadores",                                             "Ingrese la cantidad de jugadores(2 a 4)");
    cin>>cantidadJugadores;
    tablero->asignarCantidadJugadores(cantidadJugadores);
}

void ControladorLudo::ubicarJugadores() {
    tablero->ubicarJugadores();
}

void ControladorLudo::asignarPrimerJugador() {
    tablero->asignarPrimerJugador();
}

void ControladorLudo::iniciarPartida() {
    crearTablero();
    asignarCantidadJugadores();
    ubicarJugadores();
    asignarPrimerJugador();
    tablero->iniciarPartida();
    delete tablero;
    controladorGrafico->mostrarMenu();
}

void ControladorLudo::renaudarPartida(){
    string nombrePartida = controladorGrafico->getNombreCSV();
    Controlador_Memento deserializador;
    this->tablero = deserializador.deserializarJuego(nombrePartida,controladorGrafico->input);

    if(tablero != nullptr){

      this->controladorGrafico->mostrarTablero(3);
      tablero->setControlador(controladorGrafico , this);
      tablero->iniciarPartida();

      delete tablero;
      controladorGrafico->mostrarMenu();
    }
}

void ControladorLudo::pausarPartida(){
   string nombrePartida = controladorGrafico->getNombreCSV();
   Controlador_Memento serializador;
   serializador.serializarTablero(this->tablero,nombrePartida);

}





