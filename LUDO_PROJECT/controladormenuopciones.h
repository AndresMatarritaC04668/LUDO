#ifndef CONTROLADORMENUOPCIONES_H
#define CONTROLADORMENUOPCIONES_H
#include "controlador_ventanas.h"

class MenuOpciones;

class ControladorMenuOpciones
{
public:
    ControladorMenuOpciones(controlador_Ventanas * controlador);
    void iniciar();
    void cerrarVentana(int opcion);

 private:
    MenuOpciones * menuOpciones;
    controlador_Ventanas * controlador;
};

#endif // CONTROLADORMENUOPCIONES_H
