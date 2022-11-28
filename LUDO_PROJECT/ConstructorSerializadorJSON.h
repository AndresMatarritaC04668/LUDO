/**
 * @file ConstructorSerializadorJSON.h
 * @author Joseph Fernando Núñez Solano (C05582)
 * @brief Construye el serializador de los juegos en relación al formato JSON.
 * @version 0.1
 * @date 2022-11-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CONSTRUCTORSERIALIZADORJSON_H
#define CONSTRUCTORSERIALIZADORJSON_H

#pragma once

#include <sstream>

#include "ConstructorSerializadorAbstracto.h"
#include "Valor.h"
class ConstructorSerializadorJSON : public ConstructorSerializadorAbstracto
{
public:
	/**
	 * @brief Construct a new Constructor Serializador J S O N object
	 * 
	 */
	ConstructorSerializadorJSON();

	/**
	 * @brief Destroy the Constructor Serializador J S O N object
	 * 
	 */
	~ConstructorSerializadorJSON();

	/**
	 * @brief Inicia el objeto serializador en acordancia al formato JSON.
	 * 
	 */
	virtual void inicioObjeto() override;

	/**
	 * @brief Finaliza el objeto serializador en acordancia al formato JSON.
	 * 
	 */
	virtual void finObjeto() override;

	/**
	 * @brief Serializa la hilera de acuerdo al formato JSON, se utiliza un
	 * objeto par que contiene una string y un puntero a objeto Valor.
	 * Imprime según el orden que necesite la implementación específica.
	 * 
	 * @param ph Objeto par, el primero es una string, el segundo es un objeto
	 * Valor, por lo general, se espera que el contenido de este se pase a
	 * string para la serialización.
	 */
	virtual void serializarHilera(const std::pair< std::string, Valor* >& ph) override;

	/**
	 * @brief Devuelve el atributo serializacion.
	 * 
	 * @return std::string El atributo serializacion.
	 */
	virtual std::string obtSerializacion() override;
    
	/**
	 * @brief Agrega el separador de acuerdo al formato JSON.
	 * 
	 */
	virtual void agregarSeparador() override;

	// String que contiene la serialización.
    std::string serializacion;

private:

};

#endif
