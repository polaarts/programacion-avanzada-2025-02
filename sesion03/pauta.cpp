#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Publicacion {
protected:
    string titulo;
    int anio;

public:
    Publicacion(string t, int a) {
        titulo = t;
        anio = a;
    }

    virtual void mostrarInfo() {
        cout << "Titulo: " << titulo << ", Año: " << anio << "\n";
    }

    int getAnio() { return anio; }
};

class Libro : public Publicacion {
    string autor;

public:
    Libro(string t, int a, string au) : Publicacion(t, a) {
        autor = au;
    }

    void mostrarInfo() override {
        cout << "Titulo: " << titulo
             << ", Autor: " << autor
             << ", Año: " << anio << "\n";
    }
};

void ordenarPorAnio(vector<Libro>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        for (int j = 0; j + 1 < (int)v.size(); j++) {
            if (v[j].getAnio() > v[j + 1].getAnio()) {
                Libro tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
            }
        }
    }
}


void mostrarTresFormas(vector<Libro>& v) {
    cout << "\n--- For clasico ---\n";
    for (int i = 0; i < (int)v.size(); i++) {
        v[i].mostrarInfo();
    }

    cout << "\n--- For-each ---\n";
    for (Libro& libro : v) {
        libro.mostrarInfo();
    }

    cout << "\n--- Iteradores ---\n";
    for (vector<Libro>::iterator it = v.begin(); it != v.end(); ++it) {
        it->mostrarInfo();
    }
}


int main() {
    vector<Libro> biblioteca;

    cout << "¿Biblioteca vacia? " << (biblioteca.empty() ? "Si" : "No") << "\n";

    biblioteca.push_back(Libro("El Quijote", 1605, "Cervantes"));
    biblioteca.push_back(Libro("Cien Años de Soledad", 1967, "Gabriel Garcia Marquez"));
    biblioteca.push_back(Libro("Rayuela", 1963, "Julio Cortazar"));

    cout << "Tamaño: " << biblioteca.size() << "\n";

    if (!biblioteca.empty()) {
        cout << "\n--- Acceso con at(0) ---\n";
        biblioteca.at(0).mostrarInfo();
    }

    if (!biblioteca.empty()) {  
        cout << "\n--- Front ---\n";
        biblioteca.front().mostrarInfo();

        cout << "--- Back ---\n";
        biblioteca.back().mostrarInfo();
    }

    

    mostrarTresFormas(biblioteca);

    ordenarPorAnio(biblioteca);
    cout << "\n--- Libros ordenados por año ---\n";
    for (Libro& libro : biblioteca) {
        libro.mostrarInfo();
    }

    biblioteca.pop_back();
    cout << "\nSe eliminó el último libro con pop_back. Tamaño: " << biblioteca.size() << "\n";

    if (biblioteca.size() >= 1) {
        int pos = (biblioteca.size() > 1 ? 1 : (int)biblioteca.size());
        biblioteca.insert(biblioteca.begin() + pos, Libro("Pedro Páramo", 1955, "Juan Rulfo"));
    }
    cout << "\nTras insert:\n";
    for (Libro& libro : biblioteca) {
        libro.mostrarInfo();
    }

    if (biblioteca.size() >= 2) {
        biblioteca.erase(biblioteca.begin() + 1);
    }
    cout << "\nTras erase:\n";
    for (Libro& libro : biblioteca) {
        libro.mostrarInfo();
    }

    return 0;
}
