#include "DeserializadorJSON.h"
#include "Hilera.h"
#include <iostream>
//#include <QDebug>
//#include <QString>
DeserializadorJSON::DeserializadorJSON() {}

DeserializadorJSON::~DeserializadorJSON() {}

void DeserializadorJSON::eliminarInicioFinObjeto(std::string& string) {
    string = string.substr(1, string.size() - 2);
}


std::map< std::string, Valor* > DeserializadorJSON::deserializarObjeto(std::string stringJSON) {

    eliminarInicioFinObjeto(stringJSON);
    //qDebug()<<QString::fromStdString(stringJSON);
    stringJSON += delimitadorAtributo;
    unsigned long indice;
    std::string componente;
    std::map< std::string, Valor* > valores;


    while ((indice = stringJSON.find(delimitadorAtributo)) != std::string::npos) {
        componente = stringJSON.substr(0, indice);
        if(componente == ""){
          break;
         }
        valores.insert(extraerLlaveValor(componente));
        stringJSON.erase(0, indice + delimitadorAtributo.length());

    }
   
    return valores;
}

std::pair<std::string, Valor*> DeserializadorJSON::extraerLlaveValor(std::string llaveValorString) {
    unsigned long indiceLlaveValor = llaveValorString.find(delimitadorLlaveValor);
    std::string llave = llaveValorString.substr(0, indiceLlaveValor);
    eliminarInicioFinObjeto(llave);
    std::string valor = llaveValorString.substr(indiceLlaveValor+1, llaveValorString.length());
    eliminarInicioFinObjeto(valor);
    return std::pair<std::string, Hilera*> (llave,new Hilera(valor));
}

std::vector<std::map< std::string, Valor* >> DeserializadorJSON::deserializarListaObjetos(std::string listaJSON) {
    std::vector<std::map< std::string, Valor* >> listaObjetos;
    eliminarInicioFinObjeto(listaJSON);
    std::pair<std::string, Valor*> llaveValor = extraerLlaveValor(listaJSON);
    std::string stringJSON = ((Hilera*)llaveValor.second)->obt();
    unsigned long indice;
    std::string objetoJSON;
    stringJSON += delimitadorAtributo;
    
    while ((indice = stringJSON.find("}")) != std::string::npos) {
        objetoJSON = stringJSON.substr(0, indice+1);
         if(objetoJSON == ""){
          break;
         }
        stringJSON.erase(0, objetoJSON.length()+1);
        listaObjetos.push_back(deserializarObjeto(objetoJSON));
    }    
    return listaObjetos;
}




