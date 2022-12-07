/**
 * @file Jugador.h
 * @authors Esteban José Mora García (C05126),
 * José Andrés Matarrita Miranda (C04668), Joseph Fernando Núñez Solano (C05582)
 * @brief Implementa el jugador abstracto como un heredero de Objeto.
 * @version 0.1
 * @date 2022-11-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _JUGADOR
#define _JUGADOR

#include "FichaAbstracta.h"
#include <vector>
#include <stdbool.h>
#include <iostream>
#include <qmessagebox.h>
#include "Hilera.h"
#include "Dado.h"

class TableroAbstracto;
using namespace std;

class Jugador :public Objeto{
    
    public:
        /**
         * @brief Construct a new Jugador object
         * 
         */
        Jugador() {}

        /**
         * @brief Destroy the Jugador object
         * 
         */
        virtual ~Jugador() {}

        /**
         * @brief Establece el nombre del jugador en sus atributos como una
         * string.
         * 
         * @param nombre La string que se guardara en los atributos.
         */
        void  setNombre(std::string nombre){
          agregarAtributo("nombre",new Hilera(nombre));
        }

        /**
         * @brief Devuelve el nombre del Jugador desde sus atributos.
         * 
         * @return std::string El nombre del jugador.
         */
        std::string getNombre(){
          std::string nombre = "";
          Valor* valor = obtenerAtributo("nombre");
            if (valor != nullptr) {
              nombre = ((Hilera*) valor)->obt();
            }
          return nombre;

        }

        /**
         * @brief Establece el color del jugador en sus atributos.
         * 
         * @param color La string que se guardara como el color en sus
         * atributos.
         */
        void  setColor(std::string color){
          agregarAtributo("color",new Hilera(color));
        }
        
        /**
         * @brief Devuelve el color desde sus atributos como una string.
         * 
         * @return std::string El color del jugador.
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
         * @brief Indica de alguna manera que si el jugador a ganado el juego
         * o no mediante un booleano.
         * 
         * @return true 
         * @return false 
         */
        bool getEsGanador(){
          return this->esGanador;
        }
        
        /**
         * @brief El jugador ejecuta la opcion de mover la ficha para el juego
         * que se este implementando.
         * 
         * @param ficha La ficha que se va a mover.
         * @param pasos Los pasos que se va a mover la ficha.
         * @param tablero El tablero en el que se va a mover la ficha.
         * @return int Depende del juego, podria indicar si un jugador tiene el
         * derecho a repetir el turno o no.
         */
        virtual int moverFicha(FichaAbstracta * ficha , int pasos, TableroAbstracto* tablero) = 0;
        
        /**
         * @brief El jugador elige la ficha que va a mover
         * 
         * @param TableroAbstracto* El tablero en el que se va a mover.
         * @param int los pasos que se va a mover.
         * @return FichaAbstracta* Debe devolver la ficha elegida.
         */
        virtual FichaAbstracta * elegirFicha(TableroAbstracto*,int) = 0;
        
        /**
         * @brief El jugador lanza el dado.
         * 
         * @return int El resultado de lanzar el dado.
         */
        int lanzarDado(){
          Dado  dado;
          int darPasos = 0;
          darPasos = dado.lanzar();

          return darPasos;
        }

        /**
         * @brief Establece las fichas del jugador.
         * 
         * @param vector<FichaAbstracta *> Lo guarda en el vector de fichas
         * abstractas que se tiene como atributo.
         */
        void setFichas(std::vector<FichaAbstracta *> fichas){
          this->fichas = fichas;
        }
        
        /**
         * @brief Devuelve el vector de fichas que se tiene como atributo.
         * 
         * @return std::vector<FichaAbstracta *> El atributo fichas.
         */
        std::vector<FichaAbstracta *> getFichas(){
          return this->fichas;
        }

        /**
         * @brief Da las opciones para el jugador en su turno segun el juego.
         * 
         * @param tablero El tablero en el que se esta jugando.
         * @return int La eleccion del jugador, siempre representada por un
         * valor numerico.
         */
        virtual int elegirQueHacer(TableroAbstracto* tablero) = 0;
        
        /**
         * @brief El jugador juega su turno.
         * 
         * @param tablero El tablero en el que se esta jugando.
         * @return int Un entero que funciona como booleano, se usa
         * principalmente adentro del metodo para determinar si el jugador debe
         * continuar su turno tras elegir su accion, pero el resultado se
         * devuelve independientemente.
         */
        int jugarTurno(TableroAbstracto* tablero){
          int repetirTurno = 1;
          int seguirJugando = 1;

          seguirJugando = elegirQueHacer(tablero);

          if(!seguirJugando){
              return seguirJugando;
          }
          while(repetirTurno == 1){
            int darPasos = lanzarDado();
            FichaAbstracta * ficha = elegirFicha(tablero,darPasos);
            repetirTurno = moverFicha(ficha , darPasos,tablero);
          }
          return seguirJugando;
        }

    protected:
      int esGanador;
      int cantidadDados;
      std::vector<FichaAbstracta *> fichas;


};


#endif
