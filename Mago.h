//PROYECTO PROGRAMACION 2-JESUS CUESTA BARTOLOME Y ALEJANDRO RIEGO VELASCO
#ifndef MAGO_H
#define MAGO_H


#include "Personaje.h"

using namespace std;

class mago: public personaje{
    public:

    mago(){
        int x=(get_ataque_simple()+(get_ataque_simple()*((10+rand() % (55 +1 - 10)))/100));
        ataque_magico=x; //Al crear el mago le asignamos un ataque especial en función de su ataque base
        int y=((getdefensa()*(15+rand() % (85 +1 - 15)))/100) ;
        setdefensa(y); //Al ser un mago tiene menos defensa
    }

    int Ataque(){//Se aleatoriza el ataque que usa (el base o el especial)
        if (Aleatorio()==true){ //-> True=Especial
            return ataque_magico;
        }
        else {//->False=Simple
            return get_ataque_simple();
        }
        return 0;
    }

    string who() const {return "Mago";}

    int get_ataque_magico() const {return ataque_magico;}

    private:

    int ataque_magico{0}; //Para mago

};

std::ostream& operator<<(std::ostream& os, mago const & a){
    os<<"--------------Mago--------------"<<endl;
    os<<"Vida: "<<a.personaje::getvida()<<endl;
    os<<"Ataque simple: "<<a.personaje::get_ataque_simple()<<endl;
    os<<"Defensa: "<<a.personaje::getdefensa()<<endl;
    os<<"Ataque magico: "<<a.get_ataque_magico()<<endl;
    return os;
}

#endif // MAGO_H


