/**
 * @file DeserializadorAbstracto.h
 * @author Joseph Fernando Núñez Solano (C05582)
 * @brief Clase que implementa el deserializador abstracto para los
 * deserializadores de los juegos.
 * @version 0.1
 * @date 2022-11-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DeserializadorAbstracto_h
#define DeserializadorAbstracto_h

#include <stdio.h>
#include <string>
#include <map>
#include "Valor.h"
#include <vector>

class DeserializadorAbstracto {
public:
    /**
     * @brief Construct a new Deserializador Abstracto object
     * 
     */
    DeserializadorAbstracto() {};

    /**
     * @brief Destroy the Deserializador Abstracto object
     * 
     */
    ~DeserializadorAbstracto() {};

    /**
     * @brief Deserializa un objeto en relación al formato que se esté
     * implementando.
     * 
     * @param string La string con la información del objeto serializada.
     * @return std::map< std::string, Valor*> Este par contiene la información
     * deserializada es un objeto en particular, debe implementarse en relación
     * al formato escogido.
     */
    virtual std::map< std::string, Valor*> deserializarObjeto(std::string) = 0;

    /**
     * @brief Deserializa todos los objetos en la hilera serializada que se pasa
     * por parametro y los guarda en un vector de objetos map cuya key es una
     * string y su contenido es un puntero a un objeto Valor. Continuar
     * deserializando los objetos de la hilera hasta que esta se termine. Usar
     * la implementación particular adecuada.
     * 
     * @param string La hilera con la información de los objetos serializada.
     * @return std::vector<std::map< std::string, Valor* >> Este vector contiene
     * la información de todos los objetos de la hilera deserializados.
     */
    virtual std::vector<std::map< std::string, Valor* >> deserializarListaObjetos(std::string) = 0;
    
protected:
    /**
     * @brief Elimina el inicio y el fin de un objeto de acuerdo con el formato
     * que se esté utilizando.
     * 
     * @param string Es la hilera en un formato particular a la que se le va a
     * eliminar su inicio y su fin.
     */
    virtual void eliminarInicioFinObjeto(std::string&) = 0;

    /**
     * @brief Extrae la "Llave mayor" de la hilera proveída. La llave mayor es
     * diferente dependiendo del formato y se utiliza normalmente con cada
     * objeto.
     * 
     * @param string La string a la que hay que extraerle la llave mayor.
     * @return std::pair<std::string, Valor*> El par construído con la
     * información del objeto deserializado. Pensado para ser regresado a
     * deserializarObjeto(), así que hay que usar la misma lógica.
     */
    virtual std::pair<std::string, Valor*> extraerLlaveValor(std::string) = 0;
};

#endif /* DeserializadorJSON_h */
