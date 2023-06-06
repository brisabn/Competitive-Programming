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
    map<int, vector<int>> usuarios;
    map<int, int> cavaloMatching;
    map<int, vector<int>> cavaloToPeople; // Reverse mapping from cavalos to people
    map<int, int> limiteSC;               // Limite de cada emprego
    map<int, int> dist;

    void adicionarAresta(int policial, int cavalo)
    {
        usuarios[policial].push_back(cavalo);
        cavaloToPeople[cavalo].push_back(policial);
    }

    bool bfs();
    bool dfs(int policial);
    int findMatches_Exact();
};

// EXATO COM HOPCROFT-KARP
int Grafo::findMatches_Exact()
{
    cavaloMatching.clear(); // Limpa o emparelhamento
    int numMatches = 0;

    while (bfs())
    {
        for (auto const &user : usuarios)
        {
            int policial = user.first;
            if (cavaloMatching[policial] == 0 && dfs(policial))
                numMatches++;
        }
    }

    return numMatches;
}

bool Grafo::bfs()
{
    queue<int> fila;
    for (auto const &user : usuarios)
    {
        int policial = user.first;
        if (cavaloMatching[policial] == 0)
        {
            dist[policial] = 0;
            fila.push(policial);
        }
        else
            dist[policial] = INF;
    }

    dist[0] = INF;

    // BFS
    while (!fila.empty())
    {
        int policial = fila.front();
        fila.pop();

        if (dist[policial] < dist[0])
        {
            for (const int &cavalo : usuarios[policial])
            {
                // Iterate over each person assigned to the cavalo
                for (const int &person : cavaloToPeople[cavalo])
                {
                    if (dist[cavaloMatching[person]] == INF)
                    {
                        dist[cavaloMatching[person]] = dist[policial] + 1;
                        fila.push(cavaloMatching[person]);
                    }
                }
            }
        }
    }

    return (dist[0] != INF);
}

bool Grafo::dfs(int policial)
{
    if (policial == 0)
        return true;

    for (const int &cavalo : usuarios[policial])
    {
        // Iterate over each person assigned to the cavalo
        for (const int &person : cavaloToPeople[cavalo])
        {
            if (dist[cavaloMatching[person]] == dist[policial] + 1 && dfs(cavaloMatching[person]))
            {
                cavaloMatching[policial] = cavalo;
                cavaloMatching[person] = policial;
                return true;
            }
        }
    }

    dist[policial] = INF;
    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int numPoliciais, numCavalos, afinidades;
    int inst = 1;

    while (cin >> numCavalos >> numPoliciais >> afinidades)
    {
        cout << "Instancia " << inst << endl;
        Grafo grafo;

        for (int i = 0; i < numCavalos; i++)
        {
            int max;
            cin >> max;
            grafo.limiteSC[i] = max; // Limite de cada emprego
        }

        for (int i = 0; i < afinidades; i++)
        {
            int policial, cavalo;
            cin >> policial >> cavalo;

            grafo.adicionarAresta(cavalo - 1, policial - 1);
        }
        cout << grafo.findMatches_Exact() << endl
             << endl;
        inst++;
    }

    return 0;
}
