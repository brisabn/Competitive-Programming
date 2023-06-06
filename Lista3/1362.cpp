#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
const int INF = 0x3f3f3f3f;

class Grafo
{
public:
    int V;
    vector<vector<int>> residualGrafo;
    vector<int> pai;

    Grafo(int numVertices) : V(numVertices)
    {
        residualGrafo.resize(V, vector<int>(V, 0));
        pai.resize(V);
    }

    void addEdge(int u, int v, int weight);
    void addShirtEdges(int tamA, int tamB, int i, int M);
    int edmondsKarp(int s, int t);
    bool bfs(int s, int t);
};

void Grafo::addEdge(int u, int v, int weight)
{
    residualGrafo[u][v] = weight;
}

void Grafo::addShirtEdges(int tamA, int tamB, int i, int M)
{
    addEdge(tamA, 6 + i, 1);
    addEdge(6 + i, tamA, 0);
    addEdge(6 + i, tamB, 1);
    addEdge(tamB, 6 + i, 0);
    addEdge(6 + i, M + 7, 1);
    addEdge(M + 7, 6 + 1, 0);
}

int Grafo::edmondsKarp(int s, int t)
{
    int max_flow = 0;

    while (bfs(s, t))
    {
        int path_flow = INF;

        for (int v = t; v != s; v = pai[v])
        {
            int u = pai[v];
            path_flow = min(path_flow, residualGrafo[u][v]);
        }

        for (int v = t; v != s; v = pai[v])
        {
            int u = pai[v];
            residualGrafo[u][v] -= path_flow;
            residualGrafo[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

bool Grafo::bfs(int s, int t)
{
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    pai[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; ++v)
        {
            if (!visited[v] && residualGrafo[u][v] > 0)
            {
                q.push(v);
                visited[v] = true;
                pai[v] = u;
            }
        }
    }

    return visited[t];
}

int main()
{
    int N, M, casos;
    map<string, int> tamanhos;
    tamanhos["XXL"] = 1;
    tamanhos["XL"] = 2;
    tamanhos["L"] = 3;
    tamanhos["M"] = 4;
    tamanhos["S"] = 5;
    tamanhos["XS"] = 6;

    cin >> casos;
    while (casos--)
    {
        cin >> N >> M;
        Grafo grafo(M + 8);

        for (int i = 1; i <= 6; ++i)
        {
            grafo.addEdge(0, i, N / 6);
        }

        for (int i = 1; i <= M; ++i)
        {
            string a, b;
            cin >> a >> b;
            int tamA = tamanhos[a];
            int tamB = tamanhos[b];
            grafo.addShirtEdges(tamA, tamB, i, M);
        }

        cout << (grafo.edmondsKarp(0, M + 7) == M ? "YES\n" : "NO\n");
    }

    return 0;
}
