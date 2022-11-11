#ifndef HILERA_H
#define	HILERA_H

#pragma once

#include <sstream>

#include "ObtAsg.h"
class Hilera : public ObtAsg< std::string >
{
public:
	Hilera();
	Hilera(std::string v);
	virtual ~Hilera();
	virtual void asg(std::string o) override;
	virtual std::string obt() const override;
	virtual tipo::tipo_atributo obtTipo() const override;
    virtual std::string toString() const override;

private:
	std::string valor;
};

#endif
