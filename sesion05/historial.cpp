#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class NavegadorWeb {
private:
    stack<string> historialAtras;      // Páginas visitadas anteriormente
    stack<string> historialAdelante;   // Páginas para ir hacia adelante
    string paginaActual;                // URL actual
    
public:
    // Constructor - página de inicio por defecto
    NavegadorWeb() : paginaActual("about:blank") {}
    
    // Visita una nueva URL
    void visit(const string& url) {
        if (!paginaActual.empty()) {
            // Guardar la página actual en el historial de atrás
            historialAtras.push(paginaActual);
        }
        
        paginaActual = url;
        
        // Limpiar el historial hacia adelante (igual que navegadores reales)
        while (!historialAdelante.empty()) {
            historialAdelante.pop();
        }
    }
    
    // Retrocede a la página anterior
    void back() {
        if (historialAtras.empty()) {
            return;
        }
        
        // Guardar la página actual para poder avanzar después
        historialAdelante.push(paginaActual);
        
        // Ir a la página anterior
        paginaActual = historialAtras.top();
        historialAtras.pop();        
    }
    
    // Avanza a la siguiente página
    void forward() {
        if (historialAdelante.empty()) {
            return;
        }
        
        // Guardar la página actual en el historial de atrás
        historialAtras.push(paginaActual);
        
        // Ir a la página siguiente
        paginaActual = historialAdelante.top();
        historialAdelante.pop();        
    }
    
    // Obtiene la URL actual
    string getCurrentUrl() const {
        return paginaActual;
    }
    
    // Muestra el historial completo de navegación
    void showHistory() const {
        
        // Mostrar historial hacia atrás (convertir stack a vector para visualizar)
        stack<string> tempAtras = historialAtras;
        vector<string> atras;
        while (!tempAtras.empty()) {
            atras.push_back(tempAtras.top());
            tempAtras.pop();
        }
        
        // Imprimir historial hacia atrás (del más antiguo al más reciente)
        if (!atras.empty()) {
            for (int i = atras.size() - 1; i >= 0; i--) {
                cout << "   " << (atras.size() - i) << ". " << atras[i] << endl;
            }
        }
    }
    
    // Verifica si se puede ir atrás
    bool canGoBack() const {
        return !historialAtras.empty();
    }

    // Verifica si se puede ir adelante
    bool canGoForward() const {
        return !historialAdelante.empty();
    }
    
    // Limpia todo el historial
    void clearHistory() {
        while (!historialAtras.empty()) historialAtras.pop();
        while (!historialAdelante.empty()) historialAdelante.pop();
    }
};

    NavegadorWeb browser;
    
    cout << "\n╔═══════════════════════════════════════════════╗" << endl;
    cout << "║   SIMULACIÓN DE NAVEGACIÓN WEB                ║" << endl;
    cout << "╚═══════════════════════════════════════════════╝\n" << endl;
    
    // Sesión de navegación normal
    cout << "--- VISITANDO PÁGINAS ---" << endl;
    browser.visit("https://www.google.com");
    browser.mostrarPaginaActual();
    
    browser.visit("https://www.youtube.com");
    browser.mostrarPaginaActual();
    
    browser.visit("https://www.github.com");
    browser.mostrarPaginaActual();
    
    browser.visit("https://www.stackoverflow.com");
    browser.mostrarPaginaActual();
    
    browser.showHistory();
    browser.mostrarEstadisticas();
    
    // Navegando hacia atrás
    cout << "\n--- NAVEGANDO HACIA ATRÁS ---" << endl;
    browser.back();
    browser.mostrarPaginaActual();
    
    browser.back();
    browser.mostrarPaginaActual();
    
    browser.showHistory();
    browser.mostrarEstadisticas();
    
    // Navegando hacia adelante
    cout << "\n--- NAVEGANDO HACIA ADELANTE ---" << endl;
    browser.forward();
    browser.mostrarPaginaActual();
    
    browser.showHistory();
    
    // Visitando una nueva página después de retroceder
    cout << "\n--- VISITANDO NUEVA PÁGINA (borra historial adelante) ---" << endl;
    browser.visit("https://www.reddit.com");
    browser.mostrarPaginaActual();
    
    browser.showHistory();
    browser.mostrarEstadisticas();
    
    // Intentando ir adelante (no debería haber nada)
    cout << "\n--- INTENTANDO IR ADELANTE ---" << endl;
    browser.forward();
    
    // Retroceder hasta el inicio
    cout << "\n--- RETROCEDIENDO AL INICIO ---" << endl;
    while (browser.canGoBack()) {
        browser.back();
    }
    browser.mostrarPaginaActual();
    
    browser.back(); // Intentar ir más atrás (no debería hacer nada)
    
    browser.showHistory();
}