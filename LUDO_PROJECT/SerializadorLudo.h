#ifndef _SERIALIZADOR_LUDO
#define _SERIALIZADOR_LUDO

#include "SerializadorAbstracto.h"
#include "Jugador.h"
#include "JugadorLudo.h"
#include <vector>


/*

 {saveState
    jugador1 {
            color
            nombre
            ficha1 { pos, pasos, activo, caminoFinal, zonaSegura, numeroFicha}
            ficha2 { pos, pasos, activo, caminoFinal, zonaSegura, numeroFicha}
            ficha3 { pos, pasos, activo, caminoFinal, zonaSegura, numeroFicha}
            ficha4 { pos, pasos, activo, caminoFinal, zonaSegura, numeroFicha}
        }
    jugador2 {
            color
            nombre
            ficha1 { pos, activo, caminoFinal, zonaSegura, numeroFicha}
            ficha2 { pos, activo, caminoFinal, zonaSegura, numeroFicha}
            ficha3 { pos, activo, caminoFinal, zonaSegura, numeroFicha}
            ficha4 { pos, activo, caminoFinal, zonaSegura, numeroFicha}
        }

 }


*/

class SerializadorAbstracto;
class SerializadorLudo : public SerializadorAbstracto {

    public:
        SerializadorLudo();
        ~SerializadorLudo();

        void inicioObjeto() override;
        void finObjeto()  override;
        string getSerializacion() override;
        void agregarSeparador() override;
        void setJugadores(vector<Jugador *>);
        void serializarJugadores();
        void serializarFicha(JugadorLudo *);

    private:
        vector<JugadorLudo *> jugadores;


};

#endif
