#include <iostream>

int cinema[305][305];
int dp[305][305];

void menor_retangulo(int R, int C, int K)
{
    // ao invés de ficar somando toooooda vez
    for (int i = 1; i <= R; i++)
        for (int t = 1; t <= C; t++)
            dp[i][t] = dp[i - 1][t] + dp[i][t - 1] - dp[i - 1][t - 1] + cinema[i - 1][t - 1];

    int resp = R * C;

    // metodo dos dois ponteiros que foi revelado por mim atraves de um sonho
    // !! muito útil !!
    for (int esq = 1; esq <= C; esq++)
    {
        for (int dir = esq; dir <= C; dir++)
        {
            int sum = 0;
            int t = 1;
            for (int b = 1; b <= R; b++)
            {
                sum = dp[b][dir] - dp[b][esq - 1] - dp[t - 1][dir] + dp[t - 1][esq - 1];

                if (sum >= K)
                {
                    resp = std::min(resp, (b - t + 1) * (dir - esq + 1));

                    while (sum >= K) // aqui q foi a jogada meeeh
                    {
                        sum = dp[b][dir] - dp[b][esq - 1] - dp[t][dir] + dp[t][esq - 1];
                        t++;
                        if (sum >= K)
                            resp = std::min(resp, (b - t + 1) * (dir - esq + 1));
                    }
                }
            }
        }
    }

    std::cout << resp << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int R, C, K;
    while (scanf("%d %d %d", &R, &C, &K) && R != 0 && C != 0 && K != 0)
    {
        for (int i = 0; i < R; i++)
            for (int t = 0; t < C; t++)
            {
                char x;
                scanf(" %c", &x);
                cinema[i][t] = (x == '.') ? 1 : 0;
            }

        menor_retangulo(R, C, K);
    }

    return 0;
}