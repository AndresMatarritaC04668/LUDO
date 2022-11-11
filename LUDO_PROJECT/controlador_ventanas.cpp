#include "controlador_ventanas.h"
#include <qstring.h>
#include <QPushButton>
#include <qmessagebox.h>
#include "qinputdialog.h"
#include <iostream>
#include "controladormenuopciones.h"
#include "controladorventanaprincipal.h"
#include "ValidadorLudo.h"
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

void controlador_Ventanas::mostrarTablero(int opcion){

   if(opcion == 1){
       controladorVentanaPrincipal->iniciar();
       controladorLudo->iniciarPartida();
   } else if(opcion == 2 ){
       controladorLudo->renaudarPartida();
   } else if(opcion == 3){
       controladorMenuOpciones->cerrarVentana(opcion);
       controladorVentanaPrincipal->iniciar();
   }

}

void controlador_Ventanas::graficarCarcel(vector<Jugador*> jugadores){
    controladorVentanaPrincipal->graficarCarcel(jugadores);
}

void controlador_Ventanas:: mostrarMenu(){
    this->controladorVentanaPrincipal->cerrarVentana();
    this->controladorMenuOpciones->iniciar();
}

void controlador_Ventanas::mostrarReglas(){
    ValidadorLudo validador;
    validador.iniciarReglas();
    string reglas = validador.toStringReglas();
    this->controladorMenuOpciones->graficarReglas(reglas);
}

int controlador_Ventanas::eleccionJugador(string nombre){

    int eleccion = 1;
    string mensaje = nombre + "\n\nPresiona Yes para lanzar dado y seguir jugando"
                              " \nO presiona NO para guardar partida y salir";

    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(input,"Elección del jugador" , QString::fromStdString(mensaje),
                                  QMessageBox::Yes    |        QMessageBox::No);
    if(reply == QMessageBox::Yes){
        qDebug () << "Sigue jugando";
        eleccion = 1;
    } else {
        qDebug () << "Guardar y salir";
        eleccion = 0;
    }

    return eleccion;

}

string controlador_Ventanas::getNombreCSV(){
    string mensaje =  "\nDigita el nombre de la partidad";
    QString nombrePartida = "";
    nombrePartida = QInputDialog::getText(this->input,"Nombre de la partida",QString::fromStdString(mensaje));

     return nombrePartida.toStdString();
}
