#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>

using namespace std;

class Graph
{
public:
    int V;
    vector<vector<pair<int, int>>> adj;
    vector<int> atletas_alocados;

    Graph(int N)
    {
        this->V = N;
        adj.resize(V);
        atletas_alocados.resize(V);
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
    }

    void bfs(int s, int A)
    {
        vector<bool> visited(V, false);
        queue<int> queue;

        visited[s] = true;
        queue.push(s);

        while (!queue.empty())
        {
            int orig = queue.front();
            queue.pop();

            // cout << "Vertex: " << orig << endl;

            for (auto edge : adj[orig])
            {
                int dest = edge.first;
                int assentos = edge.second;

                //   cout << "Edge: (" << orig << " -> " << dest << "), assentos: " << assentos << endl;

                if (!visited[dest])
                {
                    visited[dest] = true;
                    queue.push(dest);
                }
            }
        }
    }
};

int main()
{
    int N, M, A;
    // while ((cin >> N >> M >> A) && (N != 0) && (M != 0) && (A != 0))
    {
        cin >> N >> M >> A;
        Graph g(N);
        for (int i = 0; i < M; i++)
        {
            int O, D, S;
            cin >> O >> D >> S;
            g.addEdge(O - 1, D - 1, S);
        }

        g.atletas_alocados[0] = A;
        g.bfs(0, A);

        // int days = g.minimumDays(0, N - 1, A);
        // cout << "Minimum number of days required: " << days << endl;
    }
    return 0;
}
