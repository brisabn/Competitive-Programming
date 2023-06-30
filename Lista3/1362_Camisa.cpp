#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 0x3f3f3f3f;

class Grafo
{
public:
    int V;
    vector<vector<int>> grafo;

    Grafo(int numVertices) : V(numVertices)
    {
        grafo.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v, int w)
    {
        grafo[u][v] = w;
        grafo[v][u] = w;
    }

    void addShirts(int tam1, int tam2, int i, int M)
    {
        addEdge(tam1, 6 + i, 1);
        addEdge(6 + i, tam1, 1);
        addEdge(6 + i, tam2, 1);
        addEdge(tam2, 6 + i, 1);
        addEdge(6 + i, M + 7, 1);
        addEdge(M + 7, 6 + i, 1);
    }

    int fordFulkerson(int s, int t);
    bool bfs(vector<vector<int>> &gResidual, int s, int t, vector<int> &parent);
};

int Grafo::fordFulkerson(int s, int t)
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

bool Grafo::bfs(vector<vector<int>> &gResidual, int s, int t, vector<int> &parent)
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

int main()
{
    int N, M, casos;
    vector<pair<string, int>> tam = {{"XXL", 1}, {"XL", 2}, {"L", 3}, {"M", 4}, {"S", 5}, {"XS", 6}};

    cin >> casos;
    while (casos--)
    {
        cin >> N >> M;
        // M número de voluntários
        Grafo grafo(M + 8);

        for (int i = 1; i <= 6; ++i)
        {
            grafo.addEdge(0, i, N / 6);
        }

        for (int i = 1; i <= M; ++i)
        {
            string a, b;
            cin >> a >> b;
            int tam1, tam2;
            for (const auto &pair : tam)
            {
                if (pair.first == a)
                    tam1 = pair.second;
                if (pair.first == b)
                    tam2 = pair.second;
            }
            grafo.addShirts(tam1, tam2, i, M);
        }

        // fordFulkerson adaptado é o Edmonds Karp
        cout << (grafo.fordFulkerson(0, M + 7) == M ? "YES\n" : "NO\n");
    }

    return 0;
}
