#ifndef _SERIALIZADORABSTRACTO_H
#define _SERIALIZADORABSTRACTO_H

#include <string>

using namespace std;


class SerializadorAbstracto {

    public:
        SerializadorAbstracto();
        ~SerializadorAbstracto();
        virtual void inicioObjeto() = 0;
        virtual void finObjeto() = 0;
        virtual string getSerializacion() = 0;
        virtual void agregarSeparador() = 0;
    
    protected:
        string serializacion;

};



#endif