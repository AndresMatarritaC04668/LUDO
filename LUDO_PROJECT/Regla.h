/**
 * @file Regla.h
 * @authors Esteban José Mora García (C05126),
 * José Andrés Matarrita Miranda (C04668), Joseph Fernando Núñez Solano (C05582)
 * @brief Clase que define un objeto regla.
 * @version 0.1
 * @date 2022-11-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef REGLA_27OCT22
#define REGLA_27OCT22

#include <string>

using namespace std;

class Regla {
  private:
    string nombre;

  public:

    /**
     * @brief Constructor por omision de Regla.
     * 
     */
    Regla();
  
    /**
     * @brief Constructor por parametros de Regla.
     * 
     * @param nombre El contenido de la regla.
     */
    Regla(string);

    /**
     * @brief Destroy the Regla:: Regla object
     * 
     */
    ~Regla();

    /**
     * @brief Setea el atributo nombre con una string dada por parametro.
     * 
     * @param nombre La string dada por parametro.
     */
    void setNombre(string);
    
    /**
     * @brief Devuelve el atributo nombre.
     * 
     * @return string El atributo nombre.
     */
    string obtenerNombre();
};

#endif