// 2784 - Ilhas (Algoritmo de Dijkstra)
#include <cstdio>
#include <vector>
#include <queue>

#define INF 0x3f3f3f3f

class Graph
{
    int V;
    std::vector<std::vector<std::pair<int, int>>> adj;

public:
    Graph(int V);
    void aresta(int u, int v, int w);
    int Caminho_Dijkstra(int servidor, int dest);
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::aresta(int u, int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

int Graph::Caminho_Dijkstra(int servidor, int dest)
{
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> priori;
    std::vector<int> dist(V, INF);
    priori.push({0, servidor});
    dist[servidor] = 0;
    int menorDist = INF;
    while (!priori.empty())
    {
        int u = priori.top().second;
        priori.pop();
        if (u == dest)
        {
            break;
        }
        for (auto i : adj[u])
        {
            int v = i.first;
            int weight = i.second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                priori.push({dist[v], v});
            }
        }
    }
    return dist[dest];
}

int main()
{
    int N, M, Servidor;
    scanf("%d %d", &N, &M);
    Graph g(N);
    for (int i = 0; i < M; i++)
    {
        int u, v, Ping;
        scanf("%d %d %d", &u, &v, &Ping);
        g.aresta(u - 1, v - 1, Ping);
    }
    scanf("%d", &Servidor);
    int maiorDist = 0, menorDist = INF;
    for (int i = 0; i < N; i++)
    {
        if (i != Servidor - 1)
        {
            int dis = 0;
            dis = g.Caminho_Dijkstra(i, Servidor - 1);
            maiorDist = std::max(dis, maiorDist);
            menorDist = std::min(dis, menorDist);
        }
    }
    printf("%d\n", maiorDist - menorDist);
    return 0;
}