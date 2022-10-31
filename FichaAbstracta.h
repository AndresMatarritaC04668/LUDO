#ifndef _FICHAABSTRACTA
#define _FICHAABSTRACTA

#include <stdbool.h>
#include <string>


class FichaAbstracta {

    public:
        FichaAbstracta(){};
        virtual ~FichaAbstracta(){};
        virtual std::string getColor() = 0;
        virtual int getX() = 0;
        virtual int getY() =0;
        virtual int getEstado() = 0;
        virtual bool getFinalizado() = 0;
        virtual void setPosicion(int x , int y) = 0;
    protected:
        int finalizado;
        int x;
        int y;
};



#endif