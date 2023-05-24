#include <iostream>
#include <vector>
using namespace std;

struct Sala
{
    long double hp;
    long double bonus;
};

long double rpg(int N, int mana, int dano, const vector<Sala> &salas)
{
    vector<vector<long double>> dp(N + 1, vector<long double>(mana + 1, 0));
    // meeeh avaliar se vector ou array é mais eficiente

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= mana; j++)
        {
            dp[i][j] = dp[i - 1][j] + salas[i - 1].hp / dano;
            if (j > 0)
            {
                long double bonus_tempo = salas[i - 1].hp / (dano + salas[i - 1].bonus);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + bonus_tempo);
            }
        }
    }

    return dp[N][mana];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, mana, dano;
    vector<Sala> salas;

    while (cin >> N >> mana >> dano)
    {
        salas.reserve(N); // hmmmm deixa mais rápido?
        for (int i = 0; i < N; i++)
            cin >> salas[i].hp >> salas[i].bonus;

        long double tempo = rpg(N, mana, dano, salas);
        printf("%.4Lf\n", tempo);
    }

    return 0;
}
