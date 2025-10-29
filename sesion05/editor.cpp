#include <iostream>
#include <stack>
#include <string>
using namespace std;

class EditorTexto {
private:
    string contenido;                    // Contenido actual del documento
    stack<string> historialUndo;         // Pila para deshacer
    stack<string> historialRedo;         // Pila para rehacer

public:
    // Constructor
    EditorTexto() : contenido("") {}
    
    // Escribe texto al final del documento
    void write(const string& texto) {
        // Guardar el estado actual antes de modificar
        historialUndo.push(contenido);
        
        // Agregar el nuevo texto
        contenido += texto;
        
        // Limpiar el historial de redo (ya no son válidos)
        while (!historialRedo.empty()) {
            historialRedo.pop();
        }
    }
    
    // Deshace la última operación
    void undo() {
        if (historialUndo.empty()) {
            return;
        }
        
        // Guardar el estado actual en redo antes de deshacer
        historialRedo.push(contenido);
        
        // Recuperar el estado anterior
        contenido = historialUndo.top();
        historialUndo.pop();
    }
    
    // Rehace la última operación deshecha
    void redo() {
        if (historialRedo.empty()) {
            return;
        }
        
        // Guardar el estado actual en undo antes de rehacer
        historialUndo.push(contenido);
        
        // Recuperar el estado siguiente
        contenido = historialRedo.top();
        historialRedo.pop();        
    }
    
    // Obtiene el contenido actual
    string getText() const {
        return contenido;
    }
    
    // Muestra el contenido actual
    void mostrarContenido() const {
        cout << "\"" << contenido << "\"" << endl;
    }
};