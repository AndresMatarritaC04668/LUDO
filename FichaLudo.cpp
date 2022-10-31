#include <iostream>
#include "FichaLudo.h"

FichaLudo::FichaLudo() {
    this->color = "";
    this->x = 0;
    this->activo = 0;
    this->finalizado = 0;
    this->pasosDados = 0;
    this->y = 0;
}

FichaLudo::FichaLudo(std::string color, int zonaSegura ,int numeroFicha) {
    this->color = color;
    this->y = zonaSegura; // posicion = zonasegura
    this->activo = false;  // cambiar false
    this->finalizado = false; 
    this->pasosDados = 0; // cambiar = 0
    this->zonaSegura = zonaSegura; 
    this->caminoFinal = 0;
    this->x = 0;
    this->numeroFicha = numeroFicha;
}  

void FichaLudo::activarFicha() {
    this->activo = true;
}

void FichaLudo::desactivarFicha() {
    this->activo = false;
    this->y =  zonaSegura;
}

std::string FichaLudo::getColor() {
    return this->color;
}

int FichaLudo::getX() {
    return this->x;
}

int FichaLudo::getY() {
  
    return this->y;
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

void FichaLudo::setPosicion(int x , int y){
     this->x = x;
     this->y = y;
}

int FichaLudo::getPasosDados(){
    return this->pasosDados;
}

int FichaLudo::getZonaSegura() {
    return this->zonaSegura;
}

int FichaLudo::getNumeroFicha() {
    return this->numeroFicha;
}

void FichaLudo::setFinalizado(){
    this->finalizado = 1;
}

