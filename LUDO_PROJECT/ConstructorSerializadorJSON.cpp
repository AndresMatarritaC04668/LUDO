#include "ConstructorSerializadorJSON.h"

ConstructorSerializadorJSON::ConstructorSerializadorJSON() {}

ConstructorSerializadorJSON::~ConstructorSerializadorJSON() {}

void ConstructorSerializadorJSON::inicioObjeto()
{
	serializacion = serializacion + "{";
}

void ConstructorSerializadorJSON::finObjeto()
{
	serializacion = serializacion + "}";
}

void ConstructorSerializadorJSON::serializarHilera(const std::pair< std::string, Valor* >& ph)
{
	serializacion = serializacion + '"' + ph.first + '"' + ':' + '"' + ph.second->toString() + '"';
}

std::string ConstructorSerializadorJSON::obtSerializacion()
{
	return serializacion;
}

void ConstructorSerializadorJSON::agregarSeparador() {
    serializacion=serializacion+",";
}
