#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

// ============================================================================
// CLASE POKEMON
// ============================================================================
class Pokemon {
private:
    int id;
    string name;
    int height;           // Altura en decímetros
    int weight;           // Peso en hectogramos
    int base_experience;
    string type;          // Tipo principal
    int hp;               // Estadística base HP
    int attack;           // Estadística base Attack
    int defense;          // Estadística base Defense
    
public:
    // Constructor con parámetros
    Pokemon(int id, string name, int height, int weight, 
            int base_experience, string type, 
            int hp, int attack, int defense)
        : id(id), name(name), height(height), weight(weight),
          base_experience(base_experience), type(type),
          hp(hp), attack(attack), defense(defense) {}
    
    // Constructor por defecto
    Pokemon() : id(0), name(""), height(0), weight(0), 
                base_experience(0), type(""), 
                hp(0), attack(0), defense(0) {}
    
    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    int getHeight() const { return height; }
    int getWeight() const { return weight; }
    int getBaseExperience() const { return base_experience; }
    string getType() const { return type; }
    int getHp() const { return hp; }
    int getAttack() const { return attack; }
    int getDefense() const { return defense; }
    
    // Calcular poder total (suma de HP, Attack y Defense)
    int calcularPoderTotal() const {
        return hp + attack + defense;
    }
    
    // Convertir peso de hectogramos a kilogramos
    double getPesoKg() const {
        return weight / 10.0;
    }
    
    // Convertir altura de decímetros a metros
    double getAlturaMetros() const {
        return height / 10.0;
    }
    
    // Método para mostrar información completa
    void mostrarInfo() const {
        cout << "╔════════════════════════════════════════╗" << endl;
        cout << "║  Pokemon #" << setw(4) << left << id << "                         ║" << endl;
        cout << "╠════════════════════════════════════════╣" << endl;
        cout << "║  Nombre: " << setw(28) << left << name << "║" << endl;
        cout << "║  Tipo: " << setw(30) << left << type << "║" << endl;
        cout << "╠════════════════════════════════════════╣" << endl;
        cout << "║  Altura: " << fixed << setprecision(1) 
             << setw(5) << right << getAlturaMetros() << " m" << setw(22) << " " << "║" << endl;
        cout << "║  Peso: " << setw(7) << right << getPesoKg() << " kg" << setw(21) << " " << "║" << endl;
        cout << "║  Exp. Base: " << setw(4) << right << base_experience << setw(21) << " " << "║" << endl;
        cout << "╠════════════════════════════════════════╣" << endl;
        cout << "║  HP:      " << setw(3) << right << hp << setw(25) << " " << "║" << endl;
        cout << "║  Ataque:  " << setw(3) << right << attack << setw(25) << " " << "║" << endl;
        cout << "║  Defensa: " << setw(3) << right << defense << setw(25) << " " << "║" << endl;
        cout << "║  Poder Total: " << setw(3) << right << calcularPoderTotal() << setw(19) << " " << "║" << endl;
        cout << "╚════════════════════════════════════════╝" << endl;
    }
    
    // Método simple para listar
    void mostrarResumen() const {
        cout << "#" << setw(3) << right << id << " - " 
             << setw(12) << left << name 
             << " | Tipo: " << setw(10) << left << type
             << " | Poder: " << setw(3) << right << calcularPoderTotal() << endl;
    }
};

// ============================================================================
// CLASE POKEDEX
// ============================================================================
class Pokedex {
private:
    map<int, Pokemon> pokemons;
    
public:
    // Agregar un Pokémon usando insert
    void agregarPokemon(const Pokemon& poke) {
        pokemons.insert({poke.getId(), poke});
    }
    
    // Buscar por ID usando find() - devuelve puntero o nullptr
    Pokemon* buscarPorId(int id) {
        auto it = pokemons.find(id);
        if (it != pokemons.end()) {
            return &(it->second);
        }
        return nullptr;
    }
    
    // Buscar por nombre (debe iterar todo el map)
    Pokemon* buscarPorNombre(const string& name) {
        for (auto& [id, pokemon] : pokemons) {
            if (pokemon.getName() == name) {
                return &pokemon;
            }
        }
        return nullptr;
    }
    
    // Verificar si existe un Pokémon usando count()
    bool existePokemon(int id) const {
        return pokemons.count(id) > 0;
    }
    
    // Eliminar un Pokémon por ID usando erase()
    bool eliminarPokemon(int id) {
        auto it = pokemons.find(id);
        if (it != pokemons.end()) {
            cout << "  Eliminando a " << it->second.getName() 
                 << " (ID: " << id << ")..." << endl;
            pokemons.erase(it);
            return true;
        }
        return false;
    }
    
    // Obtener el Pokémon más pesado (iterando el map)
    Pokemon* obtenerMasPesado() {
        if (pokemons.empty()) {
            return nullptr;
        }
        
        auto maxIt = pokemons.begin();
        for (auto it = pokemons.begin(); it != pokemons.end(); ++it) {
            if (it->second.getWeight() > maxIt->second.getWeight()) {
                maxIt = it;
            }
        }
        return &(maxIt->second);
    }
    
    // Obtener el Pokémon con mayor experiencia base
    Pokemon* obtenerMayorExperiencia() {
        if (pokemons.empty()) {
            return nullptr;
        }
        
        auto maxIt = pokemons.begin();
        for (auto it = pokemons.begin(); it != pokemons.end(); ++it) {
            if (it->second.getBaseExperience() > maxIt->second.getBaseExperience()) {
                maxIt = it;
            }
        }
        return &(maxIt->second);
    }
    
    // Obtener el Pokémon con mayor poder total
    Pokemon* obtenerMayorPoderTotal() {
        if (pokemons.empty()) {
            return nullptr;
        }
        
        auto maxIt = pokemons.begin();
        for (auto it = pokemons.begin(); it != pokemons.end(); ++it) {
            if (it->second.calcularPoderTotal() > maxIt->second.calcularPoderTotal()) {
                maxIt = it;
            }
        }
        return &(maxIt->second);
    }
    
    // Listar todos los Pokémon de un tipo específico
    vector<Pokemon> listarPorTipo(const string& type) {
        vector<Pokemon> resultado;
        for (const auto& [id, pokemon] : pokemons) {
            if (pokemon.getType() == type) {
                resultado.push_back(pokemon);
            }
        }
        return resultado;
    }
    
    // Calcular estadísticas promedio de todos los Pokémon
    void mostrarEstadisticasPromedio() const {
        if (pokemons.empty()) {
            cout << "No hay Pokemon en la Pokedex" << endl;
            return;
        }
        
        double sumaHp = 0, sumaAtaque = 0, sumaDefensa = 0;
        double sumaPeso = 0, sumaAltura = 0, sumaExp = 0;
        
        for (const auto& [id, pokemon] : pokemons) {
            sumaHp += pokemon.getHp();
            sumaAtaque += pokemon.getAttack();
            sumaDefensa += pokemon.getDefense();
            sumaPeso += pokemon.getWeight();
            sumaAltura += pokemon.getHeight();
            sumaExp += pokemon.getBaseExperience();
        }
        
        int cantidad = pokemons.size();
        
        cout << "\n╔════════════════════════════════════════╗" << endl;
        cout << "║     ESTADISTICAS PROMEDIO              ║" << endl;
        cout << "╠════════════════════════════════════════╣" << endl;
        cout << "║  Total de Pokemon: " << setw(4) << cantidad << setw(14) << " " << "║" << endl;
        cout << "╠════════════════════════════════════════╣" << endl;
        cout << fixed << setprecision(2);
        cout << "║  HP promedio:      " << setw(6) << right << sumaHp/cantidad << setw(12) << " " << "║" << endl;
        cout << "║  Ataque promedio:  " << setw(6) << right << sumaAtaque/cantidad << setw(12) << " " << "║" << endl;
        cout << "║  Defensa promedio: " << setw(6) << right << sumaDefensa/cantidad << setw(12) << " " << "║" << endl;
        cout << "║  Peso promedio:    " << setw(6) << right << sumaPeso/cantidad << " hg" << setw(8) << " " << "║" << endl;
        cout << "║  Altura promedio:  " << setw(6) << right << sumaAltura/cantidad << " dm" << setw(8) << " " << "║" << endl;
        cout << "║  Exp. promedio:    " << setw(6) << right << sumaExp/cantidad << setw(12) << " " << "║" << endl;
        cout << "╚════════════════════════════════════════╝" << endl;
    }
    
    // Mostrar todos los Pokémon (ordenados automáticamente por ID)
    void mostrarTodos() const {
        cout << "\n╔════════════════════════════════════════╗" << endl;
        cout << "║       POKEDEX COMPLETA                 ║" << endl;
        cout << "╠════════════════════════════════════════╣" << endl;
        cout << "║  Total: " << setw(4) << pokemons.size() << " Pokemon" << setw(19) << " " << "║" << endl;
        cout << "╚════════════════════════════════════════╝\n" << endl;
        
        for (const auto& [id, pokemon] : pokemons) {
            pokemon.mostrarResumen();
        }
    }
    
    // Obtener cantidad de Pokémon usando size()
    int cantidadPokemons() const {
        return pokemons.size();
    }
    
    // Verificar si está vacía
    bool estaVacia() const {
        return pokemons.empty();
    }
    
    // Mostrar resumen de tipos
    void mostrarResumenTipos() const {
        map<string, int> conteoPorTipo;
        
        for (const auto& [id, pokemon] : pokemons) {
            conteoPorTipo[pokemon.getType()]++;
        }
        
        cout << "\n=== RESUMEN POR TIPOS ===" << endl;
        for (const auto& [tipo, cantidad] : conteoPorTipo) {
            cout << "  " << setw(12) << left << tipo 
                 << ": " << cantidad << " Pokemon" << endl;
        }
    }
};

// ============================================================================
// FUNCIONES AUXILIARES
// ============================================================================
void mostrarSeparador() {
    cout << "\n" << string(50, '=') << "\n" << endl;
}

void mostrarTitulo(const string& titulo) {
    cout << "\n╔" << string(48, '═') << "╗" << endl;
    cout << "║  " << setw(44) << left << titulo << "  ║" << endl;
    cout << "╚" << string(48, '═') << "╝\n" << endl;
}

// ============================================================================
// MAIN
// ============================================================================
int main() {
    Pokedex miPokedex;
    
    mostrarTitulo("CREANDO POKEDEX");
    
    // Crear Pokémon con datos reales de PokéAPI
    // Datos extraídos del JSON proporcionado y otros Pokemon
    
    cout << "Creando Pokemon a partir de datos de PokeAPI...\n" << endl;
    
    // Ditto (ID: 132) - del JSON proporcionado
    Pokemon ditto(132, "ditto", 3, 40, 101, "normal", 48, 48, 48);
    
    // Bulbasaur (ID: 1)
    Pokemon bulbasaur(1, "bulbasaur", 7, 69, 64, "grass", 45, 49, 49);
    
    // Charmander (ID: 4)
    Pokemon charmander(4, "charmander", 6, 85, 62, "fire", 39, 52, 43);
    
    // Pikachu (ID: 25)
    Pokemon pikachu(25, "pikachu", 4, 60, 112, "electric", 35, 55, 40);
    
    // Charizard (ID: 6)
    Pokemon charizard(6, "charizard", 17, 905, 240, "fire", 78, 84, 78);
    
    // Snorlax (ID: 143)
    Pokemon snorlax(143, "snorlax", 21, 4600, 189, "normal", 160, 110, 65);
    
    // Mewtwo (ID: 150)
    Pokemon mewtwo(150, "mewtwo", 20, 1220, 306, "psychic", 106, 110, 90);
    
    // Agregar todos a la Pokédex usando insert()
    cout << "Agregando Pokemon a la Pokedex..." << endl;
    miPokedex.agregarPokemon(ditto);
    miPokedex.agregarPokemon(bulbasaur);
    miPokedex.agregarPokemon(charmander);
    miPokedex.agregarPokemon(pikachu);
    miPokedex.agregarPokemon(charizard);
    miPokedex.agregarPokemon(snorlax);
    miPokedex.agregarPokemon(mewtwo);
    
    cout << "\n✓ " << miPokedex.cantidadPokemons() 
         << " Pokemon agregados exitosamente!" << endl;
    
    // ========================================
    // 1. BUSQUEDA POR ID usando find()
    // ========================================
    mostrarTitulo("1. BUSQUEDA POR ID (usando find)");
    
    cout << "Buscando Pokemon con ID 132 (Ditto)..." << endl;
    Pokemon* encontrado = miPokedex.buscarPorId(132);
    if (encontrado != nullptr) {
        cout << "\n✓ Pokemon encontrado!\n" << endl;
        encontrado->mostrarInfo();
    } else {
        cout << "✗ Pokemon no encontrado" << endl;
    }
    
    // ========================================
    // 2. BUSQUEDA POR NOMBRE (iterando el map)
    // ========================================
    mostrarTitulo("2. BUSQUEDA POR NOMBRE (iterando map)");
    
    cout << "Buscando Pokemon por nombre: 'mewtwo'..." << endl;
    Pokemon* mewtwoPtr = miPokedex.buscarPorNombre("mewtwo");
    if (mewtwoPtr != nullptr) {
        cout << "\n✓ Pokemon encontrado!\n" << endl;
        mewtwoPtr->mostrarInfo();
    }
    
    // ========================================
    // 3. VERIFICAR EXISTENCIA usando count()
    // ========================================
    mostrarTitulo("3. VERIFICAR EXISTENCIA (usando count)");
    
    cout << "Verificando existencia de Pokemon...\n" << endl;
    
    if (miPokedex.existePokemon(25)) {
        cout << "✓ Pikachu (ID 25) EXISTE en la Pokedex" << endl;
    }
    
    if (miPokedex.existePokemon(150)) {
        cout << "✓ Mewtwo (ID 150) EXISTE en la Pokedex" << endl;
    }
    
    if (!miPokedex.existePokemon(151)) {
        cout << "✗ Mew (ID 151) NO EXISTE en la Pokedex" << endl;
    }
    
    // ========================================
    // 4. OBTENER CANTIDAD usando size()
    // ========================================
    mostrarTitulo("4. CANTIDAD DE POKEMON (usando size)");
    
    cout << "Total de Pokemon en la Pokedex: " 
         << miPokedex.cantidadPokemons() << endl;
    
    // ========================================
    // 5. POKEMON MAS PESADO (iterando)
    // ========================================
    mostrarTitulo("5. POKEMON MAS PESADO (iterando map)");
    
    Pokemon* masPesado = miPokedex.obtenerMasPesado();
    if (masPesado != nullptr) {
        cout << "El Pokemon mas pesado es:\n" << endl;
        cout << "→ " << masPesado->getName() 
             << " con " << masPesado->getWeight() << " hectogramos ("
             << masPesado->getPesoKg() << " kg)" << endl;
    }
    
    // ========================================
    // 6. POKEMON CON MAYOR EXPERIENCIA
    // ========================================
    mostrarTitulo("6. POKEMON CON MAYOR EXPERIENCIA BASE");
    
    Pokemon* mayorExp = miPokedex.obtenerMayorExperiencia();
    if (mayorExp != nullptr) {
        cout << "El Pokemon con mayor experiencia base es:\n" << endl;
        cout << "→ " << mayorExp->getName() 
             << " con " << mayorExp->getBaseExperience() 
             << " puntos de experiencia" << endl;
    }
    
    // ========================================
    // 7. POKEMON CON MAYOR PODER TOTAL
    // ========================================
    mostrarTitulo("7. POKEMON CON MAYOR PODER TOTAL");
    
    Pokemon* masFuerte = miPokedex.obtenerMayorPoderTotal();
    if (masFuerte != nullptr) {
        cout << "El Pokemon con mayor poder total es:\n" << endl;
        masFuerte->mostrarInfo();
    }
    
    // ========================================
    // 8. LISTAR POR TIPO (iterando y filtrando)
    // ========================================
    mostrarTitulo("8. LISTAR POKEMON POR TIPO");
    
    cout << "Buscando todos los Pokemon de tipo 'normal'...\n" << endl;
    vector<Pokemon> tipoNormal = miPokedex.listarPorTipo("normal");
    
    cout << "Encontrados " << tipoNormal.size() 
         << " Pokemon de tipo normal:" << endl;
    for (const auto& poke : tipoNormal) {
        cout << "  • " << poke.getName() 
             << " (ID: " << poke.getId() << ")" << endl;
    }
    
    cout << "\nBuscando todos los Pokemon de tipo 'fire'...\n" << endl;
    vector<Pokemon> tipoFuego = miPokedex.listarPorTipo("fire");
    
    cout << "Encontrados " << tipoFuego.size() 
         << " Pokemon de tipo fire:" << endl;
    for (const auto& poke : tipoFuego) {
        cout << "  • " << poke.getName() 
             << " (ID: " << poke.getId() << ")" << endl;
    }
    
    // ========================================
    // 9. ESTADISTICAS PROMEDIO
    // ========================================
    mostrarTitulo("9. ESTADISTICAS PROMEDIO");
    
    miPokedex.mostrarEstadisticasPromedio();
    
    // ========================================
    // 10. RESUMEN POR TIPOS
    // ========================================
    mostrarTitulo("10. RESUMEN POR TIPOS");
    
    miPokedex.mostrarResumenTipos();
    
    // ========================================
    // 11. MOSTRAR TODOS (iterando ordenado)
    // ========================================
    mostrarTitulo("11. MOSTRAR TODOS (ordenados por ID)");
    
    cout << "Los Pokemon aparecen ordenados automaticamente por ID\n"
         << "gracias a la estructura std::map:\n" << endl;
    miPokedex.mostrarTodos();
    
    // ========================================
    // 12. ELIMINAR POKEMON usando erase()
    // ========================================
    mostrarTitulo("12. ELIMINAR POKEMON (usando erase)");
    
    cout << "Intentando eliminar a Charmander (ID: 4)...\n" << endl;
    if (miPokedex.eliminarPokemon(4)) {
        cout << "\n✓ Pokemon eliminado correctamente" << endl;
    } else {
        cout << "\n✗ No se pudo eliminar el Pokemon" << endl;
    }
    
    cout << "\nPokemon restantes: " << miPokedex.cantidadPokemons() << endl;
    
    // ========================================
    // 13. MOSTRAR DESPUES DE ELIMINAR
    // ========================================
    mostrarTitulo("13. POKEDEX ACTUALIZADA");
    
    cout << "Pokedex despues de eliminar a Charmander:\n" << endl;
    miPokedex.mostrarTodos();
    
    // ========================================
    // 14. OPERACION FINAL: DETALLE COMPLETO
    // ========================================
    mostrarTitulo("14. DETALLE COMPLETO DE UN POKEMON");
    
    cout << "Mostrando informacion detallada de Pikachu...\n" << endl;
    Pokemon* pikachuPtr = miPokedex.buscarPorId(25);
    if (pikachuPtr != nullptr) {
        pikachuPtr->mostrarInfo();
    }
    
    // ========================================
    // RESUMEN FINAL
    // ========================================
    mostrarTitulo("RESUMEN FINAL");
    
    cout << "Operaciones realizadas con std::map:" << endl;
    cout << "  ✓ insert() / [] - Agregar elementos" << endl;
    cout << "  ✓ find() - Buscar por clave (ID)" << endl;
    cout << "  ✓ count() - Verificar existencia" << endl;
    cout << "  ✓ erase() - Eliminar elementos" << endl;
    cout << "  ✓ size() - Obtener cantidad" << endl;
    cout << "  ✓ Iteracion - Recorrer todos los elementos" << endl;
    cout << "  ✓ Orden automatico - Por clave (ID)" << endl;
    
    cout << "\nEstado final de la Pokedex:" << endl;
    cout << "  → Total de Pokemon: " << miPokedex.cantidadPokemons() << endl;
    cout << "  → Todos ordenados por ID automaticamente" << endl;
    
    mostrarSeparador();
    cout << "¡Ejercicio completado exitosamente!" << endl;
    mostrarSeparador();
    
    return 0;
}