#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int INF = 1e9 + 7;

struct Spell
{
    int mana;
    int dano;
};

int knapsack(int qnt, int i, const vector<Spell> &spells, int N, vector<vector<int>> &dp)
{
    if (qnt <= 0)
        return 0;

    if (i == N)
        return INF;

    if (dp[qnt][i] != -1)
        return dp[qnt][i];

    int mana = spells[i].mana;
    int dano = spells[i].dano;

    int usa_spell = dano + knapsack(qnt - mana, i + 1, spells, N, dp);
    int prox_spell = knapsack(qnt, i + 1, spells, N, dp);

    return dp[qnt][i] = min(usa_spell, prox_spell);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, HP;
    while (cin >> N >> HP)
    {
        vector<vector<int>> dp(HP + 1, vector<int>(N + 1, -1));

        vector<Spell> spells(N);
        for (int i = 0; i < N; i++)
            cin >> spells[i].mana >> spells[i].dano;

        int ans = knapsack(HP, 0, spells, N, dp);
        if (ans != INF)
            cout << ans << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}
