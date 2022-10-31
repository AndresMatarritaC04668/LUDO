#include "ControladorLudo.h"

ControladorLudo::ControladorLudo() {
    crearTablero();
}

void ControladorLudo::crearTablero() {
    this->tablero = new TableroLudo();
}

void ControladorLudo::asignarCantidadJugadores() {
    int cantidadJugadores = 2;
    cout<<"Elige de 2 a 4 jugadores , digite la cantidad:\n";
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
