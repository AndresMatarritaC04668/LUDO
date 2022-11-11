#include "Hilera.h"

Hilera::Hilera()
{
}

Hilera::Hilera(std::string v) : valor(v)
{
}

Hilera::~Hilera()
{
}

void Hilera::asg(std::string valor)
{
	this->valor = valor;
}

std::string Hilera::obt() const
{
	return valor;
}

tipo::tipo_atributo Hilera::obtTipo() const
{
	return tipo::tipo_atributo::Hilera;
}

std::string Hilera::toString() const
{
    return valor;
}
