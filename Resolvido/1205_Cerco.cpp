// 1205 - Cerco a Leningrado (Dijkstra nos vértices )
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define INF 0x3f3f3f3f

struct Vertex
{
    int id;
    int num_soldiers = 0;
};

class Grafo
{
public:
    int V;
    std::vector<std::vector<int>> adj;
    std::vector<int> num_soldiers;

    Grafo(int V);
    void aresta(int u, int v);
    int caminho(int ent, int dest, int balas);
};

Grafo::Grafo(int V)
{
    this->V = V;
    adj.resize(V);
    num_soldiers.resize(V);
}

void Grafo::aresta(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int Grafo::caminho(int ent, int dest, int balas)
{
    std::vector<int> killed(V, INF);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    killed[ent] = num_soldiers[ent];
    pq.push({killed[ent], ent});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (u == dest)
        {
            break;
        }

        for (int v : adj[u])
        {
            int balas_restantes = balas - (killed[u] + num_soldiers[v]);

            if (balas_restantes >= 0 && killed[v] > killed[u] + num_soldiers[v])
            {
                killed[v] = killed[u] + num_soldiers[v];
                pq.push({killed[v], v});
            }
        }
    }

    return killed[dest];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num_vertices;
    while (std::cin >> num_vertices)
    {
        int estradas, num_balas;
        double success_prob;
        std::cin >> estradas >> num_balas >> success_prob;

        Grafo cerco(num_vertices);

        for (int i = 0; i < estradas; i++)
        {
            Vertex u, v;
            std::cin >> u.id >> v.id;
            u.id--;
            v.id--;
            cerco.aresta(u.id, v.id);
        }

        int num_soldiers;
        std::cin >> num_soldiers;
        for (int i = 0; i < num_soldiers; i++)
        {
            int pos;
            std::cin >> pos;
            cerco.num_soldiers[pos - 1]++;
        }

        int ent, dest;
        std::cin >> ent >> dest;
        ent--;
        dest--;

        int min_soldiers = cerco.caminho(ent, dest, num_balas);
        double success = pow(success_prob, min_soldiers);
        printf("%.3f\n", success);
    }

    return 0;
}
