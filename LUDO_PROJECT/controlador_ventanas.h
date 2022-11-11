#ifndef CONTROLADOR_VENTANAS_H
#define CONTROLADOR_VENTANAS_H

#include "ventanainformacion.h"
#include <string.h>
#include <TableroAbstracto.h>
#include <QLabel>
#include "ControladorLudo.h"

class ControladorMenuOpciones;
class ControladorVentanaPrincipal;
using namespace std;

class controlador_Ventanas
{
public:
    controlador_Ventanas(ControladorLudo * controlador);
    void graficarTablero(TableroAbstracto*);
    void iniciar();
    void mostrarTablero(int);
    void mostrarMenu();
    void graficarCarcel(vector<Jugador*> jugadores);
    void mostrarReglas();
    string getNombre(string numeroJugador);
    string getNombreCSV();
    int elegirFicha(string);
    int eleccionJugador(string turno);
    ventanaInformacion * input;
    void mensajeGrafico(string);

private:
  ControladorMenuOpciones * controladorMenuOpciones;
  ControladorVentanaPrincipal * controladorVentanaPrincipal;
  ControladorLudo * controladorLudo;
};

#endif // CONTROLADOR_VENTANAS_H
