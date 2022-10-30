#include "JugadorLudo.h"
#include "FichaLudo.h"
#include "ValidadorLudo.h"
    
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

    JugadorLudo::JugadorLudo(string color,int zonaSegura){
        this->cantidadDados = 1;
        FichaLudo * ficha1 = new FichaLudo(color,zonaSegura);
        fichas.push_back(ficha1);
        FichaLudo * ficha2 = new FichaLudo(color,zonaSegura);
        fichas.push_back(ficha2);
        FichaLudo * ficha3 = new FichaLudo(color,zonaSegura);
        fichas.push_back(ficha3);
        FichaLudo * ficha4 = new FichaLudo(color,zonaSegura);
        fichas.push_back(ficha4);
        this->esGanador = 0;
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


int JugadorLudo::encontrarBarrera(int posicion, FichaLudo* mover, TableroLudo* tableroLudo) {
    int resultado = 0;
    for (int i = mover->getPos() + 1; i <= posicion; ++i) {
        if (tableroLudo->tablero[0][i] != NULL &&
            tableroLudo->tablero[1][i] != NULL) {
            return i;
        }
    }
    return resultado;
}

    void JugadorLudo::moverFicha(FichaAbstracta * ficha, int pasos, TableroAbstracto* tablero){
        TableroLudo* tableroLudo =  dynamic_cast<TableroLudo* >(tablero);

        ValidadorLudo* validadorLudo =  dynamic_cast<ValidadorLudo* >(tableroLudo->getValidador());

        int resultado = validadorLudo->validarJugada(ficha->getPos()+pasos, ficha);


        switch(resultado) {

            case 1:
                    int newPos = ficha->getPos() + pasos;
                    for (int i=0; i<2; ++i) {
                        if (!tableroLudo->tablero[i][newPos]) {
                           tableroLudo->tablero[i][newPos] = dynamic_cast<FichaLudo* >(ficha);
                        }
                    }
                    
                break;

            case 2:
                    int resultado = encontrarBarrera(ficha->getPos() + pasos, dynamic_cast<FichaLudo* >(ficha), tableroLudo);
                    
                    if (resultado != ficha->getPos()) {
                        for (int j=0; j<2; ++j) {
                            if (!tableroLudo->tablero[j][resultado-1]) {
                                tableroLudo->tablero[j][resultado-1] = dynamic_cast<FichaLudo* >(ficha);
                                continue;
                            }
                        }
                    }
                    
                break;

            default:
                    int nuevaPos = ficha->getPos() + pasos;
                    FichaLudo* newFicha = nullptr;
                    int saveState = 0; 
                    for (int k=0; k<2; ++k) {
                        if (tableroLudo->tablero[k][nuevaPos]) {
                            newFicha = tableroLudo->tablero[k][nuevaPos];
                            saveState = k;
                            continue;
                        }
                    }
                    tableroLudo->tablero[saveState][nuevaPos] = dynamic_cast<FichaLudo* >(ficha);
                    newFicha->setPasosDados(0);
                    newFicha->desactivarFicha();

        }

// Que tiene que hacer el usuario?
// 1. lanzar el dado       done
// 2. Escoger la ficha     done
// 3. Se puede mover? 
        
        
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
