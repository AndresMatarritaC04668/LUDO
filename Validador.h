#ifndef VALIDADOR_27OCT22
#define VALIDADOR_27OCT22

#include <vector>
#include "Regla.h"
#include "TableroAbstracto.h"
#include "Jugador.h"

using namespace std;

class Validador {
  private:
    vector<Regla> reglas;
    TableroAbstracto * mesa;
  
  public:
    Validador();
    Validador(TableroAbstracto * mesa);
    virtual void iniciarReglas() = 0;
    // virtual void validarReglas(string tablero[2][52]) = 0;
    virtual void validarJugada(Jugador * jugador) = 0;
    // En LUDO: Verificar bloqueo.
    vector<Regla> obtenerReglas() { return reglas; };
    
};

#endif