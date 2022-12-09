/**
 * @file FichaLudo.h
 * @authors Esteban José Mora García (C05126),
 * José Andrés Matarrita Miranda (C04668), Joseph Fernando Núñez Solano (C05582)
 * @brief Implementación de las fichas para el juego de LUDO.
 * @version 0.1
 * @date 2022-11-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _FICHA_LUDO
#define _FICHA_LUDO

#include <stdbool.h>
#include <string>
#include "FichaAbstracta.h"

class FichaLudo : public FichaAbstracta {

    private:
        //std::string color;
        //bool activo;
        //int pasosDados;
        //int zonaSegura;
        //int caminoFinal;
        //int numeroFicha;
        

    public:
        /**
         * @brief Construct a new Ficha Ludo object
         * 
         */
        FichaLudo();

        /**
         * @brief Construct a new Ficha Ludo object by arguments.
         * 
         * @param color Agrega el color a los atributos.
         * @param zonaSegura Agrega la zona segura a los atributos.
         * @param numeroFicha Agrega el número de la ficha a los atributos.
         */
        FichaLudo(std::string, int,int);

        /**
         * @brief Destroy the Ficha Ludo object
         * 
         */
        ~FichaLudo()override;
        

        /**
         * @brief Activa una ficha para sacarla de la carcel en LUDO.
         * 
         */
        void setEstadoActivo();


        /**
         * @brief Devuelve la zona segura en los atributos de la ficha.
         * 
         * @return int La zona seguera de la ficha, dada como un número.
         */
        int getZonaSegura();

        /**
         * @brief Pone a la ficha en estado activo en sus atributos.
         * 
         */
        void activarFicha();

        /**
         * @brief Pone a la ficha en estado inactivo en sus atributos.
         * 
         */
        void desactivarFicha();


        /**
         * @brief Establece a una ficha en la meta final en sus atributos.
         * 
         */
        void setFinalizado()override;

};



#endif
