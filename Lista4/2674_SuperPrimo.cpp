#include <iostream>
#include <cstring>
// #include <cmath>
//  #include <fstream>
//  std::ofstream kout("filename.txt");

#define MAXL 100000

bool isPrime[MAXL];

void crivoErastotenes()
{
    std::fill(isPrime, isPrime + MAXL, true);
    isPrime[0] = isPrime[1] = false;
    //  int sqrtLimit = std::sqrt(MAXL);
    int sqrtLimit = 316;
    for (int i = 2; i <= sqrtLimit; i++)
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

bool allDigitsPrime(int number)
{
    while (number > 0)
    {
        int digit = number % 10;
        if (!isPrime[digit])
            return false;
        number /= 10;
    }
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    crivoErastotenes();

    int number;
    while (std::cin >> number)
    {
        bool digitosPrimos = allDigitsPrime(number);
        if (isPrime[number] && digitosPrimos)
            std::cout
                << "Super\n";
        else if (isPrime[number] && !digitosPrimos)
            std::cout << "Primo\n";
        else
            std::cout << "Nada\n";
    }

    return 0;
}
