#include <iostream>
#include <cstring>

using namespace std;
const int M = 1e6;

void multMatriz(long long richasA[2][2], long long richasB[2][2])
{
    long long resp[2][2];
    memset(resp, 0, sizeof(resp));

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                resp[i][j] = (resp[i][j] + (richasA[i][k] * richasB[k][j]) % M) % M;
            }
        }
    }

    memcpy(richasA, resp, sizeof(resp));
}

void powRecursive(long long richas[2][2], long long n, long long resp[2][2])
{
    // Caso base: quando n é igual a zero, retorna matriz identidade
    if (n == 0)
    {
        resp[0][0] = resp[1][1] = 1;
        resp[0][1] = resp[1][0] = 0;
    }
    // Caso ímpar
    else if (n % 2 == 1)
    {
        // n-1 para um número par
        powRecursive(richas, n - 1, resp);
        multMatriz(resp, richas); // com richasA
    }
    // Caso par
    else
    {
        // n/2 para um número menor
        powRecursive(richas, n / 2, resp);
        multMatriz(resp, resp); // consigo mesmo
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // n amei esse codigo, mas dá dando certo as resp
    long long compTotal, corMinibus, corBus;
    while (cin >> compTotal >> corMinibus >> corBus)
    {
        compTotal /= 5;
        corMinibus %= M;
        corBus %= M;

        // na verdade o nome dele é ricadinho, lol
        long long ricardo[2][2];
        ricardo[0][0] = corMinibus;
        ricardo[0][1] = corBus;
        ricardo[1][0] = 1;
        ricardo[1][1] = 0;

        long long resp[2][2] = {{1, 0}, {0, 1}};

        powRecursive(ricardo, compTotal, resp);
        printf("%.6lld\n", (resp[1][1] + (resp[1][0] * corMinibus)) % M);
    }

    return 0;
}
