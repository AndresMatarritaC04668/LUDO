#ifndef _CONTROLADOR_LUDO
#define _CONTROLADOR_LUDO

#include "ControladorAbstracto.h"
#include "tableroLUDO.h"

class ControladorLudo : public ControladorAbstracto {

    public:
        ControladorLudo();
        void crearTablero() override;
        void asignarCantidadJugadores() override;
        void ubicarJugadores() override;
        void asignarPrimerJugador() override;
        void iniciarPartida() override;

    private:
        TableroLudo * tablero;

};


#endif