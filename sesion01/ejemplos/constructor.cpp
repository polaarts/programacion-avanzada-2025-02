#include <iostream>
using namespace std;

class nombreClase {
    private:
    // atributos de la clase
    string atributo1;

    public:
    nombreClase (){ // constructor vacío de la clase
        atributo1 = "";
    }

    nombreClase(string atributo1) {
        this->atributo1 = atributo1;
    }
};