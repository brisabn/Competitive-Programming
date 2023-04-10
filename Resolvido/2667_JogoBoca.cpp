// Jogo de Boca
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string n_aux;
    getline(cin, n_aux);
    long long int n = 0;

    // transforma uma string grande num número grandão
    for (int i = 0; i < n_aux.length(); i++)
    {
        n += (n_aux[i] - '0');
    }
    cout << n % 3 << endl;
    return 0;
}