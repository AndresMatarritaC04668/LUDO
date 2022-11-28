/**
 * @file Valor.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef Valor_H
#define	Valor_H

#include "tipo.h"
#include <string>

class Valor
{
public:
	/**
	 * @brief Construct a new Valor object
	 * 
	 */
	Valor() {};

	/**
	 * @brief Destroy the Valor object
	 * 
	 */
	virtual ~Valor() {};

	/**
	 * @brief Devuelve el tipo de objeto heredero. Es una enumeracion.
	 * 
	 * @return tipo::tipo_atributo La enumeracion del tipo.
	 */
	virtual tipo::tipo_atributo obtTipo() const = 0;

	/**
	 * @brief Devuelve como string el contenido del objeto heredero.
	 * 
	 * @return std::string El contenido del objeto heredero.
	 */
	virtual std::string toString() const = 0;
};
#endif
