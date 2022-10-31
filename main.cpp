#include "TableroLUDO.h"
#include "FichaLudo.h"
#include "ControladorLudo.h"


int main(){
  //Simulacion controlador
  ControladorLudo * controlador = new ControladorLudo();
  controlador->asignarCantidadJugadores();
  controlador->ubicarJugadores();
  controlador->asignarPrimerJugador();
  controlador->iniciarPartida();


 
  /*
  // Crear tablero()=
   TableroLudo * tablero = new TableroLudo();


  // AsignarCantidadJugadores
  tablero->asignarCantidadJugadores(4);

  // UbicarJugadores
  tablero->ubicarJugadores(); 

  // asignamos primerJugador
  tablero->asignarPrimerJugador();

  // ComenzarJuego
  tablero->iniciarPartida();
  
 */
  return 0;
}