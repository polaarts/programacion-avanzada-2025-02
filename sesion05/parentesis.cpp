#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*

# Problema: Validación de Paréntesis Balanceados

## Descripción

Dado un string `s` que contiene únicamente los caracteres `'('`, `')'`, `'{'`, `'}'`, `'['` y `']'`, determinar si el string de entrada es válido.

Un string es válido si:

1. Los paréntesis abiertos deben cerrarse con el mismo tipo de paréntesis.
2. Los paréntesis abiertos deben cerrarse en el orden correcto.
3. Cada paréntesis de cierre debe tener un paréntesis de apertura correspondiente del mismo tipo.

## Ejemplos

### Ejemplo 1:
```
Entrada: s = "()"
Salida: true
```

### Ejemplo 2:
```
Entrada: s = "()[]{}"
Salida: true
```

### Ejemplo 3:
```
Entrada: s = "(]"
Salida: false
Explicación: Los paréntesis no son del mismo tipo.
```

### Ejemplo 4:
```
Entrada: s = "([)]"
Salida: false
Explicación: Los paréntesis no están cerrados en el orden correcto.
```

## Restricciones

- `1 <= s.length <= 10^4`
- `s` consiste únicamente de paréntesis: `'()[]{}'`

- Un string vacío se considera válido.

*/

bool esValido(string s) {
    stack<char> pila;
    
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            pila.push(c);
        }
        else {
            if (pila.empty()) return false;
            
            char tope = pila.top();
            if ((c == ')' && tope == '(') ||
                (c == ']' && tope == '[') ||
                (c == '}' && tope == '{')) {
                pila.pop();
            } else {
                return false;
            }
        }
    }
    
    return pila.empty();
}