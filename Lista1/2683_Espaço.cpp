#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, custo;
};

int kruskal_min(const vector<Edge> &aresta, int n)
{
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
    }

    int ans = 0;
    for (const auto &a : aresta)
    {
        int u = a.u, v = a.v, w = a.custo;
        while (parent[u] != u)
        {
            u = parent[u];
        }

        while (parent[v] != v)
        {
            v = parent[v];
        }

        if (u != v)
        {
            parent[u] = v;
            ans += w;
        }
    }

    return ans;
}

int kruskal_max(const vector<Edge> &aresta, int n)
{
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
    }

    int ans = 0;
    for (const auto &a : aresta)
    {
        int u = a.u, v = a.v, w = a.custo;

        while (parent[u] != u)
        {
            u = parent[u];
        }

        while (parent[v] != v)
        {
            v = parent[v];
        }

        if (u != v)
        {
            parent[u] = v;
            ans += w;
        }
    }

    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<Edge> aresta(n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d %d", &aresta[i].u, &aresta[i].v, &aresta[i].custo);
    }

    sort(aresta.begin(), aresta.end(),
         [](const Edge &a, const Edge &b)
         { return a.custo > b.custo; });

    printf("%d\n", kruskal_max(aresta, n));

    sort(aresta.begin(), aresta.end(),
         [](const Edge &a, const Edge &b)
         { return a.custo < b.custo; });

    printf("%d\n", kruskal_min(aresta, n));

    return 0;
}