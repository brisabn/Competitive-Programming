#include <iostream>
#include <vector>
using namespace std;

vector<int> bolas;
vector<int> spaces;
// vector<int> roleta;
const int INF = 0x3f3f3f3f;

int jogo(int S, int B)
{
    vector<vector<int>> dp(B, vector<int>(S, INF));
    // // roleta[N] = roleta[0];
    // // for (int i = 0; i <= N; i++)
    // //     roleta[i] = roleta[i] + roleta[i + 1];
    // for (int j = 0; j < N; j++)
    // {
    //     dp[1][j] = bolas[0] * (roleta[j]);
    // }

    int lucro = INF;
    for (int i = 0; i < S; i++)
    {
        dp[0][i] = bolas[0] * (spaces[0] + spaces[1]);
    }
    for (int i = 1; i < B; i++)
    {
        for (int j = 2; j < S - 1; j++)
        {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 2] + (bolas[i]) * (spaces[j] + spaces[j + 1]));
        }
    }
    lucro = min(lucro, dp[B - 1][S - 2]);
    return lucro;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int S, B;
    while (cin >> S >> B && S != 0 && B != 0)
    {
        spaces.resize(S);
        for (int i = 0; i < S; i++)
            cin >> spaces[i];

        bolas.resize(B);
        for (int i = 0; i < B; i++)
            cin >> bolas[i];

        int lucro = INF;
        // for (int rotation = 0; rotation < S; rotation++)
        // {
        //     roleta.resize(S);
        //     for (int i = 0; i < S; i++)
        //     {
        //         roleta[i] = spaces[(i + rotation) % S];
        //     }
        //     lucro = min(lucro, jogo(S, B));
        // }
        for (int k = 0; k <= S; k++)
        {
            lucro = min(lucro, jogo(S, B));
            // aaaaaaaarg essa forma de girar a roleta fica BEM MAIS FÁCIL AGGRGGRGRGR
            spaces.push_back(spaces[0]);
            spaces.erase(spaces.begin());
        }
        cout << -lucro << endl;
    }
}