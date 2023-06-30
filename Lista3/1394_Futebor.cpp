#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <deque>
#include <cstring>
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

    Graph(int n) : adj(n), maxFlow(0) {}

    void addEdge(int a, int b, int c)
    {
        adj[a].emplace_back(b, c, adj[b].size(), false);
        adj[b].emplace_back(a, 0, adj[a].size() - 1, true);
    }

    bool bfs(int source, int target)
    {
        level = vector<int>(adj.size(), -1);
        level[source] = 0;
        start = vector<int>(adj.size(), 0);
        queue<int> q;
        q.push(source);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto &e : adj[u])
            {
                if (level[e.to] != -1 || e.flow == e.cap)
                    continue;
                level[e.to] = level[u] + 1;
                q.push(e.to);
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

class Futebol
{
public:
    vector<int> pontos;
    vector<vector<int>> jogos;

    int jogado;
    Futebol(int N)
    {
        pontos = vector<int>(N, 0);
        jogos = vector<vector<int>>(N, vector<int>(N, 0));
        jogado = 0;
    }

    void adicionarPartida(int u, char result, int v)
    {
        if (result == '<')
            pontos[v] += 2;
        if (result == '==') // melhor assi
        {
            pontos[u]++;
            pontos[v]++;
        }
        jogos[u][v]++;
        jogos[v][u]++;
    }

    void timaoVencendo(int M, int N)
    {
        for (int i = 1; i < N; i++)
        {
            int resta_jogar = M - jogos[0][i];
            jogado += resta_jogar;

            pontos[0] += 2 * resta_jogar;
            jogos[0][i] += resta_jogar;
            jogos[i][0] += resta_jogar;
        }
    }
};

int main()
{
    // uaarrrr que código custoso. lembrete para estudar o que aprendi aki
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, G;

    while (cin >> N >> M >> G && (N != 0) && (M != 0) && (G != 0))
    {
        // Modelando as partidas garantidas de futebol
        Futebol fut(N);

        for (int i = 0; i < G; i++)
        {
            int u, v;
            char result;
            cin >> u >> result >> v;
            fut.adicionarPartida(u, result, v);
        }
        fut.timaoVencendo(M, N);                              // assume que time 0 ganha todas as outras
        int remaining = N * (N - 1) * M / 2 - G - fut.jogado; // yaaas essa formula foi util agr

        // Modelando o grafo de fluxo do futebol
        Graph graph(remaining + N + 1);
        for (int i = 1; i < N; i++) // os outros times podem fazer no maximo p0 - oq fez - 1
            graph.addEdge(i + remaining, N + remaining, fut.pontos[0] - fut.pontos[i] - 1);

        int partida = 0;
        for (int i = 1; i < N; i++)
            for (int j = 1; j < N; j++)
                for (int k = fut.jogos[i][j]; k < M && i != j; k++)
                {
                    partida++;
                    fut.jogos[i][j]++;
                    fut.jogos[j][i]++;

                    graph.addEdge(0, partida, 2);
                    graph.addEdge(partida, i + remaining, 2);
                    graph.addEdge(partida, j + remaining, 2);
                }

        cout << (graph.Dinic(0, N + remaining) == 2 * remaining ? 'Y' : 'N') << endl;
    }
}
