#include "Regla.h"

Regla::Regla() {
    this->nombre = "";
}

Regla::Regla(string nombre) {
    this->nombre = nombre;
}

Regla::~Regla() {
}

void Regla::setNombre(string nombre) {
    this->nombre = nombre;
}

string Regla::obtenerNombre() {
    return this->nombre;
}