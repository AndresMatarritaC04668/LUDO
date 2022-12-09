#include <iostream>
#include "FichaLudo.h"
#include "Hilera.h"
#include <iosfwd>
using namespace std;

FichaLudo::FichaLudo() {
    agregarAtributo("color",new Hilera(""));
    agregarAtributo("x",new Hilera("0"));
    agregarAtributo("activo",new Hilera("0"));
    agregarAtributo("finalizado",new Hilera("0"));
    agregarAtributo("pasosDados",new Hilera("0"));
    agregarAtributo("y",new Hilera("0"));
}

FichaLudo::~FichaLudo(){

}

FichaLudo::FichaLudo(std::string color, int zonaSegura ,int numeroFicha) {

    agregarAtributo("color",new Hilera(color));
    agregarAtributo("y",new Hilera(to_string(zonaSegura)));
    agregarAtributo("activo",new Hilera("0"));
    agregarAtributo("finalizado",new Hilera("0"));
    agregarAtributo("pasosDados",new Hilera("0"));
    agregarAtributo("zonaSegura",new Hilera(to_string(zonaSegura)));
    agregarAtributo("caminoFinal",new Hilera("0"));
    agregarAtributo("x",new Hilera("0"));
    agregarAtributo("numeroFicha",new Hilera(to_string(numeroFicha)));

}  

void FichaLudo::activarFicha() {
    agregarAtributo("activo",new Hilera("1"));
}

void FichaLudo::desactivarFicha() {
    agregarAtributo("activo",new Hilera("0"));
    agregarAtributo("y",new Hilera(
                    to_string(getZonaSegura())));
}

int FichaLudo::getZonaSegura() {
    std::string zonaSegura = "";
        Valor* valor = obtenerAtributo("zonaSegura");
        if (valor != nullptr) {
           zonaSegura = ((Hilera*) valor)->obt();
        }
        return stoi(zonaSegura);
}


void FichaLudo::setFinalizado(){
    agregarAtributo("finalizado",new Hilera("1"));
}

void FichaLudo::setEstadoActivo(){
    agregarAtributo("activo",new Hilera("1"));
}



