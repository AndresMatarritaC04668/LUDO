/**
 * @file FichaLudo.h
 * @author Joseph Fernando Núñez Solano (C05582)
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
         * @brief Establece el color de una ficha.
         * 
         * @param color Es el color que tendrá la ficha. Se guarda en atributos.
         */
        void setColor(std::string)override;

        /**
         * @brief Devuelve el color de la ficha de los atributos.
         * 
         * @return std::string Indica el color de la ficha.
         */
        std::string getColor() override;

        /**
         * @brief Activa una ficha para sacarla de la carcel en LUDO.
         * 
         */
        void setEstadoActivo();

        /**
         * @brief Devuelve el estado de la ficha en el juego. Indicado por un
         * entero.
         * 
         * @return int Indica el estado de la ficha en el juego. 
         */
        int getEstado()override;

        /**
         * @brief Devuelve el valor entero del atributo X, inicia en la zona
         * segura.
         * 
         * @return int El atributo X.
         */
        int getX()override;

        /**
         * @brief Devuelve el valor entero del atributo Y, inicia en la zona
         * segura.
         * 
         * @return int El atributo Y.
         */
        int getY()override;

        /**
         * @brief Indica si una ficha llegó a la meta final.
         * 
         * @return true 
         * @return false 
         */
        bool getFinalizado()override;

        /**
         * @brief Devuelve el número de pasos dados en el tablero por la ficha
         * desde los atributos.
         * 
         * @return int Los pasos dados.
         */
        int getPasosDados()override;

        /**
         * @brief Devuelve la zona segura en los atributos de la ficha.
         * 
         * @return int La zona seguera de la ficha, dada como un número.
         */
        int getZonaSegura();

        /**
         * @brief Establece los pasos dados por la ficha en los atributos.
         * 
         * @param pasos Los pasos que se guardaran en los atributos.
         */
        void setPasosDados(int pasos);

        /**
         * @brief Establece la posición de la ficha en el tablero.
         * 
         * @param x Posición en el eje x.
         * @param y Posición en el eje y.
         */
        void setPosicion(int x,int y)override;

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
         * @brief Devuelve el número de ficha desde los atributos.
         * 
         * @return int El número de ficha.
         */
        int getNumeroFicha()override;

        /**
         * @brief Establece a una ficha en la meta final en sus atributos.
         * 
         */
        void setFinalizado()override;



};



#endif
