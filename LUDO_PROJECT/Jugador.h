#ifndef _JUGADOR
#define _JUGADOR

#include "Dado.h"
#include "FichaAbstracta.h"
#include <vector>
#include <stdbool.h>
#include <iostream>

class TableroAbstracto;
using namespace std;

class Jugador {
    
    public:
        Jugador() {}

        ~Jugador() {}

        virtual void  setNombre(std::string nombre) = 0;
        virtual std::string getNombre() = 0;
        virtual bool getEsGanador() = 0;
        virtual void crearFichas(int) = 0;
        virtual int moverFicha(FichaAbstracta * ficha , int pasos, TableroAbstracto* tablero) = 0;
        virtual FichaAbstracta * elegirFicha(TableroAbstracto*,int) = 0;
        virtual int lanzarDado(TableroAbstracto*) = 0;
        virtual std::vector<FichaAbstracta *> getFichas() = 0;

        int jugarTurno(TableroAbstracto* tablero){
          int repetirTurno = 1;

          while(repetirTurno == 1){
            int darPasos = lanzarDado(tablero);
            FichaAbstracta * ficha = elegirFicha(tablero,darPasos);
            repetirTurno = moverFicha(ficha , darPasos,tablero);
          }
          return repetirTurno;
        }     

    protected:
       int cantidadDados;
       std::vector<FichaAbstracta *> fichas;

};


#endif
