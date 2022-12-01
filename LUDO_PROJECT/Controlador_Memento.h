/**
 * @file Controlador_Memento.h
 * @author Joseph Fernando Núñez Solano (C05582)
 * @brief Controlador del serializador y del deserializador.
 * @version 0.1
 * @date 2022-12-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "ConstructorSerializadorAbstracto.h"
#include "DeserializadorAbstracto.h"
#include "Objeto.h"
#include "Jugador.h"
#include "tableroLUDO.h"

class Controlador_Memento {

public:
    /**
     * @brief Construct a new Controlador_Memento object
     * 
     */
    Controlador_Memento();

    /**
     * @brief Destroy the Controlador_Memento object
     * 
     */
    ~Controlador_Memento();

    /**
     * @brief Crea el archivo, llama a serializar el tablero y finalmente
     * guarda la serializacion en el archivo creado.
     * 
     * @param mesa Es el tablero del juego que se va a serializar.
     * @param nombreCSV Es el nombre del archivo en el que se va a guardar la
     * serializacion.
     */
    void serializarTablero(TableroAbstracto * , string);

    /**
     * @brief Serializa a los jugadores de la partida directamente del vector de
     * jugadores, los guarda en un vector y luego llama a
     * serializarListaObjetosJSON().
     * 
     * @param listaJugadores La lista de jugadores que deben ser serializados
     * como si fueran una lista.
     * @return std::string La lista de jugadores serializada.
     */
    std::string serializarJugadoresJSON(std::vector<Jugador*>);

    /**
     * @brief Serializa las fichas de un jugador de la partida directamente de
     * su vector de fichas, los guarda en un vector y luego llama a
     * serializarListaObjetosJSON().
     * 
     * @param listaFichas La lista de fichas que deben ser serializadas como si
     * fueran una lista.
     * @return std::string La lista de fichas serializada.
     */
    std::string serializarFichasJSON(std::vector<FichaAbstracta*>);

    /**
     * @brief Crea una string a partir de una lista (vector) de objetos
     * abstractos, de tal forma que concuerde con el formato utilizado.
     * 
     * @param listaObjetos Vector de objetos que deben ser serializados como
     * si fueran una lista.
     * @return std::string La string de objetos serializados.
     */
    std::string serializarListaObjetosJSON(std::vector<Objeto*>);
    
    /**
     * @brief Manda a serializar un solo objeto abstrato de acuerdo al formato
     * utilizado. Crea una string con ello.
     * 
     * @param objeto el objeto abstracto a serializar.
     * @return std::string La string del objeto serializado.
     */
    std::string serializarJSON(Objeto*);

    /**
     * @brief Deserializa una string que representa el tablero de juego en el
     * formato utilizado. Llama a deserializarTablero().
     * 
     * @param string La string serializada con el tablero.
     * @return TableroLudo* El tablero deserializado.
     */
    TableroLudo * deserializarTableroJSON(std::string);

    /**
     * @brief Deserializa una lista de jugadores a partir de una string
     * serializada en el formato utilizado. Llama a deserializarListaJugadores()
     * 
     * @param string La lista de jugadores serializada.
     * @return std::vector<Jugador*> El vector de jugadores deserializado.
     */
    std::vector<Jugador*> deserializarListaJugadoresJSON(std::string);

    /**
     * @brief Deserializa una lista de fichas a partir de una string
     * serializada en el formato utilizado. Llama a deserializarListaFichas().
     * 
     * @param string La lista de fichas serializada.
     * @return std::vector<FichaAbstracta*> El vector de fichas deserializado.
     */
    std::vector<FichaAbstracta*> deserializarListaFichasJSON(std::string);
    
    /**
     * @brief Estructura de deserializacion del juego a partir del archivo que
     * con la partida serializada. Llama a los demás metodos.
     * 
     * @param nombreCSV nombre del archivo serializado.
     * @param Output Envía mensajes de output en caso de error.
     * @return TableroLudo* El tablero de juego deserializado.
     */
    TableroLudo * deserializarJuego(std::string ,QWidget*);


    
private:
    /**
     * @brief Serializa un objeto abstracto usando sus atributos y un
     * constructor serializador abstracto.
     * 
     * @param objeto El objeto a serializar.
     * @param serializador Se usan los metodos de este serializador para
     * serializar el objeto.
     * @return std::string El objeto serializado.
     */
    std::string serializar(Objeto*,ConstructorSerializadorAbstracto*);
    const std::string listaObjetosString = "ListaObjetos";
    const std::string numElemString = "cantidad";
    
    /**
     * @brief Deserializa un tablero a partir de una string serializada que
     * contiene un tablero y el deserializador abstracto.
     * 
     * @param string es una string serializada que contiene un tablero.
     * @param deserializador Se usan sus metodos para serializar el tablero.
     * @return TableroLudo* El tablero deserializado.
     */
    TableroLudo * deserializarTablero(std::string, DeserializadorAbstracto*);

    /**
     * @brief Deserializa una lista de jugadores a partir de una string que
     * contiene jugadores serializados y un deserializador.
     * 
     * @param string La string serializada que contiene los jugadores.
     * @param deserializador Se usan sus metodos para serializar a los
     * jugadores.
     * @return std::vector<Jugador*> Vector de jugadores deserializado.
     */
    std::vector<Jugador*> deserializarListaJugadores(std::string , DeserializadorAbstracto*);
    
    /**
     * @brief Deserializa una lista de Fichas a partir de una string que
     * contiene fichas serializadas y un deserializador.
     * 
     * @param string La string serializada que contiene las fichas.
     * @param deserializador Se usan sus metodos para serializar a las fichas.
     * @return std::vector<FichaAbstracta*> Vector de fichas deserializadas.
     */
    std::vector<FichaAbstracta*> deserializarListaFichas(std::string , DeserializadorAbstracto*);
   
};
#endif
