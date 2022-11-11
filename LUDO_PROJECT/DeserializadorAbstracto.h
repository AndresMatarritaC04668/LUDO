#ifndef DeserializadorAbstracto_h
#define DeserializadorAbstracto_h

#include <stdio.h>
#include <string>
#include <map>
#include "Valor.h"
#include <vector>

class DeserializadorAbstracto {
public:
    DeserializadorAbstracto() {};
    ~DeserializadorAbstracto() {};
    virtual std::map< std::string, Valor*> deserializarObjeto(std::string) = 0;
    virtual std::vector<std::map< std::string, Valor* >> deserializarListaObjetos(std::string) = 0;
    
protected:
    virtual void eliminarInicioFinObjeto(std::string&) = 0;
    virtual std::pair<std::string, Valor*> extraerLlaveValor(std::string) = 0;
};

#endif /* DeserializadorJSON_h */
