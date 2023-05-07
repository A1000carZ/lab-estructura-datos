#include <iostream>
#include <string>

using namespace std;

class Cliente {
public:
    Cliente(string nombre) {
        this->nombre = nombre;
    }

    string obtenerNombre() {
        return nombre;
    }

private:
    string nombre;
};

class CuentaBancaria {
public:
    CuentaBancaria(Cliente* cliente, double saldoInicial) {
        this->cliente = cliente;
        this->saldo = saldoInicial;
    }

    void depositar(double cantidad) {
        saldo += cantidad;
    }

    void retirar(double cantidad) {
        saldo -= cantidad;
    }

    double obtenerSaldo() {
        return saldo;
    }

private:
    Cliente* cliente;
    double saldo;
};

int main() {
    Cliente* cliente = new Cliente("Amilcar Zahuindanda");
    CuentaBancaria cuenta(cliente, 1000.0);
    cuenta.depositar(500.0);
    cuenta.retirar(200.0);
    cout << "El saldo actual de la cuenta es: $" << cuenta.obtenerSaldo() << endl;
    delete cliente;

    return 0;
}
