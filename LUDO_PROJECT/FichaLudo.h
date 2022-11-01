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
        int numeroFicha;
        

    public:
        FichaLudo();
        FichaLudo(std::string, int,int);
        ~FichaLudo()override;
        std::string getColor() override;
        int getX()override;
        int getY()override;
        int getEstado()override;
        bool getFinalizado()override;
        int getPasosDados()override;
        int getZonaSegura();
        void setPasosDados(int pasos);
        void setPosicion(int x,int y)override;
        void activarFicha();
        void desactivarFicha();
        int getNumeroFicha()override;
        void setFinalizado();
        void setEstadoActivo();
    

};



#endif
