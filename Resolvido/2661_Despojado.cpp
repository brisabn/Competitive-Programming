#include <iostream>
#include <cmath>

bool despojado(double x)
{
    if (x == 1.0)
    {
        return false;
    }
    int i = 2;
    int r = (int)sqrt(x);
    bool primo = true, resul = true;
    while (i <= r && resul)
    {
        if (fmod(x, pow(i, 2)) == 0.0)
        {
            resul = false;
        }
        else if (fmod(x, i) == 0.0)
        {
            primo = false;
        }
        i++;
    }
    return resul && primo;
}

int main()
{
    double n;
    std::cin >> n;
    int div = 0;
    for (int i = 1; i <= (int)sqrt(n); i++)
    {
        if (fmod(n, i) == 0.0)
        {
            if (despojado(i))
            {
                div++;
            }
            if (i != n / i && despojado(n / i))
            {
                div++;
            }
        }
    }
    std::cout << round(pow(2, div) - div - 1) << std::endl;
    return 0;
}
