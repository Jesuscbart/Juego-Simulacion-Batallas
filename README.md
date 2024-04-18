# Trabajo Programación 2 - ¡A luchar!

El trabajo consiste en un videojuego que simula batallas entre dos equipos compuestos por personajes. Cada equipo cuenta con el mismo número de personajes al comienzo de cada partida, que se generarán de manera aleatoria de entre los dos tipos de personajes que hay: bárbaros y magos. Estos personajes se generan con unas estadísticas aleatorias dentro de unos parámetros establecidos.

## Personajes

En nuestro juego hay disponibles dos tipos de personajes:

Ambos tipos de personajes cuentan con las siguientes estadísticas de base:

* La **vida** está comprendida entre los 50 y los 100 puntos de salud.  
* El **ataque** simple efectuará entre 10 y 50 puntos de daño.  
* La **defensa** estará comprendida entre los 10 y los 100 puntos.  

Adicionalmente, cada personaje tendrá un **ataque propio** y unas **estadísticas defensivas modificadas** en base a su tipo.

### Bárbaro

El *bárbaro* tiene una **vida** comprendida entre los 50 y los 100 puntos de salud.

Como todos los personajes, el bárbaro cuenta con un **ataque simple**. Este ataque simple se generará de manera aleatoria con el personaje y efectuará entre 10 y 50 puntos de daño. A partir de este ataque simple se generará su **ataque de bárbaro** que ocasionará el daño de su ataque simple sumado a un porcentaje aleatorio de entre 5% y 40% de su ataque simple.

* A Bárbaro = A Simple + (5%-40%) · A Simple

Finalmente, posee una **defensa** propia que modifica la defensa base generada (entre 10 y 100 puntos), multiplicándola entre un 25% y un 125%. Los bárbaros son la tropa con más defensa.

* D Bárbaro = D Generada · (25%-125%)

### Mago

El *mago* tiene una vida comprendida entre los 50 y los 100 puntos de salud.

Al igual que el resto, el mago cuenta con un **ataque simple** que se generará de manera aleatoria con el personaje y efectuará entre 10 y 50 puntos de daño.
A partir de este ataque simple se generará su **ataque de mago** que ocasionará el daño de su ataque simple sumado a un porcentaje aleatorio de entre 10% y 55% de su ataque simple. Los magos son la tropa con más daño de ataque.

* A Mago = A Simple + (10%-55%) · A Simple

Finalmente, posee una defensa propia que modifica la defensa base generada (entre 10 y 100 puntos), multiplicándola entre un 15% y un 85%. Al ser un mago, su defensa es menor.

* D Bárbaro = D Generada · (15%-85%)

## Menú

El menú de nuestro juego está compuesto de 4 opciones:

**1. Crear los 2 equipos** 

Cada vez que se pulsa esta opción, se añaden 10 personajes a cada equipo. Las batallas pueden ser de más de 10 vs 10, pero el número de tropas de cada bando siempre va a ser el mismo al inicio de cada batalla.

**2. Mostrar los 2 equipos**

Esta función del menú muestra por pantalla a los dos equipos. Se muestra cada personaje indicando el tipo de tropa que es, su vida, su ataque simple, su defensa y su ataque particular. Esta opción se puede escoger después de la creación de los equipos, o después de la batalla, mostrando las tropas que han quedado con vida.

**3. Comenzar la batalla**

Esta función simula la batalla, mostrando por pantalla el número de luchadores que quedan con vida en cada equipo después de cada pelea.

**4. Salir del programa**

## Sistema de batalla

Se enfrentan los dos equipos con el mismo número de personajes. Cada partida se compone de turnos en los cuales cada luchador se enfrentará al del equipo adversario que ocupa la misma posición, aleatorizando cuál de la pareja comienza atacando para hacerlo lo más equilibrado posible. Estos combaten hasta que uno de los dos muera. Cuando esto ocurre, luchan los siguientes. Cuando el turno acaba, los personajes muertos son eliminados. Se equilibran los equipos según la vida que queda a cada personaje y se empieza otro turno. Cada batalla individual es siempre de 1 vs 1. Cuando uno de los dosequipos se queda sin jugadores, termina la batalla ganando el equipo en el que quedan personajes con vida. Puede darse empate si los últimos luchadores de cada equipo mueren a la vez, habiendo lanzado el mago, por ejemplo, su ataque mágico justo antes de morir. (Esto está hecho así a propósito, de manera que se pueda terminar completamente cada “turno de ataque”)