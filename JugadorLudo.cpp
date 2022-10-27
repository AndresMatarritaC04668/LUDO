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
        this->cantidadDados = 1;
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

    void JugadorLudo::moverFicha(FichaAbstracta * ficha,int pasos){
        FichaLudo * fichaLudo = dynamic_cast< FichaLudo *>(ficha);
        if(fichaLudo){
          pasos += fichaLudo->getPasosDados();
          fichaLudo->setPosicion(pasos);
        }
        
    }

    void JugadorLudo::crearFichas(int cantidadFichas){

        for(int i = 0 ; i < cantidadFichas ; i++){

            FichaLudo * ficha = new FichaLudo(this->color,0);

        }

    }

    int JugadorLudo::lanzarDado(){
        Dado  dado;
        int darPasos = 0;
        for(int i = 0 ; i<cantidadDados ; i++){
          darPasos+= dado.lanzar();
        }
        return darPasos;
    }

    FichaAbstracta * JugadorLudo::elegirFicha(){
       while(1){
         cout<< "Que numero de ficha desea elegir: 1,2,3 o 4";
         cout<< "\nDigite el numero de ficha que desea mover: ";
         int opcion = 0;
         cin>>opcion;
         
         if(opcion >=1 && opcion <=4 ){
            return fichas[opcion+1];
         } else {
            cout << "Numero de ficha incorrecto";
         }
       }
    }
