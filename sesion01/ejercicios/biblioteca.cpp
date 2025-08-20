#include <iostream>
#include <string>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    string isbn;
    bool disponible;

public:
    Libro() {
        titulo = "";
        autor = "";
        isbn = "";
        disponible = true;
    }

    Libro(string titulo, string autor, string isbn, bool disponible = true) {
        this->titulo = titulo;
        this->autor = autor;
        this->isbn = isbn;
        this->disponible = disponible;
    }

    bool prestar() {
        // TODO: si disponible -> poner en false y return true; si no, return false
        return false;
    }

    bool devolver() {
        // TODO: si NO disponible -> poner en true y return true; si ya estaba disponible, return false
        return false;
    }

    void imprimir() {
        // TODO: imprimir titulo, autor, isbn y estado (Disponible/Prestado)
    }

    string getISBN() { return isbn; }
    bool isDisponible() { return disponible; }
};

class Biblioteca {
private:
    enum { MAX = 50 }; // evita const
    Libro libros[MAX];
    int cantidad;

public:
    Biblioteca() {
        cantidad = 0;
    }

    bool agregar(Libro l) {
        // TODO:
        // 1) verificar espacio (cantidad < MAX)
        // 2) verificar que NO exista ISBN duplicado
        // 3) copiar l en libros[cantidad] y ++cantidad
        return false;
    }

    Libro* buscarPorISBN(string i) {
        // TODO: recorrer [0, cantidad) y devolver puntero si coincide; si no, nullptr
        return 0;
    }

    bool prestarPorISBN(string i) {
        // TODO: usar buscarPorISBN y llamar a prestar()
        return false;
    }

    bool devolverPorISBN(string i) {
        // TODO: usar buscarPorISBN y llamar a devolver()
        return false;
    }

    void listarDisponibles() {
        // TODO: recorrer y llamar imprimir() solo si isDisponible() es true
    }
};

int main() {
    Biblioteca biblio;

    // TODO: agrega al menos 5 libros
    // biblio.agregar(Libro("Clean Code", "Robert C. Martin", "9780132350884"));
    // biblio.agregar(Libro("Design Patterns", "Gamma et al.", "9780201633610"));
    // ...

    // TODO: presta 2, intenta prestar uno ya prestado (debe fallar)
    // biblio.prestarPorISBN("9780132350884");
    // biblio.prestarPorISBN("9780132350884"); // debería fallar

    // TODO: devuelve 1
    // biblio.devolverPorISBN("9780132350884");

    // TODO: intenta agregar un ISBN duplicado (debe fallar)
    // biblio.agregar(Libro("Otro título", "Otro autor", "9780132350884"));

    biblio.listarDisponibles();
    return 0;
}
