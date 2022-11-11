#ifndef CONSTRUCTORSERIALIZADORABSTRACTO_H
#define CONSTRUCTORSERIALIZADORABSTRACTO_H

#include <string>
#include <utility>

#include "Valor.h"

class ConstructorSerializadorAbstracto
{
public:
	ConstructorSerializadorAbstracto() {};
	~ConstructorSerializadorAbstracto() {};
	virtual void inicioObjeto() = 0;
	virtual void finObjeto() = 0;
    virtual void serializarHilera(const std::pair< std::string, Valor* >& ph) = 0;
	virtual std::string obtSerializacion() = 0;
    virtual void agregarSeparador() = 0;
};

#endif
