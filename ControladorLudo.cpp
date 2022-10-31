#include "ControladorLudo.h"

ControladorLudo::ControladorLudo() {
    crearTablero();
}

void ControladorLudo::crearTablero() {
    this->tablero = new TableroLudo();
}

void ControladorLudo::asignarCantidadJugadores() {
    tablero->asignarCantidadJugadores(4);
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
