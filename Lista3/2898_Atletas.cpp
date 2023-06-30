#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;

class Graph
{
public:
    struct Edge
    {
        int to, cap, rev, flow;
        bool res;
        Edge(int to_, int cap_, int rev_, bool res_)
            : to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
    };

    vector<vector<Edge>> adj;
    vector<int> level, start;
    long long maxFlow;

    Graph(int n) : adj(n), maxFlow(0)
    {
        adj.reserve(n);
    }

    void addEdge(int a, int b, int c)
    {
        adj[a].emplace_back(b, c, adj[b].size(), false);
        adj[b].emplace_back(a, 0, adj[a].size() - 1, true);
    }

    bool bfs(int source, int target)
    {
        level.assign(adj.size(), -1);
        level[source] = 0;
        start.assign(adj.size(), 0);
        deque<int> q;
        q.push_back(source);
        while (!q.empty())
        {
            int u = q.front();
            q.pop_front();
            for (auto &e : adj[u])
            {
                if (level[e.to] != -1 || e.flow == e.cap)
                    continue;
                level[e.to] = level[u] + 1;
                q.push_back(e.to);
            }
        }
        return level[target] != -1;
    }

    int dfs(int v, int source, int f = INF)
    {
        if (!f || v == source)
            return f;
        for (int &i = start[v]; i < adj[v].size(); i++)
        {
            auto &edge = adj[v][i];
            if (level[edge.to] != level[v] + 1)
                continue;
            int minFlow = dfs(edge.to, source, min(f, edge.cap - edge.flow));
            if (!minFlow)
                continue;
            edge.flow += minFlow, adj[edge.to][edge.rev].flow -= minFlow;
            return minFlow;
        }
        return 0;
    }

    long long Dinic(int source, int target)
    {
        while (bfs(source, target))
            while (int f = dfs(source, target))
                maxFlow += f;
        return maxFlow;
    }
};

class Aviao
{
public:
    vector<int> origem, destino, assentos;
    Aviao(int N) : origem(N, 0), destino(N, 0), assentos(N, 0) {}

    int calcularMinDias(int atletas, Graph &g, int aeroportos)
    {
        int minDias = 0;
        bool flowViagem = false;
        g.addEdge(0, 1, atletas);

        while (!flowViagem)
        {
            minDias++;
            g.addEdge(0, minDias * aeroportos + 1, atletas);

            for (int i = 0; i < origem.size(); i++)
            {
                g.addEdge(origem[i] + aeroportos * (minDias - 1), destino[i] + aeroportos * minDias, assentos[i]);
            }
            g.addEdge(aeroportos + (aeroportos * minDias), g.adj.size() - 1, INF);

            if (g.Dinic(0, g.adj.size() - 1) >= atletas)
                flowViagem = true;
        }

        return minDias;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int aeroportos, voos, atletas;
    while ((scanf("%d %d %d", &aeroportos, &voos, &atletas) == 3) && (aeroportos != 0) && (voos != 0) && (atletas != 0))
    {
        // Modelando os aviões ihuuu
        Aviao f(voos);
        for (int i = 0; i < voos; i++)
            scanf("%d %d %d", &f.origem[i], &f.destino[i], &f.assentos[i]);

        // Modelando viagens
        int v = aeroportos * 101 + 2;
        int source = 0, terminal = aeroportos * 101 + 1;
        Graph g(v);

        // Calcular mínimo de dias
        printf("%d\n", f.calcularMinDias(atletas, g, aeroportos));
    }
    printf("\n");

    return 0;
}