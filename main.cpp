#include "TableroLUDO.h"
#include "FichaLudo.h"
#include "Validador.h"
#include "ValidadorLudo.h"

int main(){
  //Simulacion controlador


  // Crear tablero
  TableroLudo * tablero = new TableroLudo();


  // AsignarCantidadJugadores
  tablero->asignarCantidadJugadores(4);

  // UbicarJugadores
  tablero->ubicarJugadores(); 

  // asignamos primerJugador


  // ComenzarJuego

  

  return 0;
}