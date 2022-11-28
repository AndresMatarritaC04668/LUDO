/**
 * @file Objeto.h
 * @author Joseph Fernando Núñez Solano (C05582)
 * @brief Implementa un objeto abstracto para ser utilizado en los juegos. Tiene
 * sus propios atributos.
 * @version 0.1
 * @date 2022-11-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef Objeto_h
#define Objeto_h

#include <map>
#include "Valor.h"
#include <vector>

class Objeto {
public:
    /**
     * @brief Construct a new Objeto object
     * 
     */
    Objeto();

    /**
     * @brief Destroy the Objeto object
     * 
     */
    ~Objeto();

    /**
     * @brief Guarda los atributos del objeto en un vector de valores compuesto
     * por un par de string y objeto Valor.
     * 
     * @param vectorValores El vector en el que se van a guardar los atributos
     * del objeto.
     */
    void obtAtributos(std::vector< std::pair< std::string, Valor* > >& vectorValores);

    // Define un tipo especial de objeto map.
    typedef std::map< std::string, Valor* > map_atributos;
    
    /**
     * @brief Establece los atributos de un objeto map_atributos dado.
     * 
     * @param atributos Se van a guardar en los atributos del objeto.
     */
    void setAtributos(map_atributos);
protected:
    /**
     * @brief Agrega un atributo al map.
     * 
     * @param nombre El del atributo. Se usa como key.
     * @param valor El contenido del atributo.
     */
    void agregarAtributo(std::string, Valor*);

    /**
     * @brief Recupera el valor de un atributo usando su nombre como llave.
     * 
     * @param nombre El nombre del atributo para buscarlo en el map.
     * @return Valor* El contenido del atributo.
     */
    Valor* obtenerAtributo(std::string);
private:
    map_atributos atributos;
};

#endif
