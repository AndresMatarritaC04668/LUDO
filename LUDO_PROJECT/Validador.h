/**
 * @file Validador.h
 * @authors Esteban José Mora García (C05126),
 * José Andrés Matarrita Miranda (C04668), Joseph Fernando Núñez Solano (C05582)
 * @brief Clase plantilla que representa un validador.
 * @version 0.1
 * @date 2022-11-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef VALIDADOR_27OCT22
#define VALIDADOR_27OCT22

#include <vector>
#include "Regla.h"
#include "TableroAbstracto.h"
#include "Jugador.h"
#include "FichaAbstracta.h"

using namespace std;

class TableroAbstracto;

class Validador {
  protected:
    vector<Regla *> reglas;
    TableroAbstracto * mesa;
  
  public:

    /**
     * @brief Construct a new Validador object
     * 
     */
    Validador(){};

    /**
     * @brief Construct a new Validador object by arguments.
     * 
     * @param mesa Un objeto tablero abstracto que se va a asignar en el
     * atributo mesa.
     */
    Validador(TableroAbstracto * mesa){
      this->mesa = mesa;
    }

    /**
     * @brief Destroy the Validador object
     * 
     */
    ~Validador() {
      int reglasSize = this->reglas.size();
      for (int i = 0; i < reglasSize; ++i) {
        delete this->reglas[i];
      }
    }

    /**
     * @brief Metodo que inicializa las reglas.
     * 
     */
    virtual void iniciarReglas() = 0;
    // virtual void validarReglas(string tablero[2][52]) = 0;

    /**
     * @brief Valida la jugada conforme a las reglas.
     * 
     * @param posicion La nueva posicion a la que tiene que llegar la ficha.
     * @param mover Es la ficha que se tiene que reubicar.
     * @return Un valor numero que representa un caso especifico.
     */
    virtual int validarJugada(int posicion, FichaAbstracta * mover) = 0;
    // En LUDO: Verificar bloqueo.

    /**
     * @brief Devuelve un vector con objetos regla. Estos contienen las strings
     * con las reglas.
     * 
     * @return vector<Regla *>* El artributo reglas.
     */
    vector<Regla *> * obtenerReglas() { return &reglas; };

    /**
     * @brief Devuelve una string con todas las reglas separadas por un cambio
     * de linea.
     * 
     * @return string La hilera con las reglas.
     */
    virtual string toStringReglas() = 0;

    /**
     * @brief Se usa al final de cada turno, determina si algun ganador ya
     * consiguio ganar el juego.
     * 
     * @param fichas Un vector con las fichas del juego.
     * @return int 1 si es ganador, 0 si no lo es.
     */
    virtual int esGanador(std::vector<FichaAbstracta *>) = 0;
};

#endif