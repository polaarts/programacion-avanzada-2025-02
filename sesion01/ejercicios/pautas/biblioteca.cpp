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
        if (!disponible) return false;
        disponible = false;
        return true;
    }

    bool devolver() {
        if (disponible) return false;
        disponible = true;
        return true;
    }

    void imprimir() {
        string estado = disponible ? "Disponible" : "Prestado";
        cout << "Titulo: " << titulo
             << " | Autor: " << autor
             << " | ISBN: " << isbn
             << " | Estado: " << estado << "\n";
    }

    string getISBN() { return isbn; }
    bool isDisponible() { return disponible; }
};

class Biblioteca {
private:
    Libro libros[50];
    int cantidad;

public:
    Biblioteca() {
        cantidad = 0;
    }

    bool agregar(Libro l) {
        if (cantidad >= 50) return false;
        // Rechazar ISBN duplicado
        int i = 0;
        while (i < cantidad) {
            if (libros[i].getISBN() == l.getISBN()) return false;
            i++;
        }
        libros[cantidad] = l;
        cantidad++;
        return true;
    }

    Libro* buscarPorISBN(string i) {
        int k = 0;
        while (k < cantidad) {
            if (libros[k].getISBN() == i) return &libros[k];
            k++;
        }
        return 0;
    }

    bool prestarPorISBN(string i) {
        Libro* p = buscarPorISBN(i);
        if (p == 0) return false;
        return p->prestar();
    }

    bool devolverPorISBN(string i) {
        Libro* p = buscarPorISBN(i);
        if (p == 0) return false;
        return p->devolver();
    }

    void listarDisponibles() {
        cout << "== Libros disponibles ==\n";
        int i = 0;
        while (i < cantidad) {
            if (libros[i].isDisponible()) libros[i].imprimir();
            i++;
        }
    }
};

int main() {
    Biblioteca biblio;

    // Agregar 5 libros
    cout << (biblio.agregar(Libro("Clean Code", "Robert C. Martin", "9780132350884")) ? "ok" : "fallo") << "\n";
    cout << (biblio.agregar(Libro("Design Patterns", "Gamma et al.", "9780201633610")) ? "ok" : "fallo") << "\n";
    cout << (biblio.agregar(Libro("The Pragmatic Programmer", "Andrew Hunt", "9780201616224")) ? "ok" : "fallo") << "\n";
    cout << (biblio.agregar(Libro("Refactoring", "Martin Fowler", "9780201485677")) ? "ok" : "fallo") << "\n";
    cout << (biblio.agregar(Libro("Code Complete", "Steve McConnell", "9780735619678")) ? "ok" : "fallo") << "\n";

    // Prestar 2, y fallar al prestar repetido
    cout << "Prestar 9780132350884: " << (biblio.prestarPorISBN("9780132350884") ? "ok" : "fallo") << "\n";
    cout << "Prestar 9780201633610: " << (biblio.prestarPorISBN("9780201633610") ? "ok" : "fallo") << "\n";
    cout << "Prestar repetido 9780132350884: " << (biblio.prestarPorISBN("9780132350884") ? "ok" : "fallo") << "\n";

    // Devolver 1
    cout << "Devolver 9780132350884: " << (biblio.devolverPorISBN("9780132350884") ? "ok" : "fallo") << "\n";

    // Intentar agregar ISBN duplicado (debe fallar)
    cout << "Agregar duplicado 9780132350884: "
         << (biblio.agregar(Libro("Otro titulo", "Otro autor", "9780132350884")) ? "ok" : "fallo") << "\n";

    // Listar disponibles
    biblio.listarDisponibles();

    return 0;
}
