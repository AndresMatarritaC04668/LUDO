#include "ControladorLudo.h"
#include "qinputdialog.h"

ControladorLudo::ControladorLudo() {
    crearTablero();
}

void ControladorLudo::crearTablero() {
    this->tablero = new TableroLudo();
    this->controlador = new controlador_Ventanas();
    tablero->setControlador(controlador);
    controlador->ventanaPrincipal->show();
}

void ControladorLudo::asignarCantidadJugadores() {
  int cantidadJugadores = QInputDialog::getInt(controlador->input,"Cantidad de jugadores",                                             "Ingrese la cantidad de jugadores(2 a 4)");
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
    tablero->iniciarPartida();
}



