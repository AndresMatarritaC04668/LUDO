#ifndef CONTROLADORVENTANAPRINCIPAL_H
#define CONTROLADORVENTANAPRINCIPAL_H

#include "controlador_ventanas.h"

class VentanaPrincipal;

class ControladorVentanaPrincipal
{
public:
    ControladorVentanaPrincipal(controlador_Ventanas * controlador);
    void iniciar();
    void cerrarVentana();
    void graficarTablero(TableroAbstracto*);
    void graficarCarcel(vector<Jugador*> jugadores );
    void graficarLineaFinal(TableroAbstracto*);
    void graficarCeldas(QLabel * , string color , QString numero);

private:
    controlador_Ventanas * controlador;
    VentanaPrincipal * ventanaPrincipal;
};

#endif // CONTROLADORVENTANAPRINCIPAL_H
