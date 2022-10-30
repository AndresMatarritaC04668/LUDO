#ifndef _FICHA_LUDO
#define _FICHA_LUDO

#include <stdbool.h>
#include <string>
#include "FichaAbstracta.h"

class FichaLudo : public FichaAbstracta {

    private:
        std::string color;
        bool activo;       
        int pasosDados;
        int zonaSegura;
        int caminoFinal;
        

    public:
        FichaLudo();
        FichaLudo(std::string, int);
        std::string getColor() override;
        int getPos()override;
        int getEstado()override;
        bool getFinalizado()override;
        int getPasosDados();
        int getZonaSegura();
        void setPasosDados(int pasos);
        void setPosicion(int posicion)override;
        void activarFicha();
        void desactivarFicha();

};



#endif