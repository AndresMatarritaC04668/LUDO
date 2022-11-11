#ifndef Objeto_h
#define Objeto_h

#include <map>
#include "Valor.h"
#include <vector>

class Objeto {
public:
    Objeto();
    ~Objeto();
    void obtAtributos(std::vector< std::pair< std::string, Valor* > >& vectorValores);
    typedef std::map< std::string, Valor* > map_atributos;
    void setAtributos(map_atributos);
protected:
    void agregarAtributo(std::string, Valor*);
    Valor* obtenerAtributo(std::string);
private:
    map_atributos atributos;
};

#endif
