#include "ControladorLudo.h"
#include "qinputdialog.h"
#include "controlador_ventanas.h"
#include "tableroLUDO.h"
ControladorLudo::ControladorLudo() {
    this->controladorGrafico = new controlador_Ventanas(this);
    controladorGrafico->iniciar();

}

void ControladorLudo::crearTablero() {
    this->tablero = new TableroLudo();
    tablero->setControlador(controladorGrafico);
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
    qDebug()<<"Hasta antes";
    ubicarJugadores();
    qDebug()<<"Hata Despues";
    asignarPrimerJugador();
    tablero->iniciarPartida();
    controladorGrafico->mostrarMenu();
}



