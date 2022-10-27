#ifndef REGLA_27OCT22
#define REGLA_27OCT22

#include <string>

using namespace std;

class Regla {
  private:
    string nombre;

  public:
    Regla();
    Regla(string);
    string obtenerNombre();
    virtual int validarRegla() = 0;
};

#endif