// 1086 - O SALÃO DO CLUBE
#include <algorithm>
#include <iostream>
#include <vector>

const int INF = 0x3f3f3f3f;

struct Tabuas
{
    int comp;
    bool usado = false;
};

bool greaterTabua(const Tabuas &a, const Tabuas &b)
{
    return a.comp > b.comp;
}

int cobertura(std::vector<Tabuas> &tabuas, int total, int dim_max)
{
    int qnt = 0, cob = 0;
    int left = 0, right = tabuas.size() - 1;

    while (left <= right && cob < dim_max)
    {
        if (!tabuas[left].usado)
        {
            if (tabuas[left].comp == total)
            {
                tabuas[left].usado = true;
                qnt += 1;
                cob++;
                left++;
            }
            else if (tabuas[left].comp + tabuas[right].comp == total && left != right)
            {
                tabuas[left].usado = true;
                tabuas[right].usado = true;
                qnt += 2;
                cob++;
                left++;
                right--;
            }
            else if (tabuas[left].comp + tabuas[right].comp < total && left != right)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        else
        {
            left++;
        }
    }

    if (cob < dim_max)
        return INF;
    return qnt;
}

int main()
{
    int M, N, L, K;

    while (scanf("%d %d", &M, &N))
    {
        std::vector<Tabuas> tabuas_p, tabuas_d;

        if (M == 0 && N == 0)
            return 0;

        scanf("%d", &L);
        scanf("%d", &K);

        for (int i = 0; i < K; i++)
        {
            Tabuas t;
            int comp;
            scanf("%d", &comp);
            if (comp <= M || comp <= N)
            {
                t.comp = comp;
                tabuas_p.push_back(t);
            }
        }

        sort(tabuas_p.begin(), tabuas_p.end(), greaterTabua);
        tabuas_d = tabuas_p;

        int qnt_n = (N * 100) / L, qnt_m = (M * 100) / L;
        int p = INF, d = INF;

        if (((N * 100) % L == 0) || ((M * 100) % L == 0))
        {
            if ((N * 100) % L == 0)
                p = cobertura(tabuas_p, M, qnt_n);
            if ((M * 100) % L == 0)
                d = cobertura(tabuas_d, N, qnt_m);

            int best = std::min(p, d);
            if (best == INF)
                printf("impossivel\n");
            else
                printf("%d\n", best);
        }
        else
            printf("impossivel\n");
    }

    return 0;
}