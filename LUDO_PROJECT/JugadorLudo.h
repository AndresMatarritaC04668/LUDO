#ifndef _JUGADOR_LUDO
#define _JUGADOR_LUDO
#include<iostream>
#include "Jugador.h"
#include "tableroLUDO.h"
#include "TableroAbstracto.h"
#include "ValidadorLudo.h"
using namespace std;

class JugadorLudo : public Jugador {

    private:

        int esGanador;

        

    public :
        JugadorLudo(string color,int zonaSegura,string nombre);
        JugadorLudo();
        ~JugadorLudo()override;
        void setNombre(std::string nombre) override;
        std::string getNombre() override;
        bool getEsGanador()override;
        int moverFicha(FichaAbstracta * ficha, int pasos, TableroAbstracto* tablero) override;    
        int lanzarDado()override;
        FichaAbstracta * elegirFicha(TableroAbstracto*,int)override;
        int encontrarBarrera(int posicion, FichaLudo * mover, TableroLudo* tablero);
        string getColor()override;
        void setColor(std::string nombre)override;
        void moverFichaRectaFinal(FichaLudo * ficha, int pasos, TableroLudo* tablero , ValidadorLudo * validador);
        std::vector<FichaAbstracta *> getFichas() override;
        int elegirQueHacer(TableroAbstracto* tablero)override;
        void setFichas(std::vector<FichaAbstracta *>) override;


};

#endif
