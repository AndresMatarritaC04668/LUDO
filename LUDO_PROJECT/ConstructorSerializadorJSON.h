#ifndef CONSTRUCTORSERIALIZADORJSON_H
#define CONSTRUCTORSERIALIZADORJSON_H

#pragma once

#include <sstream>

#include "ConstructorSerializadorAbstracto.h"
#include "Valor.h"
class ConstructorSerializadorJSON : public ConstructorSerializadorAbstracto
{
public:
	ConstructorSerializadorJSON();
	~ConstructorSerializadorJSON();
	virtual void inicioObjeto() override;
	virtual void finObjeto() override;
	virtual void serializarHilera(const std::pair< std::string, Valor* >& ph) override;
	virtual std::string obtSerializacion() override;
    virtual void agregarSeparador() override;
    std::string serializacion;

private:

};

#endif
