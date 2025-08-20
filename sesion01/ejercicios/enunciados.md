# Ejercicio 1: Cuenta Bancaria con operaciones básicas y transferencias

**Objetivo:** Modelar una cuenta bancaria y realizar operaciones entre objetos.

1. Implementa la clase `CuentaBancaria` con los **atributos privados**:

   * `numero` (string), `titular` (string), `saldo` (double).
2. Provee **dos constructores**:

   * Por defecto (cuenta vacía con saldo 0).
   * Parametrizado: recibe `numero`, `titular` y `saldoInicial` (si `saldoInicial` < 0, forzar a 0).
3. Implementa los **métodos públicos**:

   * `bool depositar(double monto)`: acepta solo `monto > 0`.
   * `bool girar(double monto)`: no permite dejar el saldo en negativo.
   * `bool transferir(CuentaBancaria& destino, double monto)`: usa `girar` y `depositar`.
   * `double obtenerSaldo()`: retorna el saldo actual.
   * `void imprimirResumen()`: muestra `numero`, `titular` y `saldo`.
4. En `main`:

   * Crea **tres** cuentas.
   * Realiza **2 transferencias válidas** y **1 inválida** (por falta de fondos o monto no válido).
   * Imprime el resumen de al menos dos cuentas antes y después de las operaciones.

---

# Ejercicio 2: Biblioteca

**Objetivo:** Clases relacionadas y operaciones que cambian el estado del objeto.

1. Clase `Libro` (atributos privados): `titulo`, `autor`, `isbn`, `disponible` (bool).

   * Constructores: por defecto y parametrizado (inicialmente `disponible = true` si no se indica).
   * Métodos:

     * `bool prestar()`: solo si está disponible.
     * `bool devolver()`: solo si estaba prestado.
     * `void imprimir()`: muestra título, autor, ISBN y estado (“Disponible”/“Prestado”).
     * Getters mínimos para `isbn` y `disponible`.
2. Clase `Biblioteca`:

   * Contiene un **arreglo fijo** de `Libro` de tamaño máximo **50** (no usar `vector`).
   * Lleva un **contador** de elementos usados.
   * Métodos:

     * `bool agregar(Libro l)`: falla si está llena o si el ISBN ya existe.
     * `Libro* buscarPorISBN(string isbn)`: retorna puntero o `nullptr` (0).
     * `bool prestarPorISBN(string isbn)`: usa `buscarPorISBN` y `prestar`.
     * `bool devolverPorISBN(string isbn)`: usa `buscarPorISBN` y `devolver`.
     * `void listarDisponibles()`: imprime solo los libros disponibles.
3. En `main`:

   * Agrega **al menos 5** libros.
   * Presta **2** (intenta prestar **uno repetido** para forzar fallo).
   * Devuelve **1**.
   * Intenta agregar un libro con **ISBN duplicado** (debe fallar).
   * Lista los libros **disponibles** al final.
