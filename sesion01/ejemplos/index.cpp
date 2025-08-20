#include <iostream>
using namespace std;

class Persona {
    private:
    string Nombre; //atributos

    public:
    Persona() { // constructor vacío
        Nombre = "";
    }
    Persona(string Nombre) {
        this->Nombre = Nombre;
    }

    void saludar() {
        cout << "Hola, mi nombre es " << Nombre << endl;
    }

    int main() {
        Persona a("Juan");
        a.saludar();
        
        Persona* b = new Persona("Maria");
        b->saludar();

        delete b;
    }
};