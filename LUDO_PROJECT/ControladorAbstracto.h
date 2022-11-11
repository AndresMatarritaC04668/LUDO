#ifndef _CONTROLADOR_ABSTRACTO
#define _CONTROLADOR_ABSTRACTO

class ControladorAbstracto {

    public:

        ControladorAbstracto(){}
        virtual ~ControladorAbstracto(){}
        virtual void crearTablero() = 0;
        virtual void asignarCantidadJugadores() = 0;
        virtual void ubicarJugadores() = 0;
        virtual void asignarPrimerJugador() = 0;
        virtual void iniciarPartida() = 0;
        virtual void pausarPartida() = 0;
        virtual void renaudarPartida() = 0;

};

#endif
