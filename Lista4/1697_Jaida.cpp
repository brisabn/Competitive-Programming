#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

const int MAXP = 1300000;
//            N =10000000
// const int raizMAXP = 1141;

bool isPrime[MAXP];
void crivoErastotenes()
{
    std::fill(isPrime, isPrime + MAXP, true);
    isPrime[0] = false;
    // isPrime[1] = false;
    isPrime[2] = true;
    // int sqrtLimit = sqrt(MAXP);
    int sqrtLimit = 1141;
    for (int i = 2; i <= sqrtLimit; i++)
    {
        if (isPrime[i])
        {
            // Otimização: Se o número atual é par (exceto 2), pula para o próximo
            if (i % 2 == 0 && i != 2)
                continue;

            for (int j = i * i; j <= MAXP; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int main()
{
    // a idiea é: se tem os outros primos pode formar qualquer numero né lol
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    crivoErastotenes();

    int n, casos;
    cin >> casos;
    unordered_map<int, bool> mapa; // acho que melhor pra nao dumpcore

    while (casos--)
    {
        mapa.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            mapa[num] = true;
        }

        isPrime[1] = true;             // pecado, eu sei, mas prático
        for (int i = 1; i < MAXP; i++) // tem que percorrer tooodos os primos buéee
        {
            if (isPrime[i] && !mapa[i]) // se é primo e não está no conjunto
            {
                printf("%d\n", i - 1); // o último antes desse primo
                break;
            }
        }
    }

    return 0;
}
