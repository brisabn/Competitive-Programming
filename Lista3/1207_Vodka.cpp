#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using std::vector;

const int INF = 0x3f3f3f3f;

class Grafo
{
private:
    int V;
    vector<vector<int>> grafo;

public:
    Grafo(int vertices) : V(vertices), grafo(vertices, vector<int>(vertices, 0)) {}

    void addEdge(int u, int v, int peso)
    {
        grafo[u][v] = peso;
    }

    bool bfsD(vector<vector<int>> &gResidual, vector<int> &nivel, int s, int t);
    int dfsD(vector<vector<int>> &gResidual, vector<int> &nivel, vector<int> &ptr, int u, int t, int f);
    int Dinic(int s, int t);
};

bool Grafo::bfsD(vector<vector<int>> &gResidual, vector<int> &nivel, int s, int t)
{
    nivel.assign(V, -1);
    nivel[s] = 0;

    std::queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; v++)
        {
            if (nivel[v] == -1 && gResidual[u][v] > 0)
            {
                nivel[v] = nivel[u] + 1;
                q.push(v);
            }
        }
    }

    return nivel[t] != -1;
}

int Grafo::dfsD(vector<vector<int>> &gResidual, vector<int> &nivel, vector<int> &ptr, int u, int t, int f)
{
    if (u == t)
        return f;

    for (int &v = ptr[u]; v < V; v++)
    {
        if (nivel[v] == nivel[u] + 1 && gResidual[u][v] > 0)
        {
            int pathFluxo = dfsD(gResidual, nivel, ptr, v, t, std::min(f, gResidual[u][v]));
            if (pathFluxo > 0)
            {
                gResidual[u][v] -= pathFluxo;
                gResidual[v][u] += pathFluxo;
                return pathFluxo;
            }
        }
    }

    return 0;
}

int Grafo::Dinic(int s, int t)
{
    vector<vector<int>> gResidual(V, vector<int>(V));
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            gResidual[u][v] = grafo[u][v];

    int fluxoMax = 0;
    vector<int> nivel(V);

    while (bfsD(gResidual, nivel, s, t))
    {
        vector<int> ptr(V, 0);
        while (int pathFluxo = dfsD(gResidual, nivel, ptr, s, t, INF))
            fluxoMax += pathFluxo;
    }

    return fluxoMax;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int V;
    int N, M;
    vector<int> custo(605), qnt(405), beneficio(405);

    while (scanf("%d %d", &N, &M) == 2)
    {
        V = N + M + 3;
        int fonte = 0, pia = N + M + 2;
        Grafo g(V);

        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &custo[i]);
            g.addEdge(fonte, i, custo[i]);
            g.addEdge(i, fonte, 0);
        }

        for (int i = 1; i <= M; i++)
            scanf("%d", &qnt[i]);

        int sum = 0, v;
        for (int i = 1; i <= M; i++)
        {
            scanf("%d", &beneficio[i]);
            sum += beneficio[i];
            g.addEdge(N + i, pia, beneficio[i]);
            g.addEdge(pia, N + 1, 0);

            for (int j = 0; j < qnt[i]; j++)
            {
                scanf("%d", &v);
                g.addEdge(v, N + i, INF);
                g.addEdge(N + i, v, 0);
            }
        }

        printf("%d\n", sum - g.Dinic(fonte, pia));
    }

    return 0;
}
