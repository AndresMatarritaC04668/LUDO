#include "ValidadorLudo.h"

/**
 * @brief Construct a new Validador Ludo:: Validador Ludo object
 * 
 */
ValidadorLudo::ValidadorLudo() {
  this->mesaLudo = NULL;
}

/**
 * @brief Construct a new Validador Ludo:: Validador Ludo object by arguments.
 * 
 * @param mesa 
 */
ValidadorLudo::ValidadorLudo(TableroAbstracto * mesa) {
  this->mesaLudo = dynamic_cast< TableroLudo * >(mesa);
}

/**
 * @brief Construct a new Validador Ludo:: Validador Ludo object
 * 
 * @param mesa 
 */
ValidadorLudo::ValidadorLudo(TableroLudo * mesa) {
  this->mesaLudo = mesa;
}

/**
 * @brief Clase que inicializa las reglas.
 * 
 */
void ValidadorLudo::iniciarReglas() {
}

/**
 * @brief Valida la jugada conforme a las reglas.
 * 
 * @param posicion La nueva posicion a la que tiene que llegar la ficha.
 * @param mover Es la ficha que se tiene que reubicar.
 * @return 2 Si hay una barrera. 3 Si hay otra ficha. 1 Si simplemente avanza.
 */
int ValidadorLudo::validarJugada(int posicion, FichaAbstracta * mover) {
  FichaLudo * fichaL = dynamic_cast< FichaLudo * >(mover);
  if (reglaOcho(posicion, fichaL) == false) {
    return 2;
  } else if (verifComer(posicion, fichaL) == true) {
    return 3;
  } else {
    return 1;
  }
}

/**
 * @brief Procedimiento que verifica si la regla 8 (la de la barrera) se esta
 * cumpliendo.
 * 
 * @param posicion La posicion hasta donde se debe mover la ficha.
 * @param mover La ficha que se debe mover
 * @return true Si se cumple la regla ocho.
 * @return false Si no se cumple la regla ocho.
 */
bool ValidadorLudo::reglaOcho(int posicion, FichaLudo * mover) {
  for (int i = mover->getPos() + 1; i <= posicion; ++i) {
    if (this->mesaLudo->tablero[0][i] != NULL &&
      this->mesaLudo->tablero[1][i] != NULL) {
      return false;
    }
  }
  return true;
}

/**
 * @brief Clase que verifica si se puede comer la ficha que se encuentra en una
 * posicion indicada por un numero entero.
 * 
 * @param posicion posicion en la que se podria encontrar una ficha.
 * @return true Si se puede comer.
 * @return false Si no se puede comer.
 */
bool ValidadorLudo::verifComer(int posicion, FichaLudo * mover) {
  // Este for compara, en este orden:
  // 1. Que la casilla a la que se va a llegar no este vacia.
  // 2. Que la ficha en esa casilla no este en zona segura.
  // 3. Que la ficha en esa casilla no sea del mismo color que la ficha que se
  // va a mover.
  for (int i = 0; i < 2; ++i) {
    if (this->mesaLudo->tablero[i][posicion] != NULL) {
      if (this->mesaLudo->tablero[i][posicion]->getPos() !=
        this->mesaLudo->tablero[i][posicion]->getZonaSegura()) {
          if (this->mesaLudo->tablero[i][posicion]->getColor().compare
            (mover->getColor()) != 0) {
              return true;
          }
      }
    }
  }
  return false;
}

/**
 * @brief Castea un tablero abstracto en un tablero de ludo.
 * 
 */
void ValidadorLudo::castTable() {
  if (this->mesaLudo != NULL && this->mesa != NULL){
    this->mesaLudo = dynamic_cast< TableroLudo * >(this->mesa);
  }
}

/**
 * @brief Setea el atributo de mesaLudo.
 * 
 * @param mesa El valor con lo que se llena el atributo de mesaLudo.
 */
void ValidadorLudo::setMesaLudo(TableroLudo * mesa) {
  this->mesaLudo = mesa;
}