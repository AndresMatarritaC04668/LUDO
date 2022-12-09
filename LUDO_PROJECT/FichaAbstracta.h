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

#include <iostream>
#include <stdbool.h>
#include <string>
#include "Objeto.h"
#include "Hilera.h"
#include <iosfwd>
using namespace std;

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
        std::string getColor(){
          std::string color = "";
          Valor* valor = obtenerAtributo("color");
          if (valor != nullptr) {
              color = ((Hilera*) valor)->obt();
          }
          return color;

        }

        /**
         * @brief Obtiene un atributo "X" de la ficha, depende de la
         * implementación. Debe ser una variable numerica.
         * 
         * @return int Entero que representa el atributo X.
         */
        int getX(){
          std::string x = "";
          Valor* valor = obtenerAtributo("x");
          if (valor != nullptr) {
            x = ((Hilera*) valor)->obt();
          }
         return stoi(x);
        }

        /**
         * @brief Obtiene un atributo "Y" de la ficha, depende de la
         * implementación. Debe ser una variable numerica.
         * 
         * @return int Entero que representa el atributo Y.
         */
        int getY(){
          std::string y = "";
          Valor* valor = obtenerAtributo("y");
          if (valor != nullptr) {
              y = ((Hilera*) valor)->obt();
          }
          return stoi(y);
        }

        /**
         * @brief Devuelve el estado de la ficha en el juego. Indicado por un
         * entero.
         * 
         * @return int Indica el estado de la ficha en el juego. 
         */
        int getEstado(){
          std::string activo = "";
          Valor* valor = obtenerAtributo("activo");
          if (valor != nullptr) {
           activo = ((Hilera*) valor)->obt();
          }
          return stoi(activo);
        }

        /**
         * @brief Indica si una ficha llegó a la meta final.
         * 
         * @return true 
         * @return false 
         */
        bool getFinalizado(){
          std::string finalizado = "";
          Valor* valor = obtenerAtributo("finalizado");
          if (valor != nullptr) {
              finalizado = ((Hilera*) valor)->obt();
          }
          return stoi(finalizado);
        }

        /**
         * @brief Establece la posición de la ficha en el tablero.
         * 
         * @param x Posición en el eje x.
         * @param y Posición en el eje y.
         */
        void setPosicion(int x , int y){
          agregarAtributo("x",new Hilera(to_string(x)));
          agregarAtributo("y",new Hilera(to_string(y)));
        }
        
        /**
         * @brief Devuelve el número de ficha desde los atributos.
         * 
         * @return int El número de ficha.
         */
        int getNumeroFicha(){
            std::string numeroFicha = "";
            Valor* valor = obtenerAtributo("numeroFicha");
            if (valor != nullptr) {
              numeroFicha = ((Hilera*) valor)->obt();
            }
            return stoi(numeroFicha);
        }


        /**
         * @brief Establece el color de una ficha.
         * 
         * @param color Es el color que tendrá la ficha. Se guarda en atributos.
         */
        void setColor(std::string color){
          agregarAtributo("color",new Hilera(color));
        }

        /**
         * @brief Devuelve el número de pasos dados en el tablero por la ficha
         * desde los atributos.
         * 
         * @return int Los pasos dados.
         */
        int getPasosDados(){
          std::string pasosDados = "";
          Valor* valor = obtenerAtributo("pasosDados");
          if (valor != nullptr) {
              pasosDados = ((Hilera*) valor)->obt();
          }
          return stoi(pasosDados);
        }
        
        /**
         * @brief Establece los pasos dados por la ficha en los atributos.
         * 
         * @param pasosDados Los pasos que se guardaran en los atributos.
         */
        void setPasosDados(int pasosDados){
          agregarAtributo("pasosDados",new Hilera(to_string(pasosDados)));
        }

        /**
         * @brief Establece a una ficha en la meta final en sus atributos.
         * 
         */
        virtual void setFinalizado() = 0;
    protected:


};



#endif
