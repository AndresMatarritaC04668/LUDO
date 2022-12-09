/**
 * @file Inventario.h
 * @author  Esteban José Mora García (C05126),
 * José Andrés Matarrita Miranda (C04668), Joseph Fernando Núñez Solano (C05582)
 * @brief Clase que implementa un inventario para los juegos.
 * @version 0.1
 * @date 2022-12-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MY_INVENTORY_8DEC22
#define MY_INVENTORY_8DEC22

#include <vector>
#include "Objeto.h"

class Inventario {
  public:
    // Define un tipo especial del vector.
    typedef std::vector<Objeto *> * Inventory;

    /**
     * @brief Construct a new Inventario object
     * 
     */
    Inventario();

    /**
     * @brief Construct a new Inventario object by arguments
     * 
     * @param inventory Se guarda en el atributo inventory.
     */
    Inventario(Inventory);

    /**
     * @brief Destroy the Inventario object
     * 
     */
    ~Inventario();

    /**
     * @brief Asigna un inventario para el atributo inventory. Advertencia: Si
     * habia un inventario previo, se borraran todos sus objetos.
     * 
     * @param inventory Se guarda en el atributo inventory.
     */
    void asignarInventario(Inventory);

    /**
     * @brief Devuelve el atributo inventary.
     * 
     * @return Inventory El atributo inventory.
     */
    Inventory obtenerInventario();

    /**
     * @brief Devuelve cuantos objetos hay en el inventario.
     * 
     * @return int El numero de objetos en el inventario.
     */
    int sizeInventory();

    /**
     * @brief Agrega un objeto al inventario.
     * 
     * @param object se agrega al atributo inventory.
     */
    void addObject(Objeto *);

    /**
     * @brief Elimina un objeto del inventario.
     * 
     * @param object se va a eliminar del atributo inventory.
     */
    void removeObject(Objeto *);

    /**
     * @brief Limpia el contenido del inventario. Advertencia: Si habia
     * contenido en el inventario, se borraran todos sus objetos.
     * 
     */
    void cleanInventory();

    /**
     * @brief Busca un objeto en el inventario y determina si esta presente o
     * no.
     * 
     * @param object El objeto a buscar en el inventario. 
     * @return true Si esta presente.
     * @return false Si no esta presente.
     */
    bool search(Objeto *);

  private:
    Inventory inventory;
};

#endif
