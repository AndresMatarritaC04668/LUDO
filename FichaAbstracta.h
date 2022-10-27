#ifndef _FICHAABSTRACTA
#define _FICHAABSTRACTA

#include <stdbool.h>
#include <string>

class FichaAbstracta {

    public:
        FichaAbstracta(){};

        virtual std::string getColor() = 0;
        virtual int getPos() = 0;
        virtual int getEstado() = 0;
        virtual bool getFinalizado() = 0;
        virtual void setPosicion(int posicion) = 0;
    protected:
        int finalizado;
        int pos;
};



#endif