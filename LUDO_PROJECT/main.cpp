#include "ventanaprincipal.h"
#include "controlador_ventanas.h"
#include "TableroLUDO.h"
#include "FichaLudo.h"
#include "ControladorLudo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ControladorLudo * controlador = new ControladorLudo();
    controlador->asignarCantidadJugadores();
    controlador->ubicarJugadores();
    controlador->asignarPrimerJugador();
    controlador->iniciarPartida();


    controlador_Ventanas * controladorVentana = new controlador_Ventanas();
    controladorVentana->iniciar();
    return a.exec();
}
