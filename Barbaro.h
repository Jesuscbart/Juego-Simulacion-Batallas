//PROYECTO PROGRAMACION 2-JESUS CUESTA BARTOLOME Y ALEJANDRO RIEGO VELASCO
#ifndef BARBARO_H
#define BARBARO_H

#include "Personaje.h"

using namespace std;

class barbaro: public personaje{
    public:

    barbaro(){
        int x=(get_ataque_simple()+(get_ataque_simple()*((5+rand() % (40 +1 - 5)))/100));
        ataque_barbaro=x; //Al crear el barbaro le asignamos un ataque especial en función de su ataque base
        int y=((getdefensa()*(25+rand() % (125 +1 - 25)))/100) ;
        setdefensa(y); //Al ser un bárbaro tiene más defensa
    }

    int Ataque(){//Se aleatoriza el ataque que usa (el base o el especial)
        if (Aleatorio()==true){ //-> True=Especial
            return ataque_barbaro;
        }
        else {//->False=Simple
            return get_ataque_simple();
        }
        return 0;
    }

    string who() const {return "Barbaro";}

    int get_ataque_barbaro() const {return ataque_barbaro;}

    private:

    int ataque_barbaro{0}; //Para barbaro

};

std::ostream& operator<<(std::ostream& os, barbaro const & a){
    os<<"--------------Barbaro--------------"<<endl;
    os<<"Vida: "<<a.personaje::getvida()<<endl;
    os<<"Ataque simple: "<<a.personaje::get_ataque_simple()<<endl;
    os<<"Defensa: "<<a.personaje::getdefensa()<<endl;
    os<<"Ataque barbaro: "<<a.get_ataque_barbaro()<<endl;
        return os;
}

#endif // BARBARO_H
