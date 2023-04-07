// Saco do Papai Noel - Knapsack problem usando programação dinâmica
#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int p_max, const vector<int> &peso, const vector<int> &qt_toys,
             int n, int &qnt_brinquedos, int &peso_total)
{
    int i, j;
    int table[n + 1][p_max + 1];

    // tabela com os valores, tirando o máximo a cada linha
    // o melhor vai ser a ultima célula
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= p_max; j++)
        {
            if (i == 0 || j == 0)
                table[i][j] = 0;
            else if (peso[i - 1] <= j)
            {
                table[i][j] = max(qt_toys[i - 1] + table[i - 1][j - peso[i - 1]],
                                  table[i - 1][j]);
            }
            else
            {
                table[i][j] = table[i - 1][j];
            }
        }
    }

    // quantidade de brinquedos e peso total que está levando
    qnt_brinquedos = 0, peso_total = 0;
    i = n;
    j = p_max;
    while (i > 0 && j > 0)
    {
        if (table[i][j] != table[i - 1][j])
        {
            peso_total += peso[i - 1];
            qnt_brinquedos++;
            j -= peso[i - 1];
            i--;
        }
        else
        {
            i--;
        }
    }

    return table[n][p_max];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int p_max = 50, viagens, v = 0;
    scanf("%d", &viagens);

    while (v < viagens)
    {
        int pac;
        scanf("%d", &pac);
        vector<int> qt(pac), peso(pac);

        for (int i = 0; i < pac; i++)
        {
            scanf("%d %d", &qt[i], &peso[i]);
        }

        // Impressão final
        int qt_total, p_total;
        if (v > 0)
            cout << "\n";
        cout << knapSack(p_max, peso, qt, pac, qt_total, p_total)
             << " brinquedos\n";
        cout << "Peso: " << p_total << " kg\n";
        cout << "sobra(m) " << pac - qt_total << " pacote(s)\n";

        v++;
    }
    cout << "\n";

    return 0;
}