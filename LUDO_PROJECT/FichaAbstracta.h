/**
 * @file FichaAbstracta.h
 * @authors Esteban José Mora García (C05126),
 * José Andrés Matarrita Miranda (C04668), Joseph Fernando Núñez Solano (C05582)
 * @brief Implementación abstracta para las fichas de los juegos.
 * @version 0.1
 * @date 2022-11-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _FICHAABSTRACTA
#define _FICHAABSTRACTA

#include <stdbool.h>
#include <string>
#include "Objeto.h"

class FichaAbstracta : public Objeto{

    public:
        /**
         * @brief Construct a new Ficha Abstracta object
         * 
         */
        FichaAbstracta(){};

        /**
         * @brief Destroy the Ficha Abstracta object
         * 
         */
        virtual ~FichaAbstracta(){};

        /**
         * @brief Devuelve el color de la ficha de los atributos.
         * 
         * @return std::string Indica el color de la ficha.
         */
        virtual std::string getColor() = 0;

        /**
         * @brief Obtiene un atributo "X" de la ficha, depende de la
         * implementación. Debe ser una variable numerica.
         * 
         * @return int Entero que representa el atributo X.
         */
        virtual int getX() = 0;

        /**
         * @brief Obtiene un atributo "Y" de la ficha, depende de la
         * implementación. Debe ser una variable numerica.
         * 
         * @return int Entero que representa el atributo Y.
         */
        virtual int getY() =0;

        /**
         * @brief Devuelve el estado de la ficha en el juego. Indicado por un
         * entero.
         * 
         * @return int Indica el estado de la ficha en el juego. 
         */
        virtual int getEstado() = 0;

        /**
         * @brief Indica si una ficha llegó a la meta final.
         * 
         * @return true 
         * @return false 
         */
        virtual bool getFinalizado() = 0;

        /**
         * @brief Establece la posición de la ficha en el tablero.
         * 
         * @param x Posición en el eje x.
         * @param y Posición en el eje y.
         */
        virtual void setPosicion(int x , int y) = 0;
        
        /**
         * @brief Devuelve el número de ficha desde los atributos.
         * 
         * @return int El número de ficha.
         */
        virtual int getNumeroFicha() = 0;

        /**
         * @brief Devuelve el número de pasos dados en el tablero por la ficha
         * desde los atributos.
         * 
         * @return int Los pasos dados.
         */
        virtual int getPasosDados()=0;

        /**
         * @brief Establece el color de una ficha.
         * 
         * @param color Es el color que tendrá la ficha. Se guarda en atributos.
         */
        virtual void setColor(std::string) = 0;

        /**
         * @brief Establece a una ficha en la meta final en sus atributos.
         * 
         */
        virtual void setFinalizado() = 0;
    protected:


};



#endif
