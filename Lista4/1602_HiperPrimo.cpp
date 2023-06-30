#include <iostream>
#include <cstring>

#define MAXL 2000001
bool isPrime[MAXL];
int divisores[MAXL], hiper[MAXL + 1];

void crivoErastotenes()
{
    std::fill(isPrime, isPrime + MAXL, true);
    isPrime[0] = isPrime[1] = false;
    // int sqrtLimit = sqrt(MAX);
    // já calculando sqrt de 2000001, é 1415
    for (int i = 2; i <= 1415; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MAXL; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

void calculateDivisores()
{
    std::memset(divisores, 0, sizeof(divisores));
    for (int i = 1; i <= MAXL; i++)
    {
        for (int j = i; j <= MAXL; j += i)
        {
            divisores[j]++;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int limit;
    crivoErastotenes();
    calculateDivisores();
    // bom, calculando TUDO antes funciona

    hiper[1] = 0, hiper[2] = 1, hiper[3] = 2, hiper[4] = 3;
    for (int i = 5; i <= MAXL; i++)
    {
        hiper[i] = hiper[i - 1];
        if (isPrime[divisores[i]]) // a
            hiper[i]++;
    }
    // calcular até hiperprimos funcionou, lol

    while (std::cin >> limit)
        std::cout << hiper[limit] << '\n';

    return 0;
}
