/**
 * @file ConstructorSerializadorAbstracto.h
 * @authors Esteban José Mora García (C05126),
 * José Andrés Matarrita Miranda (C04668), Joseph Fernando Núñez Solano (C05582)
 * @brief Constructor abstracto para los serializadores de los juegos.
 * @version 0.1
 * @date 2022-11-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CONSTRUCTORSERIALIZADORABSTRACTO_H
#define CONSTRUCTORSERIALIZADORABSTRACTO_H

#include <string>
#include <utility>

#include "Valor.h"

class ConstructorSerializadorAbstracto
{
public:
	/**
	 * @brief Construct a new Constructor Serializador Abstracto object
	 * 
	 */
	ConstructorSerializadorAbstracto() {};

	/**
	 * @brief Destroy the Constructor Serializador Abstracto object
	 * 
	 */
	~ConstructorSerializadorAbstracto() {};

	/**
	 * @brief Inicia el objeto serializador dependiendo del formato.
	 * 
	 */
	virtual void inicioObjeto() = 0;

	/**
	 * @brief Agrega el fin del objeto serializador dependiendo del formato.
	 * 
	 */
	virtual void finObjeto() = 0;

	/**
	 * @brief Serializa la hilera de acuerdo con el formato, se utiliza un
	 * objeto par que contiene una string y un puntero a objeto Valor.
	 * Imprime según el orden que necesite la implementación específica.
	 * 
	 * @param ph Objeto par, el primero es una string, el segundo es un objeto
	 * Valor, por lo general, se espera que el contenido de este se pase a
	 * string para la serialización.
	 */
    virtual void serializarHilera(const std::pair< std::string, Valor* >& ph) = 0;
	
	/**
	 * @brief Devuelve la hilera que contiene la serialización en formato
	 * string. Crear una hilera en cada implementación.
	 * 
	 * @return std::string La string con la serialización.
	 */
	virtual std::string obtSerializacion() = 0;

	/**
	 * @brief Agrega el separador a la hilera de la serialización dependiendo de
	 * la implementación.
	 * 
	 */
    virtual void agregarSeparador() = 0;
};

#endif
