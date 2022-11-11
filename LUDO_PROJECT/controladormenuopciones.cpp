#include "controladormenuopciones.h"
#include "menuopciones.h"
#include <qmessagebox.h>

ControladorMenuOpciones::ControladorMenuOpciones(controlador_Ventanas * controlador)
{
  this->controlador = controlador;
  this->menuOpciones = new MenuOpciones();
  this->menuOpciones->setControlador(this);
}

void ControladorMenuOpciones::iniciar(){
   this->menuOpciones->show();
}
void ControladorMenuOpciones::cerrarVentana(int opcion){

    if(opcion == 1){
       this->menuOpciones->close();
       controlador->mostrarTablero(opcion);
    } else if(opcion == 2){
       controlador->mostrarTablero(opcion);
    } else if(opcion == 1){
       this->menuOpciones->close();
    }
}


void ControladorMenuOpciones::mostrarReglas(){
  controlador->mostrarReglas();
}

void ControladorMenuOpciones::graficarReglas(string reglas){
  QMessageBox::information(menuOpciones," Reglas ", QString::fromStdString(reglas));
}
