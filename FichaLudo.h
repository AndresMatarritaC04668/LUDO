#ifndef _FICHA_LUDO
#define _FICHA_LUDO

#include <stdbool.h>
#include <string>
#include "FichaAbstracta.h"

class FichaLudo : public FichaAbstracta {

    private:
        std::string color;
        int pos;
        bool activo;
        int finalizado;
        int pasosDados;
        

    public:
        FichaLudo();
        FichaLudo(std::string, int, int);
        std::string getColor() override;
        int getPos()override;
        int getEstado()override;
        bool getFinalizado()override;
        void setPasosDados(int pasos);
        void setPosicion(int posicion);

};



#endif