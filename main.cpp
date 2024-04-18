//PROYECTO PROGRAMACION 2-JESUS CUESTA BARTOLOME Y ALEJANDRO RIEGO VELASCO

#include <vector>
#include <memory>
#include <ctime>
#include "FuncionesYMenu.h"

using namespace std;

//int main(){
//    while (true){
//    vector<shared_ptr<personaje>> Equipo1, Equipo2;
//    CrearEquipo(Equipo1,10);
//    CrearEquipo(Equipo2,10);
//    Combate(Equipo1,Equipo2);
//    }
//}



int main()
{
    vector<shared_ptr<personaje>> Equipo1, Equipo2;
    int opcion=0;
    bool check{false}; //Comprueba si se han generado nuevos equipos desde la batalla anterior

    do {
    opcion=menu();

    switch (opcion){

    case 1 :
        CrearEquipo(Equipo1,10);
        CrearEquipo(Equipo2,10);
        check=true;
        cout<<"Se han creado los equipos"<<endl;
        break;

    case 2 :
        if (Equipo1.size()>0 or Equipo2.size()>0){
        cout<<"Se le mostraran los equipos"<<endl;
        cout<<"===================Equipo 1==================="<<endl;
        MostrarEquipo(Equipo1);
        cout<<"===================Equipo 2==================="<<endl;
        MostrarEquipo(Equipo2);
        }
        else{cout<<"Ambos equipos estan vacios"<<endl;}
        break;
    case 3 :
        if (check==true){
        cout<<"Comienza la batalla!!!"<<endl;
        Combate(Equipo1,Equipo2);
        check=false;
        }
        else {
        cout<<"No ha creado nuevos equipos desde la ultima batalla, no hay con quien combatir"<<endl<<endl;
        }

        break;

    case 4 :

        cout<<"Apagando..."<<endl;

        break;
    default : //Si no selecciona una opcion

        cout<<"Seleccione una opción valida"<<endl;

        break;
    }

    }
    while (opcion!=4); //La opcion del menú que lo "apague" , si existe la opcion, primero se ejecuta y luego sale del bucle


    return 0;
}
