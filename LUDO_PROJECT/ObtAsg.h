#ifndef OBTASG_H
#define OBTASG_H

#include "Valor.h"

template < typename T >
class ObtAsg : public Valor
{
public:
    ObtAsg() {};
    virtual ~ObtAsg() {}; 
    virtual void asg(T o) = 0;
    virtual T obt() const = 0;
};

#endif
