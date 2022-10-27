#ifndef _JUGADOR_LUDO
#define _JUGADOR_LUDO
#include<iostream>
#include "Jugador.h"
using namespace std;
class JugadorLudo : Jugador {

    private:
        std::string nombre;
        std::vector<FichaAbstracta *> fichas;
        bool esGanador;
        string color;

    public :
        JugadorLudo();
        JugadorLudo(std::string nombre , string color);
        ~JugadorLudo();
        void setNombre(std::string nombre) override;
        std::string getNombre() override;
        std::vector<FichaAbstracta *> getFichas();
        bool getEsGanador()override;
        int lanzarDado(Dado* dado)override;
        void moverFicha(FichaAbstracta * ficha,int pasos) override;    
        void crearFichas(int cantidadFichas)override;  

};

#endif