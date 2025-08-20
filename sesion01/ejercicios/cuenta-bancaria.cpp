#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria {
private:
    string numero;
    string titular;
    double saldo;

public:
    // Constructores
    CuentaBancaria() {
        numero = "";
        titular = "";
        saldo = 0.0;
    }

    CuentaBancaria(string num, string tit, double saldoInicial) {
        numero = num;
        titular = tit;
        saldo = 0.0; // TODO: validar saldoInicial >= 0 y asignar
    }

    // Métodos
    bool depositar(double monto) {
        // TODO: validar monto > 0; sumar a saldo; retornar true/false
        return false;
    }

    bool girar(double monto) {
        // TODO: validar monto > 0; no permitir saldo negativo; true/false
        return false;
    }

    bool transferir(CuentaBancaria& destino, double monto) {
        // TODO: usar girar() y depositar()
        return false;
    }

    double obtenerSaldo() {
        // TODO: retornar saldo real
        return 0.0;
    }

    void imprimirResumen() {
        // TODO: imprimir numero, titular y saldo
    }
};

int main() {
    CuentaBancaria a("001", "Ana", 100000.0);
    CuentaBancaria b("002", "Benito", 50000.0);

    {
        CuentaBancaria c("003", "Carla", 30000.0);
        // TODO: 2 transferencias válidas y 1 inválida
        // a.transferir(b, 20000);
        // b.transferir(c, 10000);
        // c.transferir(a, 999999); // inválida
    }

    a.imprimirResumen();
    b.imprimirResumen();

    return 0;
}
