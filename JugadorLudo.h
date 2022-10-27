#ifndef _JUGADOR_LUDO
#define _JUGADOR_LUDO
#include<iostream>
#include "Jugador.h"
using namespace std;
class JugadorLudo : Jugador {

    private:
        std::string nombre;
        bool esGanador;
        string color;
        std::vector<FichaAbstracta *> fichas;

    public :
        JugadorLudo();
        JugadorLudo(std::string nombre , string color);
        ~JugadorLudo();
        void setNombre(std::string nombre) override;
        std::string getNombre() override;
        std::vector<FichaAbstracta *> getFichas();
        bool getEsGanador()override;
        void moverFicha(FichaAbstracta * ficha,int pasos) override;    
        void crearFichas(int cantidadFichas)override; 
        int lanzarDado()override;
        FichaAbstracta * elegirFicha()override;

};

#endif