/**
 * @file Hilera.h
 * @author Joseph Fernando Núñez Solano (C05582)
 * @brief Clase que implementa un objeto que funciona como hilera. Funciona con
 * una string.
 * @version 0.1
 * @date 2022-11-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef HILERA_H
#define	HILERA_H

#pragma once

#include <sstream>

#include "ObtAsg.h"
class Hilera : public ObtAsg< std::string >
{
public:
	/**
	 * @brief Construct a new Hilera object
	 * 
	 */
	Hilera();

	/**
	 * @brief Construct a new Hilera object by arguments.
	 * 
	 * @param v La string con la que se va a llenar la Hilera. Se guarda en el
	 * atributo valor.
	 */
	Hilera(std::string v);

	/**
	 * @brief Destroy the Hilera object
	 * 
	 */
	virtual ~Hilera();

	/**
	 * @brief Asigna una string pasada como argumento al atributo valor.
	 * 
	 * @param o La string con la que se va a llenar valor.
	 */
	virtual void asg(std::string o) override;

	/**
	 * @brief Devuelve la string que contiene la hilera, en este caso, el
	 * atributo valor.
	 * 
	 * @return std::string el atributo valor. 
	 */
	virtual std::string obt() const override;

	/**
	 * @brief Devuelve la enumeracion de la clase Hilera especificada en Tipo.
	 * 
	 * @return tipo::tipo_atributo El tipo de la Hilera es 0.
	 */
	virtual tipo::tipo_atributo obtTipo() const override;

	/**
	 * @brief Devuelve el atributo valor.
	 * 
	 * @return std::string El atributo valor.
	 */
    virtual std::string toString() const override;

private:
	std::string valor;
};

#endif
