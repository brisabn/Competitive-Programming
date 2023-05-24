#include <iostream>
#include <cstring>

using namespace std;

int pilhas[3][101];
int dp[101][101][101];

bool jogo(int A, int B, int C)
{
    if (A == 0 && B == 0 && C == 0)
        return true;

    if (dp[A][B][C] != -1)
        return dp[A][B][C];

    int topoA = pilhas[0][A - 1];
    int topoB = pilhas[1][B - 1];
    int topoC = pilhas[2][C - 1];

    bool resultado = false;

    if (A > 0 && topoA % 3 == 0)
        resultado = jogo(A - 1, B, C);

    if (B > 0 && topoB % 3 == 0)
        resultado = jogo(A, B - 1, C);

    if (C > 0 && topoC % 3 == 0)
        resultado = jogo(A, B, C - 1);

    if (!resultado && A > 0 && B > 0 && (topoA + topoB) % 3 == 0)
        resultado = jogo(A - 1, B - 1, C);

    if (!resultado && A > 0 && C > 0 && (topoA + topoC) % 3 == 0)
        resultado = jogo(A - 1, B, C - 1);

    if (!resultado && B > 0 && C > 0 && (topoB + topoC) % 3 == 0)
        resultado = jogo(A, B - 1, C - 1);

    if (!resultado && A > 0 && B > 0 && C > 0 && (topoA + topoB + topoC) % 3 == 0)
        resultado = jogo(A - 1, B - 1, C - 1);

    dp[A][B][C] = resultado;

    return resultado;
}

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> pilhas[j][i];
            }
        }
        memset(dp, -1, sizeof(dp));
        cout << (jogo(n, n, n) ? "1\n" : "0\n");
    }

    return 0;
}
