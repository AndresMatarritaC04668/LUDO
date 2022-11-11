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

std::string FichaLudo::getColor() {
    std::string color = "";
        Valor* valor = obtenerAtributo("color");
        if (valor != nullptr) {
            color = ((Hilera*) valor)->obt();
        }
        return color;
}

int FichaLudo::getX() {
    std::string x = "";
        Valor* valor = obtenerAtributo("x");
        if (valor != nullptr) {
            x = ((Hilera*) valor)->obt();
        }
        return stoi(x);;
}

int FichaLudo::getY() {
    std::string y = "";
        Valor* valor = obtenerAtributo("y");
        if (valor != nullptr) {
            y = ((Hilera*) valor)->obt();
        }
        return stoi(y);;
}

int FichaLudo::getEstado() {
    std::string activo = "";
        Valor* valor = obtenerAtributo("activo");
        if (valor != nullptr) {
            activo = ((Hilera*) valor)->obt();
        }
        return stoi(activo);
}

bool FichaLudo::getFinalizado() {
    std::string finalizado = "";
        Valor* valor = obtenerAtributo("finalizado");
        if (valor != nullptr) {
            finalizado = ((Hilera*) valor)->obt();
        }
        return stoi(finalizado);
}

void FichaLudo::setPasosDados(int pasosDados){
    agregarAtributo("pasosDados",new Hilera(to_string(pasosDados)));
}

void FichaLudo::setPosicion(int x , int y){
     agregarAtributo("x",new Hilera(to_string(x)));
     agregarAtributo("y",new Hilera(to_string(y)));

}

int FichaLudo::getPasosDados(){
    std::string pasosDados = "";
        Valor* valor = obtenerAtributo("pasosDados");
        if (valor != nullptr) {
            pasosDados = ((Hilera*) valor)->obt();
        }
        return stoi(pasosDados);;
}

int FichaLudo::getZonaSegura() {
    std::string zonaSegura = "";
        Valor* valor = obtenerAtributo("zonaSegura");
        if (valor != nullptr) {
           zonaSegura = ((Hilera*) valor)->obt();
        }
        return stoi(zonaSegura);
}

int FichaLudo::getNumeroFicha() {
    std::string numeroFicha = "";
        Valor* valor = obtenerAtributo("numeroFicha");
        if (valor != nullptr) {
           numeroFicha = ((Hilera*) valor)->obt();
        }
        return stoi(numeroFicha);
}

void FichaLudo::setFinalizado(){
    agregarAtributo("finalizado",new Hilera("1"));
}

void FichaLudo::setEstadoActivo(){
    agregarAtributo("activo",new Hilera("1"));
}

void FichaLudo::setColor(string color){
    agregarAtributo("color",new Hilera(color));
}


