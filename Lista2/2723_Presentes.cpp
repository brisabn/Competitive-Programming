#include <iostream>

bool equilibrio(int presente[], int N, int pesoEsq, int pesoDir, int pos)
{
    if (pos == N)
        return true;

    // if (dp[pos][pesoEsq])
    //     return dp[pos][pesoEsq]; dp nem sempre deixa mais rápido!!
    int dif = pesoEsq - pesoDir;
    // dá pra colocar na esquerda?
    if (abs(presente[pos] - dif) <= 5)
        if (equilibrio(presente, N, pesoEsq, pesoDir + presente[pos], pos + 1))
            return true;

    // dá pra colocar na direita?
    if (abs(presente[pos] + dif) <= 5)
        if (equilibrio(presente, N, pesoEsq + presente[pos], pesoDir, pos + 1))
            return true;

    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T, N;
    int peso_presentes[10005];

    std::cin >> T;
    while (T--)
    {
        std::cin >> N;
        // memset(dp, false, sizeof(dp));

        for (int i = 0; i < N; i++)
            std::cin >> peso_presentes[i];

        std::cout << (equilibrio(peso_presentes, N, 0, 0, 0) ? "Feliz Natal!\n" : "Ho Ho Ho!\n");
    }
    return 0;
}
