#include <iostream>
#include <cstring>
#include <algorithm>

const int MAXSIZE = 1005;
int sequence[MAXSIZE];
int dp[MAXSIZE][MAXSIZE];

int jogador1(int i, int j);
int jogador2(int i, int j);

int jogador1(int i, int j)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int score = std::max(jogador2(i + 1, j) + sequence[i], jogador2(i, j - 1) + sequence[j]);
    dp[i][j] = score;
    return score;
}

int jogador2(int i, int j)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int score = std::min(jogador1(i + 1, j), jogador1(i, j - 1));
    dp[i][j] = score;
    return score;
}

int main()
{
    int N;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    while (std::cin >> N && N != 0)
    {
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < 2 * N; i++)
        {
            int num;
            std::cin >> num;
            if (num % 2 == 0)
                sequence[i] = 1;
            else
                sequence[i] = 0;
        }

        printf("%d\n", jogador1(0, 2 * N - 1));
    }

    return 0;
}
