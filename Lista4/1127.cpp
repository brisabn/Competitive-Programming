#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);

    int M, T;
    while (cin >> M >> T && M != 0 && T != 0)
    {
        vector<char> suspeito;
        vector<char> musica;
        for (int i = 0; i < M; i++)
            cin >> musica[i]; // na verdade tem que permitir #F

        for (int i = 0; i < T; i++)
            cin >> suspeito[i];
    }

    return 0;
}
