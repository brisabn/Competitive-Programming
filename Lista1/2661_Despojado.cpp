#include <iostream>
#include <cmath>

bool is_primo(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool is_despojado(int n)
{
    if (n == 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % (i * i) == 0)
        {
            return false;
        }
    }
    return is_primo(n);
}

int qnts_despojado(double n)
{
    int qnt = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (fmod(n, i) == 0.0) // tipo n%i
        {
            if (is_despojado(i))
            {
                qnt++;
            }
            if (i != n / i && is_despojado(n / i))
            {
                qnt++;
            }
        }
    }
    return qnt;
}

int main()
{
    double n; // declarado como double porque depois faz a raiz dele
    std::cin >> n;
    scanf("%lf", &n);
    int despojado_divisores = qnts_despojado(n);

    int resul = pow(2, despojado_divisores) - despojado_divisores - 1;
    printf("%d\n", resul);
    return 0;
}
