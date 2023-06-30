#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define MAXL 10000001

bool isPrime[MAXL];
int primeCount[MAXL];

void crivoErastotenes(int limit)
{
    std::fill(isPrime, isPrime + limit, true);
    isPrime[0] = isPrime[1] = false;
    isPrime[2] = true;
    int sqrtLimit = sqrt(limit);
    for (int i = 2; i <= sqrtLimit; i++)
    {
        if (isPrime[i])
        {
            // Otimização: Se o número atual é par (exceto 2), pula para o próximo
            if (i % 2 == 0 && i != 2)
                continue;

            for (int j = i * i; j <= limit; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

void precalculatePrimeCount(int limit)
{
    primeCount[0] = primeCount[1] = 0;
    for (int i = 2; i <= limit; i++)
    {
        primeCount[i] = primeCount[i - 1] + isPrime[i];
    }
}

// Função para verificar se (k)_2 ⊆ (n)_2 Teorema de Lucas
bool binomialCoef(int n, int k) // calcula paridade do coeficiente binomial
{
    while (k > 0)
    {
        // Verifica se é ímpar
        // int kIsOdd = k % 2;
        // int nIsOdd = n % 2;
        if (k % 2 > n % 2)
        {
            return false;
        }

        // Divide k por 2 para remover o dígito menos significativo
        k /= 2;
        n /= 2;
    }

    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;

    int limit = max(a, b);

    crivoErastotenes(limit);
    precalculatePrimeCount(limit);

    int qntFatores = abs(a - b);
    int qntPrimos = primeCount[max(a, b)] - primeCount[min(a, b) - 1];

    if (a == b)
        cout << "?\n";
    else if (qntPrimos == 0 || !binomialCoef(qntPrimos + qntFatores - 1, qntFatores))
        cout << "Bob\n";
    else
        cout << "Alice\n";

    return 0;
}
