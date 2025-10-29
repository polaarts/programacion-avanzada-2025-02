# Ayudantia 6

Has obtenido datos de la **PokéAPI** (https://pokeapi.co/) en formato JSON y ahora necesitas crear un sistema de gestión de Pokédex.

La estructura principal del sistema debe usar **obligatoriamente** `std::map<int, Pokemon>` donde la clave es el ID del Pokémon y el valor es un objeto completo de tipo `Pokemon`.

## Datos de Ejemplo de la PokéAPI

A continuación se muestra un fragmento de los datos que retorna la API para un Pokémon (Ditto, ID: 132):

```json
{
  "id": 132,
  "name": "ditto",
  "height": 3,
  "weight": 40,
  "base_experience": 101,
  "types": [
    {
      "slot": 1,
      "type": {
        "name": "normal"
      }
    }
  ],
  "stats": [
    {
      "base_stat": 48,
      "stat": {
        "name": "hp"
      }
    },
    {
      "base_stat": 48,
      "stat": {
        "name": "attack"
      }
    },
    {
      "base_stat": 48,
      "stat": {
        "name": "defense"
      }
    }
  ]
}
```

---

## Parte 1: Clase Pokemon

Implementa una clase `Pokemon` que modele la información de un Pokémon obtenida de la API.

### Atributos privados:
- `int id` - Identificador único del Pokémon
- `string name` - Nombre del Pokémon
- `int height` - Altura en decímetros
- `int weight` - Peso en hectogramos
- `int base_experience` - Experiencia base que otorga
- `string type` - Tipo principal (ej: "fire", "water", "normal")
- `int hp` - Puntos de vida base
- `int attack` - Ataque base
- `int defense` - Defensa base

### Métodos públicos requeridos:

```cpp
// Constructores
Pokemon(int id, string name, int height, int weight, 
        int base_experience, string type, 
        int hp, int attack, int defense);
Pokemon(); // Constructor por defecto

// Getters (todos los atributos)
int getId();
string getName();
// ... etc.

// Métodos adicionales
int calcularPoderTotal() const;  // Retorna hp + attack + defense
double getPesoKg() const;        // Convierte hectogramos a kilogramos
double getAlturaMetros() const;  // Convierte decímetros a metros
void mostrarInfo() const;        // Imprime información formateada
void mostrarResumen() const;     // Imprime resumen en una línea
```

---

## Parte 2: Clase Pokedex

Implementa una clase `Pokedex` que gestione una colección de Pokémon usando map.

### Atributo privado:
```cpp
map<int, Pokemon> pokemons;
```

### Métodos públicos requeridos:

#### Operaciones básicas de map:
```cpp
void agregarPokemon(const Pokemon& pokemon);
// Usa insert() para agregar el Pokemon al map

Pokemon* buscarPorId(int id);
// Usa find() para buscar. Retorna puntero al Pokemon o nullptr

bool existePokemon(int id);
// Usa count() o find() para verificar existencia

bool eliminarPokemon(int id);
// Usa erase() para eliminar. Retorna true si se eliminó

int cantidadPokemons() const;
// Usa size() para obtener la cantidad
```

#### Búsquedas y análisis (requieren iterar el map):
```cpp
Pokemon* buscarPorNombre(const string& name);
// Itera el map para buscar por nombre

Pokemon* obtenerMasPesado();
// Itera el map para encontrar el Pokemon con mayor peso

Pokemon* obtenerMayorExperiencia();
// Itera el map para encontrar el Pokemon con mayor base_experience

Pokemon* obtenerMayorPoderTotal();
// Itera el map para encontrar el Pokemon con mayor poder total

vector<Pokemon> listarPorTipo(const string& type);
// Retorna vector con todos los Pokemon del tipo especificado
```

#### Estadísticas:
```cpp
void mostrarEstadisticasPromedio() const;
// Calcula e imprime promedios de HP, Attack, Defense, Peso, etc.

void mostrarTodos() const;
// Itera e imprime todos los Pokemon (se mostrarán ordenados por ID)

void mostrarResumenTipos() const;
// Cuenta cuántos Pokemon hay de cada tipo
```

---

## Parte 3: Programa Principal

En la función `main()`, debes:

### 1. Crear una Pokédex y agregar Pokémon

Crea al menos **6 Pokémon**. Ejemplos:

```cpp
Pokemon ditto(132, "ditto", 3, 40, 101, "normal", 48, 48, 48);

Pokemon bulbasaur(1, "bulbasaur", 7, 69, 64, "grass", 45, 49, 49);

Pokemon charmander(4, "charmander", 6, 85, 62, "fire", 39, 52, 43);

Pokemon pikachu(25, "pikachu", 4, 60, 112, "electric", 35, 55, 40);

Pokemon charizard(6, "charizard", 17, 905, 240, "fire", 78, 84, 78);

Pokemon snorlax(143, "snorlax", 21, 4600, 189, "normal", 160, 110, 65);
```

### 2. Realizar las siguientes operaciones:

#### a) Búsqueda por ID (usar `find()`)
```cpp
Pokemon* encontrado = miPokedex.buscarPorId(132);
// Mostrar información de Ditto
```

#### b) Búsqueda por nombre (iterar el map)
```cpp
Pokemon* poke = miPokedex.buscarPorNombre("pikachu");
// Mostrar información de Pikachu
```

#### c) Verificar existencia (usar `count()`)
```cpp
if (miPokedex.existePokemon(25)) {
    cout << "Pikachu existe en la Pokedex" << endl;
}
```

#### d) Obtener estadísticas
```cpp
Pokemon* masPesado = miPokedex.obtenerMasPesado();
Pokemon* mayorExp = miPokedex.obtenerMayorExperiencia();
Pokemon* masFuerte = miPokedex.obtenerMayorPoderTotal();
```

#### e) Filtrar por tipo
```cpp
vector<Pokemon> tipoFuego = miPokedex.listarPorTipo("fire");
// Mostrar todos los Pokemon de tipo fuego
```

#### f) Mostrar estadísticas promedio
```cpp
miPokedex.mostrarEstadisticasPromedio();
```

#### g) Mostrar todos los Pokémon (usar iteración)
```cpp
miPokedex.mostrarTodos();
// Observar que aparecen ordenados por ID automáticamente
```

#### h) Eliminar un Pokémon (usar `erase()`)
```cpp
miPokedex.eliminarPokemon(4);  // Eliminar Charmander
// Mostrar la Pokédex actualizada
```

---
