#include <iostream>
#include "FichaLudo.h"

FichaLudo::FichaLudo() {
    this->color = "";
    this->pos = 0;
    this->activo = 0;
    this->finalizado = 0;
    this->pasosDados = 0;
}

FichaLudo::FichaLudo(std::string color, int zonaSegura) {
    this->color = color;
    this->pos = zonaSegura; // posicion = zonasegura
    this->activo = false;  // cambiar false
    this->finalizado = false; 
    this->pasosDados = 0; // cambiar = 0
    this->zonaSegura = zonaSegura; 
    this->caminoFinal = 0;
}  

std::string FichaLudo::getColor() {
    return this->color;
}

int FichaLudo::getPos() {
    return this->pos;
}

int FichaLudo::getEstado() {
    return this->activo;
}

bool FichaLudo::getFinalizado() {
    return this->finalizado;
}

void FichaLudo::setPasosDados(int pasosDados){
    this->pasosDados = pasosDados;
}

void FichaLudo::setPosicion(int posicion){
     this->pos = posicion;
}

int FichaLudo::getPasosDados(){
    return this->pasosDados;
}

int FichaLudo::getZonaSegura() {
    return this->zonaSegura;
}

