#ifndef Valor_H
#define	Valor_H

#include "tipo.h"
#include <string>

class Valor
{
public:
	Valor() {};
	virtual ~Valor() {};
	virtual tipo::tipo_atributo obtTipo() const = 0;
	virtual std::string toString() const = 0;
};
#endif
