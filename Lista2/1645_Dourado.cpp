#include <iostream>
#include <cstring>
using namespace std;

long long contadorLIS(int sequence[], int N, int K)
{
    long long dp[N + 1][K + 1];
    // dp[qnt][tam-1]
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < N; i++) // logicamente, subsequencias com tamanho 1 que são eles mesmo, ye
        dp[i][0] = 1;

    for (int i = 1; i < N; i++) // onde q tá
    {
        for (int j = 0; j < i; j++) // antes dele
        {
            if (sequence[i] > sequence[j]) // (crescente)
            {
                for (int k = 1; k <= K; k++)
                    dp[i][k] += dp[j][k - 1];
                // caso eu use isso dps, a ideia é que pega acumulado das subsequencias anteriores com tamanho k
                // use a partir de 1 porque já tem definidinho quando é 0, aí dp[j][k - 1] é o que tá calculando
                // dos anteriores.
            }
        }
    }

    long long total = 0;
    for (int i = 0; i < N; i++)
        total += dp[i][K - 1];

    return total;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    while (cin >> N >> K && N != 0 && K != 0)
    {
        int sequence[N];
        for (int i = 0; i < N; i++)
            cin >> sequence[i];

        long long total = contadorLIS(sequence, N, K);
        cout << total << endl;
    }

    return 0;
}
