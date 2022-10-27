#ifndef _JUGADOR
#define _JUGADOR

#include "Dado.h"
#include "FichaAbstracta.h"
#include <vector>
#include <stdbool.h>


class Jugador {
    
    public:
        Jugador() {}

        ~Jugador() {}

        virtual void  setNombre(std::string nombre) = 0;

        virtual std::string getNombre() = 0;

        virtual bool getEsGanador() = 0;

        virtual int lanzarDado(Dado* dado) = 0;

        virtual void crearFichas(int) = 0;

        virtual void moverFicha(FichaAbstracta * ficha , int pasos) = 0;

};


#endif