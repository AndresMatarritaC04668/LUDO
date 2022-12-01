/**
 * @file ValidadorLudo.h
 * @authors Esteban José Mora García (C05126),
 * José Andrés Matarrita Miranda (C04668), Joseph Fernando Núñez Solano (C05582)
 * @brief Clase que define el validador para el juego de LUDO.
 * @version 0.1
 * @date 2022-11-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef VALIDADORLUDO_27OCT22
#define VALIDADORLUDO_27OCT22

#include "Validador.h"
#include "TableroAbstracto.h"
#include "tableroLUDO.h"
#include "Jugador.h"
#include "FichaLudo.h"
#include "FichaAbstracta.h"

class Validador;

class ValidadorLudo : public Validador {
    private:
        TableroLudo * mesaLudo;
    public:

        /**
         * @brief Construct a new Validador Ludo:: Validador Ludo object
         * 
         */
        ValidadorLudo();

        /**
         * @brief Construct a new Validador Ludo:: Validador Ludo object by
         * arguments.
         * 
         * @param mesa TableroAbstracto que representa el tablero de juego.
         */
        ValidadorLudo(TableroAbstracto * mesa);

        /**
         * @brief Construct a new Validador Ludo:: Validador Ludo object by
         * arguments
         * 
         * @param mesa TableroLudo que representa el tablero de juego.
         */
        ValidadorLudo(TableroLudo * mesa);

        /**
         * @brief Metodo que inicializa las reglas.
         * 
         */
        void iniciarReglas() override;

        /**
         * @brief Valida la jugada conforme a las reglas.
         * 
         * @param posicion La nueva posicion a la que tiene que llegar la ficha.
         * @param mover Es la ficha que se tiene que reubicar.
         * @return 2 Si hay una barrera. 3 Si hay otra ficha. 1 Si simplemente
         * avanza.
         */
        int validarJugada(int posicion, FichaAbstracta * mover) override;

        /**
         * @brief Devuelve una string con todas las reglas separadas por un
         * cambio de linea.
         * 
         * @return string La hilera con las reglas.
         */
        string toStringReglas() override;


        bool verificarBloqueo();

        /**
         * @brief Castea un tablero abstracto en un tablero de ludo.
         * 
         */
        void castTable();

        /**
         * @brief Setea el atributo de mesaLudo.
         * 
         * @param mesa El valor con lo que se llena el atributo de mesaLudo.
         */
        void setMesaLudo(TableroLudo * mesa);

        /**
         * @brief Procedimiento que verifica si la regla 8 (la de la barrera) se
         * esta cumpliendo.
         * 
         * @param posicion La posicion hasta donde se debe mover la ficha.
         * @param mover La ficha que se debe mover
         * @return true Si se cumple la regla ocho.
         * @return false Si no se cumple la regla ocho.
         */
        bool reglaOcho(int posicion, FichaLudo * mover);

        /**
         * @brief Clase que verifica si se puede comer la ficha que se encuentra
         * en una posicion indicada por un numero entero.
         * 
         * @param posicion posicion en la que se podria encontrar una ficha.
         * @return true Si se puede comer.
         * @return false Si no se puede comer.
         */
        bool verifComer(int posicion, FichaLudo * mover);

        /**
         * @brief Metodo que identifica el posible accionar al sacar un numero seis tras
         * lanzar el dado.
         * 
         * @return true Si se puede sacar de la salida.
         * @return false Si no se puede sacar de la salida.
         */
        bool validarSeis(int pasosDado, FichaAbstracta * laFicha);

        /**
         * @brief Determina si una ficha ya llego a casa.
         * 
         * @return int 1 si ya llego, 0 si no ha llegado.
         */
        int finalizaFicha(FichaLudo *);

        /**
         * @brief Se usa al final de cada turno, determina si algun ganador ya
         * consiguio ganar el juego.
         * 
         * @param fichas Un vector con las fichas del juego.
         * @return int 1 si es ganador, 0 si no lo es.
         */
        int esGanador(std::vector<FichaAbstracta *>)override;
        
};

#endif