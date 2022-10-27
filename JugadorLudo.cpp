#include "JugadorLudo.h"
#include "FichaLudo.h"
    
    JugadorLudo::JugadorLudo() {
        this->nombre = "";
        this->esGanador = false;
   }

    JugadorLudo::JugadorLudo(std::string nombre , string color) {
        this->setNombre(nombre);
        this->esGanador = false;
        this->color = color;
    }

    JugadorLudo::~JugadorLudo() {
            for (auto i: fichas)
                delete i;
        }

    void JugadorLudo::setNombre(std::string nombre) {
            this->nombre = nombre;
        }

    std::string JugadorLudo:: getNombre() {
            return this->nombre;
        }

    std::vector<FichaAbstracta *> JugadorLudo:: getFichas() {  // no override
            return this->fichas;
        }

    bool JugadorLudo::getEsGanador() {
            return this->esGanador;
        }

    int  JugadorLudo::lanzarDado(Dado* dado) {
            return dado->lanzar();
    }

    void JugadorLudo::moverFicha(FichaAbstracta * ficha,int pasos){

    }

    void JugadorLudo::crearFichas(int cantidadFichas){

        for(int i = 0 ; i < cantidadFichas ; i++){

            FichaLudo * ficha = new FichaLudo(this->color,0,0);

        }

    }