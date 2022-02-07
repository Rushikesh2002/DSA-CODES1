#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m;
    cout << "Enter No of vertices and Edges Respectively:- " << endl;
    cin >> n >> m;

    vector<int> dist(n + 1, INT_MAX);

    vector<vector<pair<int, int>>> graph(n + 1);

    int adjmat[n][n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjmat[i][j] = 0;
        }
    }
    cout << "Enter Source node, Destination node and Weight Respectively:- " << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
        adjmat[u - 1][v - 1] = w;
    }

    int source;
    cout << "Enter Source:- " << endl;
    cin >> source;

    set<pair<int, int>> s;
    dist[source] = 0;

    s.insert({0, source});
    while (!s.empty())
    {

        auto x = *(s.begin());

        s.erase(x);

        for (auto it : graph[x.second])
        {

            if (dist[it.first] > dist[x.second] + it.second)
            {

                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first], it.first});
            }
        }
    }
    cout << "Adjacency Matrix:- " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adjmat[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Egde    Distance from Souce" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] < INT_MAX)
        {
            cout << i << "             " << dist[i] << endl;
        }
        else
        {
            cout << -1 << " ";
        }
    }
    return 0;
}