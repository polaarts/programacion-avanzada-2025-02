#include <bits/stdc++.h>
using namespace std;

/*

## Pregunta 1

Un grupo de amigos, fanáticos de los juegos de mesa y de la 
programación en C++, inventó un tablero con **100 casillas**.

En cada casilla hay un número entero entre **-1 y 3 (excluyendo
 el 0)**. Ese número indica cuántas posiciones debe avanzar el 
 jugador desde esa casilla.

**Reglas del movimiento:**

1. El juego comienza en la casilla 0.
2. En cada turno se lee el valor de la casilla y se 
avanza esa cantidad.
3. Si se cae en una casilla con valor **-1**, el jugador 
**pierde automáticamente**.
4. Si el jugador logra avanzar más allá de la casilla 99, 
se considera que **ganó**, imprimiéndose el número de pasos utilizados.

*/

/*

#### Clase `Movimiento` (10 puntos)

* Escriba la clase con un **constructor parametrizado** que reciba el valor del paso.
* El constructor debe **validar** que el paso esté en el rango válido (-1, 1, 2 o 3).
  En caso contrario, el paso debe quedar en **1 por defecto**.
* Incluya el **método get** necesario para acceder al valor de `paso`.

*/

class Movimiento {
    int paso;
public:
    Movimiento(int p) {
     if(p == -1 || p == 1 || p == 2 || p == 3) paso = p;
     else paso = 1;
    }

    int getPaso() { return paso; }
};

/*

#### Clase `CaminoHaciaFinal` (5 puntos)

* Contendrá un **atributo privado** llamado `camino`, que es un 
**arreglo de 100 punteros a objetos `Movimiento`**.
* No es necesario que el constructor genere ni llene los objetos; s
e asume que el arreglo ya contiene datos válidos.

*/

class CaminoHaciaFinal {
    Movimiento* camino[100];
public:

    CaminoHaciaFinal(Movimiento* arreglo[100]) {
        for (int i = 0; i < 100; ++i) camino[i] = arreglo[i];
    }

/*

#### Método `void pasosHaciaFinal()` (15 puntos)

Debe programar un método que **calcule cuántos movimientos 
realiza el jugador** desde la casilla 0 
hasta sobrepasar la casilla 99 (recuerde que el arreglo parte de 
la posición 0).

*/

    void pasosHaciaFinal() {
        int posicion = 0, pasos = 0;
        while (posicion <= 99){
            int valor = camino[posicion]->getPaso();
            if (valor == -1){
                cout << "Perdiste" << endl;
                return;
            }

            posicion += valor;
            ++pasos;
        }
        cout << pasos << endl;
    }
};


/*

## Pregunta 2

En la **Municipalidad de Los Laureles**, los alumnos que postulan 
a un colegio deben participar en una **“tómbola”** que, de acuerdo 
con los cupos disponibles, los asigna a uno de los **dos colegios** 
que eligieron al postular (colegios **A30** y **A31**, respectivamente,
 únicos existentes en la comuna).

Cada alumno debe indicar las **dos opciones de colegio en orden de 
prioridad**.
Si el colegio de primera prioridad no tiene cupo, se intentará con 
la segunda opción.
Si no logra entrar en ninguna de las dos opciones, quedará dentro 
de una **lista de rezagados**.
*/

/*

#### Clase `Alumno` (5 puntos)

* Atributos privados: `rut`, `nombre`, `colegio1`, `colegio2` (primera 
y segunda opción del alumno).
* Incluya un **constructor parametrizado** para inicializar los 
atributos.
* Método `imprimir()` que muestre todos los datos del alumno.

*/

class Alumno {
    string rut, nombre, colegio1, colegio2;
public:
    Alumno() : rut(""), nombre(""), colegio1(""), colegio2("") {}
    Alumno(string r, string n, string c1, string c2) {}

    string getColegio1() { return colegio1; }
    string getColegio2() { return colegio2; }
    string getNombre() { return nombre; }
    string getRut() { return rut; }

    void imprimir() {
        cout << rut << " - " << nombre << " - " << colegio1 << " - " << colegio2 << "\n";
    }
};


/*

#### Clase `Colegios`

* Atributos: tres arreglos de objetos `Alumno`

  * `colegioA30[300]`
  * `colegioA31[300]`
  * `rezagados[2000]`
    Representando los alumnos asignados a cada colegio y los rezagados.

*/

/*

Debe programar la **estructura de la clase** (atributos) y su **constructor**.

*/

class Colegios {
    Alumno colegioA30[300];
    Alumno colegioA31[300];
    Alumno rezagados[2000];
    int nA30, nA31, nRez;
public:
    Colegios() : nA30(0), nA31(0), nRez(0) {}

/*

Agrega al alumno que recibe como parámetro al colegio A30 
**en caso de que encuentre cupo (retorna `true`)**;
si no encuentra cupo, debe **retornar `false`**.

> **Nota:** Se asume que existen también los métodos
> `bool agregarAlumnoA31(Alumno* a)` y `bool agregarRezagados(Alumno* a)`,
> que se comportan igual que `agregarAlumnoA30`.
> **Usted no debe programar estos métodos, pero sí asumir su existencia.**

*/

    bool agregarAlumnoA30(Alumno* a) {
        if (nA30 >= 300) return false;
        colegioA30[nA30++] = *a;
        return true;
    }

    bool agregarAlumnoA31(Alumno* a) {
        if (nA31 >= 300) return false;
        colegioA31[nA31++] = *a;
        return true;
    }

    bool agregarRezagados(Alumno* a) {
        if (nRez >= 2000) return false;
        rezagados[nRez++] = *a;
        return true;
    }

/*
    
Intenta ubicar al alumno en su primera o segunda prioridad;
si no hay cupo en ninguna, va a rezagados.
Debe imprimir el resultado de la asignación.

*/

    void agregarAlumno(Alumno* a) {
        string c1 = a->getColegio1();
        string c2 = a->getColegio2();
        bool asignado = false;

        if (c1 == "A30") asignado = agregarAlumnoA30(a);
        else if (c1 == "A31") asignado = agregarAlumnoA31(a);
        if (asignado) {
            cout << "Asignado a " << c1 << ": " << a->getRut() << " - " << a->getNombre() << endl;
            return;
        }

        if (c2 == "A30") asignado = agregarAlumnoA30(a);
        else if (c2 == "A31") asignado = agregarAlumnoA31(a);
        if (asignado) {
            cout << "Asignado a " << c2 << ": " << a->getNombre() << endl;
            return;
        }

        agregarRezagados(a);
        cout << "Rezagado (1ra prioridad " << c1 << "): " << a->getNombre() << endl;
    }

/*

Muestra los alumnos asignados a cada colegio.

*/    
    void imprimirAsignados() {
        cout << "Colegios A30 (" << nA30 << ")\n";
        cout << "Colegios A31 (" << nA31 << ")\n";
    }

/*

Muestra los alumnos rezagados indicando cuál fue su primera prioridad.

*/    
    void imprimirRezagados() {
        cout << "Rezagados (" << nRez << ")\n";
        for (int i = 0; i < nRez; ++i) {
            rezagados[i].imprimir();
        }
    }
};