#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

const int MAX_V = 26;

class Grafo // acho que fica mais claro enxergar com classe, e menos parametros pra dfs
{
public:
    vector<int> adj[MAX_V];
    bool visited[MAX_V];

    void dfs(int u, vector<int> &comp);
};

void Grafo::dfs(int u, vector<int> &comp)
{
    visited[u] = true;
    comp.push_back(u);
    for (int v : adj[u]) // isso aqui foi bem útil! yee, for inteligente é mt bom
    {
        if (!visited[v])
        {
            dfs(v, comp);
        }
    }
}

int main()
{
    int case_ = 0, cases;
    scanf("%d", &cases);

    while (case_ < cases)
    {
        Grafo g;
        vector<vector<int>> components;

        int V, E;
        scanf("%d %d", &V, &E);

        for (int i = 0; i < V; i++)
        {
            g.visited[i] = false;
        }

        // leitura das arestas
        for (int i = 0; i < E; i++)
        {
            char u, v;
            scanf(" %c %c", &u, &v);
            g.adj[u - 'a'].push_back(v - 'a');
            g.adj[v - 'a'].push_back(u - 'a');
        }

        for (int u = 0; u < V; u++)
        {
            if (!g.visited[u])
            {
                vector<int> comp;
                g.dfs(u, comp);
                components.push_back(comp);
            }
        }

        // pra GARANTIR, já q pd não ter sido encontrado em ordem
        sort(components.begin(), components.end());

        printf("Case #%d:\n", case_ + 1);

        // tipo matriz, já que é vector de vector...
        for (int i = 0; i < components.size(); i++)
        {
            sort(components[i].begin(), components[i].end());
            for (int u : components[i])
            {
                printf("%c,", char(u + 'a'));
            }
            printf("\n");
        }
        printf("%lu connected components\n\n", components.size());

        case_++;
    }
    return 0;
}
