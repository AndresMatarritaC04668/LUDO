#ifndef _DADO
#define _DADO

#include <stdlib.h>
#include <string>
#include <time.h>


class Dado {


    public:
        Dado(){
            srand(time(NULL));
        }
        
        int lanzar() {
            return (1 + rand() % (7 - 1));
        }

};



#endif