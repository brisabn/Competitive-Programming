#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f

class Graph
{
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    int shortestPath(int src, int dest);
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

int Graph::shortestPath(int src, int dest)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INF);
    pq.push({0, src});
    dist[src] = 0;
    int minDist = INF;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (u == dest)
        {
            minDist = dist[u];
            break;
        }
        for (auto i : adj[u])
        {
            int v = i.first;
            int weight = i.second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return minDist;
}

// Driver's code
int main()
{
    int N, M, Servidor;
    Graph g(N);

    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int u, v, Ping;
        scanf("%d %d %d", &u, &v, &Ping);
        g.addEdge(u - 1, v - 1, Ping);
        g.addEdge(v - 1, u - 1, Ping);
    }

    scanf("%d", &Servidor);
    int maiorDist = 0, menorDist = INF;
    for (int i = 0; i < N; i++)
    {
        if (i != Servidor - 1)
        {
            int dis = 0;
            dis = g.shortestPath(i, Servidor - 1);
            maiorDist = max(dis, maiorDist);
            menorDist = min(dis, menorDist);

            cout
                << i + 1 << " " << dis << endl;
        }
    }

    cout
        << maiorDist - menorDist << endl;

    // for (int i = 0; i < N; i++)
    //     cout << "from " << i + 1 << " " << g.shortestPath(0, Servidor) << endl;

    return 0;
}
