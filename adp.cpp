#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;
const int INF = 0x3f3f3f3f;

class Grafo
{
public:
    vector<vector<pair<int, int>>> adj;
    map<int, int> limiteSC; // Limite de cada cavalo

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
    }

    int findMaximumMatches();
    bool findPath(vector<int> &parent, int policial);
};

int Grafo::findMaximumMatches()
{
}

bool Grafo::findPath(vector<int> &parent, int policial)
{
}

int main()
{
    int n, m, k;
    int inst = 1;
    while (cin >> n >> m >> k)
    {
        cout << "Instancia " << inst << endl;
        Grafo grafo;
        for (int i = 0; i < n; i++)
        {
            int max;
            cin >> max;
            grafo.limiteSC[i] = max; // Limite de cada cavalo
        }
        for (int i = 0; i < k; i++)
        {
            int cavalo, policial;
            cin >> cavalo >> policial;
            grafo.adicionarAresta(cavalo - 1, policial - 1); // Adjust the indices here
        }
        cout << grafo.findMaximumMatches() << endl
             << endl;
        inst++;
    }

    return 0;
}
