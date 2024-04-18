//PROYECTO PROGRAMACION 2-JESUS CUESTA BARTOLOME Y ALEJANDRO RIEGO VELASCO
#ifndef FUNCIONESYMENU_H
#define FUNCIONESYMENU_H

#include <vector>
#include <memory>
#include <ctime>
#include <algorithm>
#include "Barbaro.h"
#include "Mago.h"
#include "Personaje.h"


using namespace std;

std::ostream& operator<<(std::ostream& os, shared_ptr<personaje> const & a){ //Sobrecarga con downcasting para mostrar los equipos
       os<<"--------------"<<a->who()<<"--------------"<<endl;
       os<<"Vida: "<<a->personaje::getvida()<<endl;
       os<<"Ataque simple: "<<a->personaje::get_ataque_simple()<<endl;
       os<<"Defensa: "<<a->personaje::getdefensa()<<endl;
       if (a->who()=="Barbaro"){
           barbaro* t = dynamic_cast <barbaro*>(a.get());                   //Utilizamos downcasting para acceder a las funciones de las clases hijas
           os<<"Ataque barbaro: "<<t->get_ataque_barbaro()<<endl;
        }
       else {
           mago* t = dynamic_cast <mago*>(a.get());                        //Utilizamos downcasting para acceder a las funciones de las clases hijas
       os<<"Ataque magico: "<<t->get_ataque_magico()<<endl;
   }
  return os;
}

void CrearEquipo(vector<shared_ptr<personaje>> &Equipo, int num){ //Crea un equipo con el numero de personajes pasados como parametro (ampliabilidad)

        for (int aux=num;aux>0;--aux){
            if (Aleatorio()){
                barbaro a;
                Equipo.push_back(make_shared<barbaro>(a));
            }
            else {
                mago b;
                Equipo.push_back(make_shared<mago>(b));
            }
        }
}


void MostrarEquipo(const vector<shared_ptr<personaje>> &Equipo){ //Muestra el equipo
    for (auto const & elem:Equipo){
    cout<<elem<<endl;
    }
}


bool ComparadorVidaTotal(const shared_ptr<personaje> &p1,const shared_ptr<personaje> &p2){return (p1->getvida()+p1->getdefensa())>(p2->getvida()+p2->getdefensa());}


void EliminarMuertos(vector<shared_ptr<personaje>> &Equipo){

    sort(Equipo.begin(),Equipo.end(),ComparadorVidaTotal); //Ordenamos el vector segun la vida de los personajes (se usa tras la primera batalla a muerte)
                                                                                                //Se ordenan para enfrentar los que tienen mas vida entre si y "balancearlo"

    for (int k=Equipo.size()-1;k>=0;--k){
        if (Equipo.at(k)->getvida()==0){
            Equipo.pop_back();
        }
    }
}


//Se enfrentan dos equipos con el mismo numero de jugadores
//Solo por referencia porque los personajes que mueren no siguen en el juego, se pierden sus almas....
void Combate( vector<shared_ptr<personaje>> &Equipo1,vector<shared_ptr<personaje>> &Equipo2){
    int x=Equipo1.size()-1; //Inicializamos el combate con el numero de jugadores (del turno)
    int cont{0};
    while (Equipo1.size()>0 and Equipo2.size()>0){ //Mientras que queden vivos personajes en los dos equipos , combaten

        if (Equipo1.size()>Equipo2.size()){x=Equipo2.size()-1;} //Recorremos los equipos de principio a fin, para evitar "out_of_range"
        else {x=Equipo1.size()-1;}                                                //Hacemos que el tope sea el valor del vector con menos personajes

        for (;x>=0;--x){ //Recorremos haciendo que luchen los personajes de las mismas posiciones
            if (Aleatorio()==true){ //Aleatorizamos quien ataca primero-> True=Equipo 1
                while (Equipo1.at(x)->getvida()>0 and Equipo2.at(x)->getvida()>0){ //Combaten hasta que uno muera
                        Equipo2.at(x)->Recibir_dano(Equipo1.at(x)->Ataque());

                        Equipo1.at(x)->Recibir_dano(Equipo2.at(x)->Ataque());
                    }
            }

            else { //->False=Equipo 2
                while (Equipo1.at(x)->getvida()>0 and Equipo2.at(x)->getvida()>0){ //Combaten hasta que uno muera
                        Equipo1.at(x)->Recibir_dano(Equipo2.at(x)->Ataque());

                        Equipo2.at(x)->Recibir_dano(Equipo1.at(x)->Ataque());

                    }
            }
        }
    //Una vez recorrido todo, sacamos los personajes muertos del vector antes de que se recalibre la lucha
    EliminarMuertos(Equipo1);
    EliminarMuertos(Equipo2);

        ++cont;
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<"Pelea "<<cont<<" terminada!"<<endl;
    cout<<"Quedan "<<Equipo1.size()<<" luchadores del primer equipo"<<endl;
    cout<<"Quedan "<<Equipo2.size()<<" luchadores del segundo equipo"<<endl;
    cout<<"----------------------------------------------------------------------------"<<endl;
    }
    cout<<"============================================"<<endl<<endl;
    if (Equipo1.size()>Equipo2.size()){cout<<"Ha ganado el primer equipo!!!"<<endl<<endl;}
    else if  (Equipo1.size()<Equipo2.size()){cout<<"Ha ganado el segundo equipo!!!"<<endl<<endl;}
    else {cout<<"Ha habido empate, sus ultimos ataques llegaron a la vez!!!"<<endl<<endl;}
    cout<<"============================================"<<endl;

}


int menu(void){ //Menu Generico
    int opcion= 0;
    cout<<"============================================================="<<endl;
    cout<<endl<<"Bienvenido a FightJyR , seleccione una opcion"<<endl<<endl;
    cout<<"1. Crear los 2 equipos"<<endl;
    cout<<"2. Mostrar los 2 equipos"<<endl;
    cout<<"3. Comenzar la batalla"<<endl;
    cout<<"4.Salir del programa"<<endl<<endl;
    cout<<"============================================================="<<endl;
    cout<<endl;
    cin>>opcion;
    cout<<endl;

    return opcion;
}


#endif // FUNCIONESYMENU_H
