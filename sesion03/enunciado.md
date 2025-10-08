Diseña un programa para gestionar un sistema simple de **biblioteca**.

1. Define una clase base `Publicacion` que tenga:

   * Atributos: `titulo` (string), `anio` (int).
   * Método `mostrarInfo()` que imprima la información.

2. Define una clase derivada `Libro` que herede de `Publicacion` y agregue:

   * Atributo: `autor` (string).
   * Redefina el método `mostrarInfo()` para incluir el autor.

3. En la función `main`:

   * Crea un `vector<Libro>` para almacenar varios libros.
   * Implementa las siguientes operaciones usando **únicamente** las funciones vistas en las diapositivas:

     * Agregar libros con `push_back`.
     * Mostrar todos los libros recorriendo el vector de **tres formas diferentes** (for clásico, for-each, iteradores).
     * Eliminar el último libro ingresado con `pop_back`.
     * Consultar el primero y el último libro con `front` y `back`.
     * Ordenar el vector por año de publicación usando `sort` junto con `begin()` y `end()`.
     * Usar `size` y `empty` para verificar el estado del vector antes de mostrar resultados.
