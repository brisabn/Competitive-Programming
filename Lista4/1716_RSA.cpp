#include <bits/stdc++.h> // me rendendo a esse biblio :P
#define MAXL 1000000
using namespace std;

bool isPrime[MAXL];
void crivoErastotenes()
{
    std::fill(isPrime, isPrime + MAXL, true);
    isPrime[0] = isPrime[1] = false;
    isPrime[2] = true;
    int sqrtLimit = sqrt(MAXL);
    for (int i = 2; i <= sqrtLimit; i++)
    {
        if (isPrime[i])
        {
            // Otimização: Se o número atual é par (exceto 2), pula para o próximo
            if (i % 2 == 0 && i != 2)
                continue;
            for (int j = i * i; j <= MAXL; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

// algoritmo de Euclides estendido
int mdcEuclidesEst(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int mdc = mdcEuclidesEst(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;

    return mdc;
}

// inverso multiplicativo de a módulo b
int modInverso(int a, int b)
{
    int x, y;
    int mdc = mdcEuclidesEst(a, b, x, y);
    return (x % b + b) % b;
}

// (base^exponent) módulo mod usando a exponenciação por quadrados
long long powerEsperto(long long base, long long exponent, long long mod)
{
    long long result = 1;
    base %= mod;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        exponent /= 2;
        base = (base * base) % mod;
    }

    return result;
}

int calculaPQ(int N)
{
    for (int P = 2; P * P <= N; P++)
    {
        if (N % P == 0 && isPrime[P])
        {
            while (N % P == 0)
                N /= P;
            return P;
        }
    }
    return N;
}

int phi(int N)
{
    int P = calculaPQ(N);
    int Q = N / P;
    return (P - 1) * (Q - 1);
}

int main()
{
    int N, E, C;
    cin >> N >> E >> C;

    crivoErastotenes();
    int fphi = phi(N);
    int D = modInverso(E, fphi);
    int M = powerEsperto(C, D, N); // decripto

    cout << M << '\n';

    return 0;
}
