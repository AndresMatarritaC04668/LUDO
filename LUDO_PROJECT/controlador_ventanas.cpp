#include "controlador_ventanas.h"
#include <qstring.h>
#include <QPushButton>
#include <qmessagebox.h>
#include "qinputdialog.h"
#include <iostream>
#include "controladormenuopciones.h"
#include "controladorventanaprincipal.h"

controlador_Ventanas::controlador_Ventanas(ControladorLudo * controlador)
{
    this->controladorVentanaPrincipal = new ControladorVentanaPrincipal(this);
    this->input = new ventanaInformacion();
    this->controladorMenuOpciones = new ControladorMenuOpciones(this);
    this->controladorLudo = controlador;
}

void controlador_Ventanas::iniciar(){
    this->controladorMenuOpciones->iniciar();


}

void controlador_Ventanas::graficarTablero(TableroAbstracto * mesa){
    controladorVentanaPrincipal->graficarTablero(mesa);
}

void controlador_Ventanas::mensajeGrafico(string mensaje){
    QMessageBox::information(input,"Informacion", QString::fromStdString(mensaje));


 }

int  controlador_Ventanas::elegirFicha(string mensaje){
  mensaje +=  "\nQue numero de ficha desea elegir: 1,2,3 o 4";
  mensaje += "\n Digita el numero de ficha";
  int opcion = 1;
  opcion = QInputDialog::getInt(this->input,"Elegir ficha",QString::fromStdString(mensaje));

   return opcion;
}

void controlador_Ventanas::mostrarTablero(){
    controladorVentanaPrincipal->iniciar();
    controladorLudo->iniciarPartida();
}

void controlador_Ventanas::graficarCarcel(vector<Jugador*> jugadores){
    controladorVentanaPrincipal->graficarCarcel(jugadores);
}
