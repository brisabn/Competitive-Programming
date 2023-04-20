// 1086 - O SALÃO DO CLUBE
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

void backtrack(vector<int> &tabuas, vector<int> &sol, int target, int sum,
               int idx, int &best_size, vector<int> &best_sol)
{
    if (sum > target)
        return;

    if (sum == target && (sol.size() < best_size || best_size == -1))
    {
        best_size = sol.size();
        best_sol = sol;
        return;
    }

    for (int i = idx; i < tabuas.size(); i++)
    {
        sol.push_back(tabuas[i]);
        backtrack(tabuas, sol, target, sum + tabuas[i], i + 1, best_size, best_sol);
        sol.pop_back();
    }
}

int cobertura(vector<int> &tabuas, vector<int> &sol, int target, int sum,
              int idx, int &best_size, vector<int> &best_sol, int fila)
{

    for (int i = 0; i < tabuas.size(); i++)
    {
        int maior;
        if (tabuas[i] > maior)
            tabuas.erase(find(tabuas.begin(), tabuas.end(), tabuas[i]));
    }

    int qnt = 0, want = 0;
    while (true && want < fila)
    {
        backtrack(tabuas, sol, target, 0, 0, best_size, best_sol);

        if (best_size == -1)
            break;

        qnt += best_size;

        for (int i = 0; i < best_sol.size(); i++)
        {
            tabuas.erase(find(tabuas.begin(), tabuas.end(), best_sol[i]));
        }
        best_sol.clear();
        best_size = -1;

        want++;
    }

    if (want < fila)
        return -1;

    else
        return qnt;
}

int main()
{
    int M, N, L, K;
    while (scanf("%d %d", &M, &N))
    {
        if (M == 0 && N == 0)
            return 0;
        scanf("%d", &L);
        scanf("%d", &K);

        vector<int> tabuas;
        for (int i = 0; i < K; i++)
        {
            int comp;
            scanf("%d", &comp);
            tabuas.push_back(comp);
        }

        sort(tabuas.begin(), tabuas.end());

        vector<int> best_sol;
        int best_size = -1;
        vector<int> sol;

        int fila = (M * 100) / L, coluna = (N * 100) / L;
        int pe, deitado;
        int larg_m = (M * 100) % L, larg_n = (N * 100) % L;

        if (larg_n == 0 && larg_m == 0)
        {
            if (larg_m == 0)
            {
                pe = cobertura(tabuas, sol, N, 0, 0, best_size, best_sol, fila);
            }
            if (larg_n == 0)
            {
                deitado = cobertura(tabuas, sol, M, 0, 0, best_size, best_sol, coluna);
            }

            if (pe == -1 && deitado == -1)
                printf("impossivel\n");
            else
            {
                if (pe == -1 && deitado > 0)
                    printf("%d\n", deitado);
                else if (pe > 0 && deitado == -1)
                    printf("%d\n", pe);
                else if ((pe != -1 && deitado != -1))
                {
                    if (pe < deitado)
                        printf("%d\n", pe);
                    else if (deitado < pe)
                        printf("%d\n", deitado);
                }
            }
        }
        else
            printf("impossivel\n");
    }

    return 0;
}