#ifndef _CONTROLADOR_LUDO
#define _CONTROLADOR_LUDO

#include "ControladorAbstracto.h"

class controlador_Ventanas;
class TableroLudo;

class ControladorLudo : public ControladorAbstracto {

    public:
        ControladorLudo();
        void crearTablero() override;
        void asignarCantidadJugadores() override;
        void ubicarJugadores() override;
        void asignarPrimerJugador() override;
        void iniciarPartida()override;
        void pausarPartida()override;
        void renaudarPartida()override;

    private:
        TableroLudo * tablero;
        controlador_Ventanas * controladorGrafico;


};

#endif
