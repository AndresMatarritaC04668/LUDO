#include "SerializadorLudo.h"

SerializadorLudo::SerializadorLudo() {

}

SerializadorLudo::~SerializadorLudo() {

}

void SerializadorLudo::inicioObjeto() {
    this->serializacion = this->serializacion + "{";
}

void SerializadorLudo::finObjeto() {
    this->serializacion = this->serializacion + "}";
}

string SerializadorLudo::getSerializacion() {
    return this->serializacion;
}

void SerializadorLudo::agregarSeparador() {
    this->serializacion = this->serializacion + ",";
}

void SerializadorLudo::setJugadores(vector<Jugador *> jugadores) {
    for (int i=0; i<jugadores.size(); ++i)
        this->jugadores.push_back(dynamic_cast< JugadorLudo * >(jugadores[i]));
}



void SerializadorLudo::serializarJugadores() {
    int tam = this->jugadores.size();
    for (int i=0; i<tam; ++i) {
        JugadorLudo * actual = jugadores[i];
        serializacion += ("Jugador" + i+1 + " {\n");
        serializacion += (actual->getColor() + "\n");
        serializacion += (actual->getNombre() + "\n");

        serializarFicha(actual);

        serializacion += "}\n";
    }
}

void SerializadorLudo::serializarFicha(JugadorLudo * actual) {
    for (int j=0; j<4; ++j) {
        FichaLudo* fichaActual = actual->fichas[i];
        serializacion += ("Ficha" + j+1 + " { ");
        serializacion += (fichaActual->getPasosDados());
        agregarSeparador();
        serializacion += (" " + fichaActual->getEstado());
        agregarSeparador();
        serializacion += (" " + fichaActual->getFinalizado());
        agregarSeparador();
        serializacion += (" " + fichaActual->getZonaSegura());
        agregarSeparador();
        serializacion += (" " + fichaActual->getNumeroFicha());
        serializacion += "}\n";
    }
}

