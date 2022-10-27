#ifndef VALIDADORLUDO_27OCT22
#define VALIDADORLUDO_27OCT22

#include "Validador.h"
#include "TableroAbstracto.h"
#include "tableroLUDO.h"
#include "Jugador.h"

class ValidadorLudo : Validador {
    private:
        TableroLudo * mesaLudo;
    public:
        ValidadorLudo();
        ValidadorLudo(TableroAbstracto * mesa);
        void iniciarReglas() override;
        void validarJugada(Jugador * jugador) override;
        bool verificarBloqueo();
};

#endif