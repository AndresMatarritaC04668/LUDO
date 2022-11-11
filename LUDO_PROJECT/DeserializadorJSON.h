#ifndef DeserializadorJSON_h
#define DeserializadorJSON_h

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include "Valor.h"
#include "DeserializadorAbstracto.h"

class DeserializadorJSON : public DeserializadorAbstracto {
public:
    DeserializadorJSON();
    ~DeserializadorJSON();
    std::map< std::string, Valor*> deserializarObjeto(std::string) override;
    std::vector<std::map< std::string, Valor* >> deserializarListaObjetos(std::string) override;
protected:
    void eliminarInicioFinObjeto(std::string&) override;
    std::pair<std::string, Valor*> extraerLlaveValor(std::string) override;
private:
    std::string const delimitadorAtributo = ",";
    std::string const delimitadorLlaveValor = ":";
};

#endif /* DeserializadorJSON_h */
