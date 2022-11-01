#include "Regla.h"

/**
 * @brief Constructor por omision de Regla.
 * 
 */
Regla::Regla() {
    this->nombre = "";
}

/**
 * @brief Constructor por parametros de Regla.
 * 
 * @param nombre El contenido de la regla.
 */
Regla::Regla(string nombre) {
    this->nombre = nombre;
}

/**
 * @brief Destroy the Regla:: Regla object
 * 
 */
Regla::~Regla() {
}

/**
 * @brief Setea el atributo nombre con una string dada por parametro.
 * 
 * @param nombre La string dada por parametro.
 */
void Regla::setNombre(string nombre) {
    this->nombre = nombre;
}

/**
 * @brief Devuelve el atributo nombre.
 * 
 * @return string El atributo nombre.
 */
string Regla::obtenerNombre() {
    return this->nombre;
}