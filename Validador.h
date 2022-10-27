#ifndef VALIDADOR_27OCT22
#define VALIDADOR_27OCT22

#include <vector>
#include "Regla.h"

using namespace std;

class Validador {
  private:
    vector<Regla> reglas;
  
  public:
    Validador();
    virtual void iniciarReglas() = 0;
    // virtual void validarReglas(vector<Jugadores>) = 0;
    virtual void validarJugada() = 0;
    vector<Regla> obtenerReglas() { return reglas; };

};

#endif