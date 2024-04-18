//PROYECTO PROGRAMACION 2-JESUS CUESTA BARTOLOME Y ALEJANDRO RIEGO VELASCO
#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <ctime>
#include <memory>

using namespace std;

class personaje{
    public:

    personaje(){ //Constructor de personaje, genera las caracteristicas comunes de los personajes aleatoriamente de 0 a 100
        vida=50+rand() % (100 +1 - 50) ; //El minimo de vida  es 50
        ataque_simple=10+rand() % (50 +1 - 10) ; //El minimo de ataque base es 10 - El maximo es 50
        defensa=10+rand() % (100 +1 - 10) ; //El minimo de defensa es 10
    }

    virtual  ~personaje(){}; //Destructor virtual

    //Getters y setters
    virtual int Ataque()=0; //Un mago ataca diferente que un barbaro (ataque magico y ataque fisico)

    virtual string who() const =0; //Funcion para identificar el tipo de personaje

    void Recibir_dano(int ataque){ //Funcion que todos tienen, ya que recibir daño es parte del juego

        if (defensa>0){ //Si tiene escudo
            if (ataque>defensa){ //Si el ataque quita mas vida que el escudo
               int dano=defensa-ataque;
               defensa=0;
               vida=vida+dano;
            }
           else {//Si el ataque especial quita menos vida (o lo mismo) que el escudo
               defensa=defensa-ataque;
           }
        }
        else { //Si no le queda escudo
            if (ataque>vida){vida=0;} //Si lo mata con ese golpe
                else{vida=vida-ataque;} //Si no lo mata con ese golpe (o hace el mismo daño)
        }

    }

    //Getters y setters comunes a los personajes
    int getvida()const {return vida;}
    void setvida(int vida){this->vida=vida;}

    int get_ataque_simple()const {return ataque_simple;}

    int getdefensa()const {return defensa;}
    void setdefensa(int defensa){this->defensa=defensa;}

    private:
    int vida{0}; //Vida del personaje
    int ataque_simple{0}; //"Fuerza de ataque" base del personaje
    int defensa{0}; //Escudo del personaje

};

bool Aleatorio(){return rand()%2;} //Genera un numero aleatorio (0-1)

#endif // PERSONAJE_H
