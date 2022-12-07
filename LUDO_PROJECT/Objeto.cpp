
#include "Objeto.h"

Objeto::Objeto() {}

Objeto::~Objeto() {

}

void Objeto::obtAtributos(std::vector< std::pair< std::string, Valor* > >& vectorValores)
{
    unsigned long numAtributos = atributos.size();
    vectorValores.resize(numAtributos);
    int j = 0;
    for (auto i : atributos)
    {
        vectorValores[j] = i;
        j++;
    }
}

void Objeto::agregarAtributo(std::string nombre, Valor* valor)
{
    auto atributo = atributos.find(nombre);
    if (atributo != atributos.end()) {
        atributo->second = valor;
    }
    else {
        atributos.insert(std::pair< std::string, Valor* >(nombre,valor));
    }
}

Valor* Objeto::obtenerAtributo(std::string nombre)
{
    Valor* valor = nullptr;
    auto atributo = atributos.find(nombre);
    if (atributo != atributos.end()){
        valor = atributo->second;
    }
    return valor;
}

void Objeto::setAtributos(map_atributos atributos)
{
    this->atributos = atributos;
}
