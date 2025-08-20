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

    CuentaBancaria(string numero, string titular, double saldo) {
        this->numero = numero;
        this->titular = titular;
        this->saldo = saldo;
    }

    // Métodos
    bool depositar(double monto) {
        if (monto <= 0.0) return false;
        saldo += monto;
        return true;
    }

    bool girar(double monto) {
        if (monto <= 0.0) return false;
        if (saldo - monto < 0.0) return false;
        saldo -= monto;
        return true;
    }

    bool transferir(CuentaBancaria& destino, double monto) {
        if (monto <= 0.0) return false;
        if (!girar(monto)) return false;
        return true;
    }

    double obtenerSaldo() {
        return saldo;
    }

    void imprimirResumen() {
        cout << "Cuenta: " << numero
             << " | Titular: " << titular
             << " | Saldo: " << saldo << "\n";
    }
};

int main() {
    CuentaBancaria a("001", "Ana", 100000.0);
    CuentaBancaria b("002", "Benito", 50000.0);
    CuentaBancaria c("003", "Carla", 30000.0);

    cout << "== Estado inicial ==\n";
    a.imprimirResumen();
    b.imprimirResumen();
    c.imprimirResumen();

    cout << "\n== Operaciones ==\n";
    cout << "Ana -> Benito (20000): " << (a.transferir(b, 20000.0) ? "ok" : "fallo") << "\n";
    cout << "Benito -> Carla (10000): " << (b.transferir(c, 10000.0) ? "ok" : "fallo") << "\n";
    cout << "Carla -> Ana (999999): " << (c.transferir(a, 999999.0) ? "ok" : "fallo") << "\n";

    cout << "\n== Estado final ==\n";
    a.imprimirResumen();
    b.imprimirResumen();
    c.imprimirResumen();

    return 0;
}
