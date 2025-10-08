---

# PRIMERA SOLEMNE PROGRAMACIÓN AVANZADA — CIT1010

**Semestre:** Primavera 2025
**Duración:** 120 minutos
**Puntaje total:** 60 puntos

---

## Pregunta 1 — 30 puntos

Un grupo de amigos, fanáticos de los juegos de mesa y de la programación en C++, inventó un tablero con **100 casillas**.

En cada casilla hay un número entero entre **-1 y 3 (excluyendo el 0)**. Ese número indica cuántas posiciones debe avanzar el jugador desde esa casilla.

**Ejemplo:**

Si estoy en la casilla 3 y el número en esa casilla es 2, entonces avanzo hasta la casilla 5 y desde ahí hasta la 8 y así sucesivamente.

El tablero puede representarse como un **arreglo de 100 objetos de la clase `Movimiento`**.
Cada objeto `Movimiento` guarda un único atributo entero llamado `paso`, cuyo valor está entre -1 y 3 (pero nunca 0).

---

### Se pide

#### Clase `Movimiento` (10 puntos)

* Escriba la clase con un **constructor parametrizado** que reciba el valor del paso.
* El constructor debe **validar** que el paso esté en el rango válido (-1, 1, 2 o 3).
  En caso contrario, el paso debe quedar en **1 por defecto**.
* Incluya el **método get** necesario para acceder al valor de `paso`.

---

#### Clase `CaminoHaciaFinal` (5 puntos)

* Contendrá un **atributo privado** llamado `camino`, que es un **arreglo de 100 punteros a objetos `Movimiento`**.
* No es necesario que el constructor genere ni llene los objetos; se asume que el arreglo ya contiene datos válidos.

---

#### Método `void pasosHaciaFinal()` (15 puntos)

Debe programar un método que **calcule cuántos movimientos realiza el jugador** desde la casilla 0 hasta sobrepasar la casilla 99 (recuerde que el arreglo parte de la posición 0).

**Reglas del movimiento:**

1. El juego comienza en la casilla 0.
2. En cada turno se lee el valor de la casilla y se avanza esa cantidad.
3. Si se cae en una casilla con valor **-1**, el jugador **pierde automáticamente**.
4. Si el jugador logra avanzar más allá de la casilla 99, se considera que **ganó**, imprimiéndose el número de pasos utilizados.

---

## Pregunta 2 — 30 puntos

En la **Municipalidad de Los Laureles**, los alumnos que postulan a un colegio deben participar en una **“tómbola”** que, de acuerdo con los cupos disponibles, los asigna a uno de los **dos colegios** que eligieron al postular (colegios **A30** y **A31**, respectivamente, únicos existentes en la comuna).

Cada alumno debe indicar las **dos opciones de colegio en orden de prioridad**.
Si el colegio de primera prioridad no tiene cupo, se intentará con la segunda opción.
Si no logra entrar en ninguna de las dos opciones, quedará dentro de una **lista de rezagados**.

**Ejemplo:**

Un alumno que postuló como primera opción al colegio A30 y segunda opción al colegio A31 será tratado así:

1. Si hay cupo en A30, queda asignado ahí.
2. Si no hay cupo, se intenta en A31.
3. Si no queda en ninguno, pasa a la lista de rezagados.

---

### Se pide

#### Clase `Alumno` (5 puntos)

* Atributos privados: `rut`, `nombre`, `colegio1`, `colegio2` (primera y segunda opción del alumno).
* Incluya un **constructor parametrizado** para inicializar los atributos.
* Método `imprimir()` que muestre todos los datos del alumno.

---

#### Clase `Colegios`

* Atributos: tres arreglos de objetos `Alumno`

  * `colegioA30[300]`
  * `colegioA31[300]`
  * `rezagados[2000]`
    Representando los alumnos asignados a cada colegio y los rezagados.

##### (5 puntos)

Debe programar la **estructura de la clase** (atributos) y su **constructor**.

---

### Métodos

#### (5 puntos) `bool agregarAlumnoA30(Alumno* a)`

Agrega al alumno que recibe como parámetro al colegio A30 **en caso de que encuentre cupo (retorna `true`)**;
si no encuentra cupo, debe **retornar `false`**.

> **Nota:** Se asume que existen también los métodos
> `bool agregarAlumnoA31(Alumno* a)` y `bool agregarRezagados(Alumno* a)`,
> que se comportan igual que `agregarAlumnoA30`.
> **Usted no debe programar estos métodos, pero sí asumir su existencia.**

---

#### (5 puntos) `void agregarAlumno(Alumno* a)`

Intenta ubicar al alumno en su primera o segunda prioridad;
si no hay cupo en ninguna, va a rezagados.
Debe imprimir el resultado de la asignación.

---

#### (5 puntos) `void imprimirAsignados()`

Muestra los alumnos asignados a cada colegio.

---

#### (5 puntos) `void imprimirRezagados()`

Muestra los alumnos rezagados indicando cuál fue su primera prioridad.

---