/**
 * @file DeserializadorJSON.h
 * @author Joseph Fernando Núñez Solano (C05582)
 * @brief Deserializa una hilera serializada de acuerdo al formato JSON.
 * @version 0.1
 * @date 2022-11-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DeserializadorJSON_h
#define DeserializadorJSON_h

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include "Valor.h"
#include "DeserializadorAbstracto.h"

class DeserializadorJSON : public DeserializadorAbstracto {
public:
    /**
     * @brief Construct a new Deserializador J S O N object
     * 
     */
    DeserializadorJSON();

    /**
     * @brief Destroy the Deserializador J S O N object
     * 
     */
    ~DeserializadorJSON();

    /**
     * @brief Deserializa un objeto específico de acuerdo al formato JSON.
     * 
     * @param stringJSON La string con la información del objeto serializada.
     * @return std::map< std::string, Valor*> Este par contiene la información
     * deserializada es un objeto en particular, implementada de acuerdo al
     * formato JSON.
     */
    std::map< std::string, Valor*> deserializarObjeto(std::string) override;
    
    /**
     * @brief Deserealiza todos los objetos en una hilera de acuerdo al formato
     * JSON.
     * 
     * @param listaJSON La hilera con la información de los objetos serializada.
     * @return std::vector<std::map< std::string, Valor* >> Este vector contiene
     * la información de todos los objetos de la hilera deserializados.
     */
    std::vector<std::map< std::string, Valor* >> deserializarListaObjetos(std::string) override;
protected:
    /**
     * @brief Elimina el inicio y fin de un objeto en una hilera serializada de
     * acuerdo a los estándares del formato JSON.
     * 
     * @param string Es la hilera en un formato particular a la que se le va a
     * eliminar su inicio y su fin.
     */
    void eliminarInicioFinObjeto(std::string&) override;

    /**
     * @brief Extrae la llave mayor del formato JSON, ":".
     * 
     * @param string La string a la que hay que extraerle la llave mayor.
     * @return std::pair<std::string, Valor*> El par construído con la
     * información del objeto deserializado. Pensado para ser regresado a
     * deserializarObjeto(), así que hay que usar la misma lógica.
     */
    std::pair<std::string, Valor*> extraerLlaveValor(std::string) override;
private:
    // Atributo delimitador del formato JSON.
    std::string const delimitadorAtributo = ",";

    // Llave Valor del formato JSON.
    std::string const delimitadorLlaveValor = ":";
};

#endif /* DeserializadorJSON_h */
