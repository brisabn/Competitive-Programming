#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
    int u, v, w;
};

int kruskal_min(const vector<Edge> &edges, int n)
{
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
    }

    int ans = 0;
    for (const auto &edge : edges)
    {
        int u = edge.u, v = edge.v, w = edge.w;
        while (parent[u] != u)
        {
            u = parent[u];
        }

        while (parent[v] != v)
        {
            v = parent[v];
        }

        if (u != v)
        {
            parent[u] = v;
            ans += w;
        }
    }

    return ans;
}

int kruskal_max(const vector<Edge> &edges, int n)
{
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
    }

    int ans = 0;
    for (const auto &edge : edges)
    {
        int u = edge.u, v = edge.v, w = edge.w;

        while (parent[u] != u)
        {
            u = parent[u];
        }

        while (parent[v] != v)
        {
            v = parent[v];
        }

        if (u != v)
        {
            parent[u] = v;
            ans += w;
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<Edge> edges(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(),
         [](const Edge &a, const Edge &b)
         { return a.w > b.w; });

    cout << kruskal_max(edges, n) << endl;

    sort(edges.begin(), edges.end(),
         [](const Edge &a, const Edge &b)
         { return a.w < b.w; });

    cout << kruskal_min(edges, n) << endl;

    return 0;
}
