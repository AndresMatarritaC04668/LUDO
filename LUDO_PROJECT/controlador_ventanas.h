#ifndef CONTROLADOR_VENTANAS_H
#define CONTROLADOR_VENTANAS_H
#include "ventanaprincipal.h"
#include "ventanainformacion.h"
#include <string.h>
#include <TableroAbstracto.h>
#include <QLabel>
using namespace std;

class controlador_Ventanas
{
public:
    controlador_Ventanas();
    void graficarTablero(TableroAbstracto*);
    void graficarCarcel(vector<Jugador*> jugadores );
    void graficarLineaFinal(TableroAbstracto*);
    void graficarCeldas(QLabel * , string color , QString numero);

    void iniciar();
    string getNombre(string numeroJugador);
    int elegirFicha(string);
    VentanaPrincipal * ventanaPrincipal;
    ventanaInformacion * input;
    void mensajeGrafico(string);

private:

};

#endif // CONTROLADOR_VENTANAS_H
