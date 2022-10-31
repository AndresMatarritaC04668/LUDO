#include "TableroLUDO.h"
#include "FichaLudo.h"


int main(){
  //Simulacion controlador


  // Crear tablero
  TableroLudo * tablero = new TableroLudo();


  // AsignarCantidadJugadores
  tablero->asignarCantidadJugadores(4);

  // UbicarJugadores
  tablero->ubicarJugadores(); 

  // asignamos primerJugador
  tablero->asignarPrimerJugador();

  // ComenzarJuego
  tablero->iniciarPartida();
  

  return 0;
}