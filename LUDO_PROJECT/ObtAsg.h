/**
 * @file ObtAsg.h
 * @authors Esteban José Mora García (C05126),
 * José Andrés Matarrita Miranda (C04668), Joseph Fernando Núñez Solano (C05582)
 * @brief Implementacion de un objeto con un valor asignado.
 * @version 0.1
 * @date 2022-11-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef OBTASG_H
#define OBTASG_H

#include "Valor.h"

template < typename T >
class ObtAsg : public Valor
{
public:
    /**
     * @brief Construct a new Obt Asg object
     * 
     */
    ObtAsg() {};

    /**
     * @brief Destroy the Obt Asg object
     * 
     */
    virtual ~ObtAsg() {};

    /**
     * @brief Asigna un objeto dado por parametro a una clase heredera.
     * 
     * @param o El objeto dado.
     */
    virtual void asg(T o) = 0;

    /**
     * @brief Devuelve un objeto atributo de la clase heredera. Comunmente el
     * objetino mediante el metodo de asg().
     * 
     * @return T El atributo en interes.
     */
    virtual T obt() const = 0;
};

#endif
