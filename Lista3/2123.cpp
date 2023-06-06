#include <iostream>
#include <queue>
#include <vector>

using namespace std;
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

    bool bfs(vector<vector<int>> &gResidual, int s, int t, vector<int> &parent)
    {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(s);
        visited[s] = true;
        parent[s] = -1;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v = 0; v < V; v++)
            {
                if (!visited[v] && gResidual[u][v] > 0)
                {
                    if (v == t)
                    {
                        parent[v] = u;
                        return true;
                    }
                    q.push(v);
                    parent[v] = u;
                    visited[v] = true;
                }
            }
        }
        return false;
    }

    int fordFulkerson(int s, int t)
    {
        vector<vector<int>> gResidual(V, vector<int>(V));
        for (int u = 0; u < V; u++)
            for (int v = 0; v < V; v++)
                gResidual[u][v] = grafo[u][v];

        vector<int> parent(V);
        int fluxoMax = 0;
        while (bfs(gResidual, s, t, parent))
        {
            int pathFluxo = INF;
            for (int v = t; v != s; v = parent[v])
            {
                int u = parent[v];
                pathFluxo = min(pathFluxo, gResidual[u][v]);
            }
            for (int v = t; v != s; v = parent[v])
            {
                int u = parent[v];
                gResidual[u][v] -= pathFluxo;
                gResidual[v][u] += pathFluxo;
            }
            fluxoMax += pathFluxo;
        }
        return fluxoMax;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V;
    int n, m, k;

    int inst = 1;
    while (scanf("%d %d %d", &n, &m, &k) == 3)
    {
        V = n + m + 2;
        int sink = 0, tink = n + m + 1;
        Grafo grafo(V);

        for (int i = 1; i <= m; i++)
        {
            grafo.addEdge(i + n, tink, 1);
        }

        for (int i = 1; i <= n; i++)
        {
            int lim;
            scanf("%d", &lim);
            grafo.addEdge(0, i, lim);
        }

        for (int i = 1; i <= k; i++)
        {
            int cavalo, soldado;
            scanf("%d %d", &cavalo, &soldado);
            grafo.addEdge(cavalo, soldado + n, 1);
            grafo.addEdge(soldado + n, cavalo, 0);
        }

        printf("Instancia %d\n", inst);
        printf("%d\n\n", grafo.fordFulkerson(0, n + m + 1));
        inst++;
    }

    return 0;
}
