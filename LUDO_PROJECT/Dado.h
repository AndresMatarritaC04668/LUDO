/**
 * @file Dado.h
 * @author Joseph Fernando Núñez Solano (C05582)
 * @brief Clase que implementa un dado de seis caras.
 * @version 0.1
 * @date 2022-11-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _DADO
#define _DADO

#include <stdlib.h>
#include <string>
#include <time.h>


class Dado {


    public:
        /**
         * @brief Construct a new Dado object
         * 
         */
        Dado(){
            srand(time(NULL));
        }
        
        /**
         * @brief Lanza un dado y genera un numero aleatorio.
         * 
         * @return int Un numero entero del 1 al 6.
         */
        int lanzar() {
            return (1 + rand() % (7 - 1));
        }

};



#endif