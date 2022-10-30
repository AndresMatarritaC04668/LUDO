#ifndef VALIDADOR_27OCT22
#define VALIDADOR_27OCT22

#include <vector>
#include "Regla.h"
#include "TableroAbstracto.h"
#include "Jugador.h"
#include "FichaAbstracta.h"

using namespace std;

class Validador {
  
  protected:
    vector<Regla> reglas;
    TableroAbstracto * mesa;
  
  public:
    Validador();
    Validador(TableroAbstracto * mesa);
    virtual void iniciarReglas() = 0;
    // virtual void validarReglas(string tablero[2][52]) = 0;
    virtual int validarJugada(int posicion, FichaAbstracta * mover) = 0;
    // En LUDO: Verificar bloqueo.
    vector<Regla> obtenerReglas() { return reglas; };
    
    
};

#endif