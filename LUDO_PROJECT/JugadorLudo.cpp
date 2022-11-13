#include "JugadorLudo.h"
#include "FichaLudo.h"
#include "ValidadorLudo.h"

#include "Hilera.h"
    
    JugadorLudo::JugadorLudo() {
        this->esGanador = 0;
        this->cantidadDados = 1;
   }


    JugadorLudo::JugadorLudo(string color,int zonaSegura,string nombre){
        this->cantidadDados = 1;
        FichaLudo * ficha1 = new FichaLudo(color,zonaSegura,1);
        fichas.push_back(ficha1);
        FichaLudo * ficha2 = new FichaLudo(color,zonaSegura,2);
        fichas.push_back(ficha2);
        FichaLudo * ficha3 = new FichaLudo(color,zonaSegura,3);
        fichas.push_back(ficha3);
        FichaLudo * ficha4 = new FichaLudo(color,zonaSegura,4);
        fichas.push_back(ficha4);
        this->esGanador = 0;
        agregarAtributo("color",new Hilera(color));
        agregarAtributo("nombre",new Hilera(nombre));

    }

    JugadorLudo::~JugadorLudo() {
            for (auto i: fichas)
                delete i;
    }

    void JugadorLudo::setNombre(std::string nombre) {
         agregarAtributo("nombre",new Hilera(nombre));
    }

    std::string JugadorLudo:: getNombre() {
            std::string nombre = "";
                Valor* valor = obtenerAtributo("nombre");
                if (valor != nullptr) {
                    nombre = ((Hilera*) valor)->obt();
                }
                return nombre;
    }

    bool JugadorLudo::getEsGanador() {
            return this->esGanador;
    }
        
    std::vector<FichaAbstracta *> JugadorLudo::getFichas(){
           return this->fichas;
    }


int JugadorLudo::encontrarBarrera(int posicion, FichaLudo* mover, TableroLudo* tableroLudo) {
    int resultado = 0;
    for (int i = mover->getY() + 1; i <= posicion; ++i) {
        if (tableroLudo->tablero[0][i] != NULL &&
            tableroLudo->tablero[1][i] != NULL) {
            return i;
        }
    }
    return resultado;
}

    int JugadorLudo::moverFicha(FichaAbstracta * miFicha, int pasos, TableroAbstracto* tablero){
        int repetir = 0;
        TableroLudo* tableroLudo =  dynamic_cast<TableroLudo* >(tablero);
        ValidadorLudo* validadorLudo =  dynamic_cast<ValidadorLudo* >(tableroLudo->getValidador());
        FichaLudo * ficha =   dynamic_cast<FichaLudo* >(miFicha);


        if(!ficha->getEstado() /**&& pasos != 6**/){ // descomentar regla del 6
           // string mensaje = "";
           //mensaje += "No sacas 6 no sacas ficha de la carcel";
          //tableroLudo-> graficarInformacion(mensaje);
          // return 0;
         //} else if(!ficha->getEstado() && pasos == 6){

            ficha->setEstadoActivo();
           // repetir = 1;
           // pasos = 0;
        }


        if((ficha->getPasosDados() + pasos) > 54){

          moverFichaRectaFinal(ficha,pasos,tableroLudo , validadorLudo);

        } else {
   
        int resultado = validadorLudo->validarJugada((ficha->getY()+pasos)%52, ficha);
        switch(resultado) {

            case 1:
            {
                    int newPos = (ficha->getY() + pasos)%52;
                    for (int i=0; i<2; ++i) {
                        if (!tableroLudo->tablero[i][newPos]) { 
                           tableroLudo->tablero[ficha->getX()][ficha->getY()] = nullptr; // VACIA CELDA antigua 
                           tableroLudo->tablero[i][newPos] = dynamic_cast<FichaLudo* >(ficha);
                           ficha->setPosicion(i,newPos);  // Nueva posicion
                           ficha->setPasosDados(ficha->getPasosDados()+pasos);// sumarPasos
                           break;
                        }
                    }
                 

                break;
            }
            case 2:
            {
               string mensaje = "Hay una barrera de color , no puedes avanzar";
               tableroLudo->graficarInformacion(mensaje);
                
                break;
            }

            default:
                    int nuevaPos = (ficha->getY() + pasos)%52;
                    FichaLudo* newFicha = nullptr;
                    int saveState = 0; 
                    for (int k=0; k<2; ++k) {
                        if (tableroLudo->tablero[k][nuevaPos]) {
                            newFicha = tableroLudo->tablero[k][nuevaPos];
                            saveState = k;
                            break;
                        }
                    }
                    tableroLudo->tablero[ficha->getX()][ficha->getY()] = nullptr;
                    tableroLudo->tablero[saveState][nuevaPos] = dynamic_cast<FichaLudo* >(ficha);
                    ficha->setPosicion(saveState,nuevaPos);  // Nueva posicion
                    ficha->setPasosDados(ficha->getPasosDados()+pasos);// sumarPasos'

                    newFicha->setPasosDados(0);
                    newFicha->desactivarFicha();
        }
    }


        tableroLudo->controlador->graficarTablero(tableroLudo);

        if(pasos == 6 || repetir == 1){
            repetir = 1;
            string mensaje = "Obtuviste un 6 , tira de nuevo";
            tableroLudo->graficarInformacion(mensaje);
        }




        return repetir;
    }


    int JugadorLudo::lanzarDado(){
        //TableroLudo* tableroLudo =  dynamic_cast<TableroLudo* >(tablero);
        Dado  dado;
        int darPasos = 0;
        //string mensaje = "Por favor lanza el dado: " + this->nombre;
        //tableroLudo->graficarInformacion(mensaje);
        for(int i = 0 ; i<cantidadDados ; i++){
          darPasos+= dado.lanzar();
        }
        return darPasos;
    }

    FichaAbstracta * JugadorLudo::elegirFicha(TableroAbstracto* tablero,int pasos){
       TableroLudo* tableroLudo =  dynamic_cast<TableroLudo* >(tablero);

       string mensaje = "Dado sacó: " + std::to_string(pasos);
       while(1){
         int opcion = 0;
         opcion = tableroLudo->graficoElejirFicha(mensaje);
         
         if(opcion >=1 && opcion <=4 && !fichas[(opcion-1)%4]->getFinalizado()){
            return fichas[(opcion-1)%4];
         } else {
            mensaje = "La ficha elegida ya esta en la meta , eliga otra ficha";
            tableroLudo->graficarInformacion(mensaje);
         }
       }
    }

    string JugadorLudo::getColor(){
        std::string color = "";
            Valor* valor = obtenerAtributo("color");
            if (valor != nullptr) {
                color = ((Hilera*) valor)->obt();
            }
            return color;
    }

    void JugadorLudo::setColor(string color){
        agregarAtributo("color",new Hilera(color));
    }



    void JugadorLudo::moverFichaRectaFinal(FichaLudo * ficha, int pasos, TableroLudo* tablero , ValidadorLudo * validador){
        string mensaje = "";
        TableroLudo* tableroLudo =  dynamic_cast<TableroLudo* >(tablero);

        if(ficha->getPasosDados() <= 54){
           tablero->tablero[ficha->getX()][ficha->getY()] = nullptr;
           ficha->setPasosDados(ficha->getPasosDados()+pasos);        
        } else {
            if((pasos+ficha->getPasosDados()) > 60 ){
                mensaje = "No puedes mover tu ficha , excede las casillas hasta la meta\n";
                 tableroLudo->graficarInformacion(mensaje);
            } else{
                ficha->setPasosDados(ficha->getPasosDados()+pasos);
            }
        }

        if(validador->finalizaFicha(ficha)){
            mensaje = "Ficha llega a la meta" + ficha->getColor();
            tableroLudo->graficarInformacion(mensaje);
            ficha->setFinalizado();
        }
    }

    int JugadorLudo::elegirQueHacer(TableroAbstracto* tablero){

        TableroLudo* tableroLudo =  dynamic_cast<TableroLudo* >(tablero);
        tableroLudo->controlador->graficarTablero(tableroLudo);
        int eleccion = 1;

        eleccion = tableroLudo->controlador->eleccionJugador(getNombre());

        return eleccion;
    }

    void JugadorLudo::setFichas(std::vector<FichaAbstracta *>fichas){

        this->fichas = fichas;
    }



 
