#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int notas, moedas;

void contadorNotas(double valor, int &money)
{
    notas = 0;
    int valor_aux = valor * 1000;

    notas = money / valor_aux;
    cout << notas << " nota(s) de R$ " << setprecision(2) << fixed << valor << endl;

    money = ((money) % (valor_aux));
}

void contadorMoedas(double valor, int &money)
{
    moedas = 0;
    int valor_aux = valor * 1000;

    moedas = money / valor_aux;
    cout << moedas << " moeda(s) de R$ " << setprecision(2) << fixed << valor << endl;

    money = ((money) % (valor_aux));
}

int main()
{
    int money;
    double dinheiro;
    cin >> dinheiro;

    money = dinheiro * 1000;

    cout << "NOTAS:" << endl;
    contadorNotas(100.00, money);
    contadorNotas(50.00, money);
    contadorNotas(20.00, money);
    contadorNotas(10.00, money);
    contadorNotas(5.00, money);
    contadorNotas(2.00, money);

    cout << "MOEDAS:" << endl;
    contadorMoedas(1.00, money);
    contadorMoedas(0.50, money);
    contadorMoedas(0.25, money);
    contadorMoedas(0.10, money);
    contadorMoedas(0.05, money);
    contadorMoedas(0.01, money);

    return 0;
}