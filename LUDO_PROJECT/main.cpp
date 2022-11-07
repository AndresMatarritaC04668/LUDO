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
    //controlador->asignarCantidadJugadores();
    //controlador->ubicarJugadores();
    //controlador->asignarPrimerJugador();
    //controlador->iniciarPartida();

    return a.exec();
}
