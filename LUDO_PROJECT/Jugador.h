#ifndef _JUGADOR
#define _JUGADOR

#include "Dado.h"
#include "FichaAbstracta.h"
#include <vector>
#include <stdbool.h>
#include <iostream>
#include <qmessagebox.h>
using namespace std;
class TableroAbstracto;
using namespace std;

class Jugador {
    
    public:
        Jugador() {}

        virtual ~Jugador() {}

        virtual void  setNombre(std::string nombre) = 0;
        virtual std::string getNombre() = 0;
        virtual bool getEsGanador() = 0;
        virtual int moverFicha(FichaAbstracta * ficha , int pasos, TableroAbstracto* tablero) = 0;
        virtual FichaAbstracta * elegirFicha(TableroAbstracto*,int) = 0;
        virtual int lanzarDado() = 0;
        virtual std::vector<FichaAbstracta *> getFichas() = 0;
        virtual int elegirQueHacer(TableroAbstracto* tablero) = 0;
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
       int cantidadDados;
       std::vector<FichaAbstracta *> fichas;
       string color;
       std::string nombre;

};


#endif
