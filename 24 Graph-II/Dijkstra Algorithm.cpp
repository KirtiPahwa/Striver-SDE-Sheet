#include <bits/stdc++.h>
vector<int> dijkstraHelper(vector<pair<int, int>> adj[], int v, int src)
{
    bool *vis = new bool[v];
    vector<int> dis(v);
    for (int i = 0; i < v; i++)
    {
        vis[i] = false;
        dis[i] = INT_MAX;
    }
    dis[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dis[src], src});
    for (int i = 0; i < v - 1; i++)
    {
        //         get min
        pair<int, int> minV = pq.top();
        pq.pop();
        int u = minV.second;
        vis[u] = true;

        for (auto x : adj[u])
        {
            int v = x.first;
            int w = x.second;
            if (!vis[v] && minV.first + w < dis[v])
            {
                dis[v] = minV.first + w;
                pq.push({dis[v], v});
            }
        }
    }

    delete vis;
    return dis;
}
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    vector<pair<int, int>> adj[vertices];
    for (int i = 0; i < edges; i++)
    {
        adj[vec[i][0]].push_back({vec[i][1], vec[i][2]});
        adj[vec[i][1]].push_back({vec[i][0], vec[i][2]});
    }
    return dijkstraHelper(adj, vertices, source);
}
