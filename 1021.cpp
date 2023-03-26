#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void contadorNotas(float valor, float &dinheiro)
{
    int notas = 0;
    int dinheiro_aux = dinheiro * 100;
    int valor_aux = valor * 100;

    notas = int(dinheiro / valor);
    cout << notas << " nota(s) de R$ " << setprecision(2) << fixed << valor << endl;

    dinheiro = ((dinheiro_aux) % (valor_aux)) / 100.00;
}

void contadorMoedas(float valor, float &dinheiro)
{
    int moedas = 0;
    int dinheiro_aux = dinheiro * 100;
    int valor_aux = valor * 100;

    moedas = int(dinheiro_aux / valor_aux);
    cout << moedas << " moeda(s) de R$ " << setprecision(2) << fixed << valor << endl;

    dinheiro = ((dinheiro_aux) % (valor_aux)) / 100.00;
}

int main()
{
    float dinheiro;
    cin >> dinheiro;

    cout << "NOTAS:" << endl;
    contadorNotas(100.0, dinheiro);
    contadorNotas(50.0, dinheiro);
    contadorNotas(20.0, dinheiro);
    contadorNotas(10.0, dinheiro);
    contadorNotas(5.0, dinheiro);
    contadorNotas(2.0, dinheiro);

    cout << "MOEDAS:" << endl;
    contadorMoedas(1.00, dinheiro);
    contadorMoedas(0.50, dinheiro);
    contadorMoedas(0.25, dinheiro);
    contadorMoedas(0.10, dinheiro);
    contadorMoedas(0.05, dinheiro);
    contadorMoedas(0.01, dinheiro);

    return 0;
}