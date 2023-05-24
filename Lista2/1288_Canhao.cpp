#include <cstdio>
#include <vector>
#include <algorithm>

struct Projetil
{
    int poder;
    int peso;
};

bool missao(int N, int K, int R, const std::vector<Projetil> &proj)
{
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(101, 0));

    for (int i = 0; i < N; i++)
    {
        int poder = proj[i].poder;
        int peso = proj[i].peso;

        for (int j = 0; j < 100; j++)
            if (j < peso)
                dp[i + 1][j] = dp[i][j];
            else
                dp[i + 1][j] = std::max(dp[i][j], dp[i][j - peso] + poder);
    }

    return dp[N][K] >= R;
}

int main()
{
    int chumbo, c = 0;
    scanf("%d", &chumbo);

    while (c < chumbo)
    {
        int N;
        scanf("%d", &N);

        std::vector<Projetil> proj(N);
        for (int i = 0; i < N; i++)
            scanf("%d %d", &proj[i].poder, &proj[i].peso);

        int K, R;
        scanf("%d %d", &K, &R);

        if (missao(N, K, R, proj))
            printf("Missao completada com sucesso\n");
        else
            printf("Falha na missao\n");

        c++;
    }

    return 0;
}
