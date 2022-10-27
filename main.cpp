#include "TableroLUDO.h"
#include "FichaLudo.h"


int main(){
 
  TableroLudo * tablero = new TableroLudo();
  cout<<"   Nuevo tablero";
  int mover = tablero->lanzarDado();
  
  FichaLudo * ficha = new FichaLudo("AZUL",0);
  tablero->tablero[0][ficha->getPos()+mover%52] = ficha->getColor();
  for(int i = 0 ; i < 52 ; i++){

    cout<<  tablero->tablero[0][i] << tablero->tablero[1][i]<<endl;
  }

  return 0;
}