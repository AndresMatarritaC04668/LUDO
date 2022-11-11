#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "ConstructorSerializadorAbstracto.h"
#include "DeserializadorAbstracto.h"
#include "Objeto.h"
#include "Jugador.h"
#include "tableroLUDO.h"

class Controlador_Memento {

public:
    Controlador_Memento();
    ~Controlador_Memento();
    void serializarTablero(TableroAbstracto * , string);
    std::string serializarJugadoresJSON(std::vector<Jugador*>);
    std::string serializarFichasJSON(std::vector<FichaAbstracta*>);
    std::string serializarListaObjetosJSON(std::vector<Objeto*>);
    std::string serializarJSON(Objeto*);
    TableroLudo * deserializarTableroJSON(std::string);
    std::vector<Jugador*> deserializarListaJugadoresJSON(std::string);
    std::vector<FichaAbstracta*> deserializarListaFichasJSON(std::string);
    TableroLudo * deserializarJuego(std::string ,QWidget*);


    
private:
    std::string serializar(Objeto*,ConstructorSerializadorAbstracto*);
    const std::string listaObjetosString = "ListaObjetos";
    const std::string numElemString = "cantidad";
    TableroLudo * deserializarTablero(std::string, DeserializadorAbstracto*);
    std::vector<Jugador*> deserializarListaJugadores(std::string , DeserializadorAbstracto*);
    std::vector<FichaAbstracta*> deserializarListaFichas(std::string , DeserializadorAbstracto*);
   
};
#endif
