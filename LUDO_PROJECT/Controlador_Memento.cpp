#include "Controlador_Memento.h"
#include <vector>

#include "ConstructorSerializadorJSON.h"
#include "DeserializadorJSON.h"
//#include "Hilera.h"
//#include <QDebug>
#include "FichaAbstracta.h"
#include "tableroLUDO.h"
#include "JugadorLudo.h"
#include <iostream>
#include <fstream>
#include <QMessageBox>

int abrirArchivo(ifstream& reader, string filename , QWidget*);
void extraerFilas(ifstream& reader, vector<string>& lineas);

Controlador_Memento::Controlador_Memento() {
}

Controlador_Memento::~Controlador_Memento() {
}

void Controlador_Memento::serializarTablero(TableroAbstracto * mesa, string nombreCSV){
    nombreCSV += ".csv";

    ofstream {nombreCSV};
    ofstream writer(nombreCSV);
    string mesaJSON = "";

    mesaJSON = serializarJSON(mesa);
    writer << mesaJSON << endl;

    mesaJSON = serializarJugadoresJSON(mesa->getJugadores());
    writer << mesaJSON << endl;

    for(Jugador * jugador: mesa->getJugadores()){
     if(jugador!=nullptr){
        mesaJSON = serializarFichasJSON(jugador->getFichas());
        writer << mesaJSON << endl;
     }
    }


}

TableroLudo * Controlador_Memento::deserializarJuego(std::string  nombreCSV , QWidget* output){
    ifstream reader;
    vector<string> lineas;
    nombreCSV += ".csv";
    TableroLudo * tablero = nullptr;

    int existe = abrirArchivo(reader, nombreCSV , output);

    if(existe){
      extraerFilas(reader, lineas);
      int iterador = 0;
      tablero =   deserializarTableroJSON(lineas[iterador]);
      iterador++;
      std::vector<Jugador*> listaJugadores = deserializarListaJugadoresJSON(lineas[iterador]);
      iterador++;
      if(tablero->getCantidadJugadores() == 2){
         listaJugadores.push_back(nullptr);
         listaJugadores.push_back(nullptr);
      } else if(tablero->getCantidadJugadores() == 3){
          listaJugadores.push_back(nullptr);
      }
      tablero->setJugadores(listaJugadores);

      std::vector<FichaAbstracta*> listaFichas = deserializarListaFichasJSON(lineas[iterador]);
      iterador++;
      tablero->getjugadores()[0]->setFichas(listaFichas);


      listaFichas = deserializarListaFichasJSON(lineas[iterador]);
      iterador++;
      tablero->getjugadores()[1]->setFichas(listaFichas);

      if(tablero->getCantidadJugadores() >= 3){
          listaFichas = deserializarListaFichasJSON(lineas[iterador]);
          iterador++;
          tablero->getjugadores()[2]->setFichas(listaFichas);
      }

      if(tablero->getCantidadJugadores() == 4){
          listaFichas = deserializarListaFichasJSON(lineas[iterador]);
          iterador++;
          tablero->getjugadores()[3]->setFichas(listaFichas);
      }

       tablero->rellenarMesa();
    }


    return tablero;
}

int abrirArchivo(ifstream& reader, string filename , QWidget* output) {
    int existe = 0;
    reader.open(filename);
    if (reader.fail()) {
        QMessageBox::information(output,"No existe partida" , "No hay ninguna partida almacenada con ese nombre" );

    } else {
        existe = 1;
    }

    return existe;
}

void extraerFilas(ifstream& reader, vector<string>& lineas) {
    while (!reader.eof()) {
        string linea;
        getline(reader, linea);
        if (linea != "")
            lineas.push_back(linea);
        linea.clear();
    }
}



std::string Controlador_Memento::serializarJSON(Objeto* objeto) {
    ConstructorSerializadorJSON* serializador = new ConstructorSerializadorJSON();
    std::string stringJSON = serializar(objeto,serializador);
    return stringJSON;
}

std::string Controlador_Memento::serializar(Objeto* objeto, ConstructorSerializadorAbstracto* serializador) {
	std::vector< std::pair< std::string, Valor* > >  atributos;
    objeto->obtAtributos(atributos); // se obtiene el vector de atributos
	serializador->inicioObjeto();
    for (auto atributo : atributos) {
		switch (atributo.second->obtTipo())
		{
        case tipo::Hilera:serializador->serializarHilera(atributo);
            break;
		}
        if (atributos[atributos.size()-1]!=atributo) {
            serializador->agregarSeparador();
        }
    }
    serializador->finObjeto();
    return serializador->obtSerializacion();
}

std::string Controlador_Memento::serializarJugadoresJSON(std::vector<Jugador*> listaJugadores ){
   vector<Objeto*> JugadoresObjeto;
   for(Jugador * jugador: listaJugadores){
      JugadoresObjeto.push_back(jugador);
   }
   return serializarListaObjetosJSON(JugadoresObjeto);
}

std::string Controlador_Memento::serializarFichasJSON(std::vector<FichaAbstracta*> listaFichas){
    vector<Objeto*> FichasObjeto;
    for( FichaAbstracta  * ficha: listaFichas){
       FichasObjeto.push_back(ficha);
    }
    return serializarListaObjetosJSON(FichasObjeto);


}

std::string Controlador_Memento::serializarListaObjetosJSON(std::vector<Objeto*> listaObjetos) {
    std::string stringJSON = "{";
    unsigned long contador = listaObjetos.size();
    if (contador > 0) {
        stringJSON += '"'+listaObjetosString+'"'+':';
        stringJSON += "[";
        for (auto objeto : listaObjetos) {
          if(objeto != nullptr){
            stringJSON += serializarJSON(objeto);
            if (objeto != listaObjetos[listaObjetos.size()-1]) {
                stringJSON += ",";
            }
           }
        }
        stringJSON += "]";
    }
    stringJSON += "}";
    return stringJSON;
}

TableroLudo * Controlador_Memento::deserializarTableroJSON(std::string stringJSON){
    DeserializadorJSON* deserializador = new DeserializadorJSON();
    TableroLudo * tablero  = deserializarTablero(stringJSON,deserializador);
    return tablero;

}

TableroLudo *  Controlador_Memento::deserializarTablero(std::string stringJSON, DeserializadorAbstracto * deserializador ){
   TableroLudo * tablero = new TableroLudo();
   std::map<std::string, Valor*> atributos = deserializador->deserializarObjeto(stringJSON);
    tablero->setAtributos(atributos);
    return tablero;
}

std::vector<Jugador*> Controlador_Memento::deserializarListaJugadoresJSON(std::string stringJSON){
    DeserializadorJSON* deserializador = new DeserializadorJSON();
    std::vector<Jugador*> listaJugadores = deserializarListaJugadores(stringJSON,deserializador);
    return listaJugadores;
}

std::vector<Jugador*> Controlador_Memento::deserializarListaJugadores(std::string stringJSON, DeserializadorAbstracto* deserializador) {
    std::vector<Jugador*> listaJugadores;

    std::vector<std::map<std::string, Valor*>> listaAtributos = deserializador->deserializarListaObjetos(stringJSON);
    for(auto atributos: listaAtributos) {
       JugadorLudo * jugador = new JugadorLudo();
       jugador->setAtributos(atributos);
        listaJugadores.push_back(jugador);
    }
    return listaJugadores;
}

std::vector<FichaAbstracta*> Controlador_Memento::deserializarListaFichasJSON(std::string stringJSON){
    DeserializadorJSON* deserializador = new DeserializadorJSON();
    std::vector<FichaAbstracta*> listaFichas = deserializarListaFichas(stringJSON,deserializador);
    return listaFichas;
}

std::vector<FichaAbstracta*> Controlador_Memento::deserializarListaFichas(std::string stringJSON, DeserializadorAbstracto* deserializador) {
    std::vector<FichaAbstracta*> listaFichas;

    std::vector<std::map<std::string, Valor*>> listaAtributos = deserializador->deserializarListaObjetos(stringJSON);
    for(auto atributos: listaAtributos) {
       FichaLudo * ficha = new FichaLudo();
       ficha->setAtributos(atributos);
        listaFichas.push_back(ficha);
    }
    return listaFichas;
}

