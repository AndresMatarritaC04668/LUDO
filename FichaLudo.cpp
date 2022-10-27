#include <iostream>
#include "FichaLudo.h"

FichaLudo::FichaLudo() {
    this->color = "";
    this->pos = 0;
    this->activo = 0;
    this->finalizado = 0;
    this->pasosDados = 0;
}

FichaLudo::FichaLudo(std::string color, int pos, int estado) {
    this->color = color;
    this->pos = pos;
    this->activo = estado;
    this->finalizado = false;
    this->pasosDados = 0;
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

