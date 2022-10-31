#ifndef _JUGADOR_LUDO
#define _JUGADOR_LUDO
#include<iostream>
#include "Jugador.h"
#include "tableroLUDO.h"
#include "TableroAbstracto.h"
using namespace std;

class JugadorLudo : public Jugador {

    private:
        std::string nombre;
        int esGanador;
        string color;
        

    public :
        JugadorLudo(string color,int zonaSegura);
        JugadorLudo();
        JugadorLudo(std::string nombre , string color);
        ~JugadorLudo();
        void setNombre(std::string nombre) override;
        std::string getNombre() override;
        std::vector<FichaAbstracta *> getFichas();
        bool getEsGanador()override;
        int moverFicha(FichaAbstracta * ficha, int pasos, TableroAbstracto* tablero) override;    
        void crearFichas(int cantidadFichas)override; 
        int lanzarDado()override;
        FichaAbstracta * elegirFicha()override;
        int encontrarBarrera(int posicion, FichaLudo * mover, TableroLudo* tablero);

};

#endif