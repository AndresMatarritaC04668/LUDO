#include "Inventario.h"

Inventario::Inventario() {
  this->inventory = new std::vector<Objeto *>;
}

Inventario::Inventario(Inventory inventory) {
  if (inventory)
    cleanInventory();

  this->inventory = inventory;
}

Inventario::~Inventario() {
  if (inventory) {
    cleanInventory();
    delete this->inventory;
  }
}

void Inventario::asignarInventario(Inventory inventory) {
  if (inventory) {
    cleanInventory();
    delete this->inventory;
  }

  this->inventory = inventory;
}

Inventario::Inventory Inventario::obtenerInventario() {
  return this->inventory;
}

int Inventario::sizeInventory() {
  return this->inventory->size();
}

void Inventario::addObject(Objeto * object) {
  this->inventory->push_back(object);
}

void Inventario::removeObject(Objeto * object) {
  int size = sizeInventory();
  int i = 0;
  bool salir = false;

  while (i < size && !salir) {
    if (this->inventory->at(i) == object) {
      this->inventory->erase(this->inventory->begin() + i);
      salir = true;
    }
    ++i;
  }
}

void Inventario::cleanInventory() {
  for (auto it : *this->inventory)
    delete it;

  this->inventory->clear();
}

bool Inventario::search(Objeto * object) {
  for (auto it : *this->inventory) {
    if (it == object)
      return true;
  }
  return false;
}
