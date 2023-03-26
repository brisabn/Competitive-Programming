#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    double dinheiro = 0;
    int notas = 0, moedas = 0, dinheiro_aux, valor_aux;

    cin >> dinheiro;

    // NOTAS
    cout << "NOTAS:\n";
    // 100
    dinheiro_aux = dinheiro * 1000;
    valor_aux = 100.00 * 1000;

    notas = int(dinheiro_aux / valor_aux);
    cout << notas << " nota(s) de R$ 100.00 \n";

    dinheiro = ((dinheiro_aux) % (valor_aux)) / 1000.00;

    // 50
    dinheiro_aux = dinheiro * 1000;
    valor_aux = 50.00 * 1000;

    notas = int(dinheiro_aux / valor_aux);
    cout << notas << " nota(s) de R$ 50.00 \n";

    dinheiro = ((dinheiro_aux) % (valor_aux)) / 1000.00;

    // 20
    dinheiro_aux = dinheiro * 1000;
    valor_aux = 20.00 * 1000;

    notas = int(dinheiro_aux / valor_aux);
    cout << notas << " nota(s) de R$ 20.00 \n";

    dinheiro = ((dinheiro_aux) % (valor_aux)) / 1000.00;

    // 10
    dinheiro_aux = dinheiro * 1000;
    valor_aux = 10.00 * 1000;

    notas = int(dinheiro_aux / valor_aux);
    cout << notas << " nota(s) de R$ 10.00 \n";

    dinheiro = ((dinheiro_aux) % (valor_aux)) / 1000.00;

    // 5
    dinheiro_aux = dinheiro * 1000;
    valor_aux = 5.00 * 1000;

    notas = int(dinheiro_aux / valor_aux);
    cout << notas << " nota(s) de R$ 5.00 \n";

    dinheiro = ((dinheiro_aux) % (valor_aux)) / 1000.00;

    // 2
    dinheiro_aux = dinheiro * 1000;
    valor_aux = 2.00 * 1000;

    notas = int(dinheiro_aux / valor_aux);
    cout << notas << " nota(s) de R$ 2.00 \n";

    dinheiro = ((dinheiro_aux) % (valor_aux)) / 1000.00;

    // MOEDAS
    cout << "MOEDAS:" << endl;
    // 1
    dinheiro_aux = dinheiro * 1000;
    valor_aux = 1.00 * 1000;

    moedas = int(dinheiro_aux / valor_aux);
    cout << moedas << " moeda(s) de R$ 1.00 \n";

    dinheiro = ((dinheiro_aux) % (valor_aux)) / 1000.00;

    // 0.50
    dinheiro_aux = dinheiro * 1000;
    valor_aux = 0.50 * 1000;

    moedas = int(dinheiro_aux / valor_aux);
    cout << moedas << " moeda(s) de R$ 0.50 \n";

    dinheiro = ((dinheiro_aux) % (valor_aux)) / 1000.00;

    // 0.25
    dinheiro_aux = dinheiro * 1000;
    valor_aux = 0.25 * 1000;

    moedas = int(dinheiro_aux / valor_aux);
    cout << moedas << " moeda(s) de R$ 0.25 \n";

    dinheiro = ((dinheiro_aux) % (valor_aux)) / 1000.00;

    // 0.10
    dinheiro_aux = dinheiro * 1000;
    valor_aux = 0.10 * 1000;

    moedas = int(dinheiro_aux / valor_aux);
    cout << moedas << " moeda(s) de R$ 0.10 \n";

    dinheiro = ((dinheiro_aux) % (valor_aux)) / 1000.00;

    // 0.05
    dinheiro_aux = dinheiro * 1000;
    valor_aux = 0.05 * 1000;

    moedas = int(dinheiro_aux / valor_aux);
    cout << moedas << " moeda(s) de R$ 0.05 \n";

    dinheiro = ((dinheiro_aux) % (valor_aux)) / 1000.00;

    // 0.01
    dinheiro_aux = dinheiro * 1000;
    valor_aux = 0.01 * 1000;

    moedas = int(dinheiro_aux / valor_aux);
    cout << moedas << " moeda(s) de R$ 0.01 \n";

    dinheiro = ((dinheiro_aux) % (valor_aux)) / 1000.00;

    return 0;
}