#include <bits/stdc++.h>
vector<pair<pair<int, int>, int>> prims(vector<pair<int, int>> adj[], int n, int m)
{
    bool *vis = new bool[n + 1];
    int *parent = new int[n + 1];
    int *weight = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        weight[i] = INT_MAX;
        vis[i] = false;
    }
    parent[1] = -1;
    weight[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    for (int i = 0; i < n - 1; i++)
    {
        //         min univisted
        pair<int, int> minV = pq.top();
        pq.pop();
        int u = minV.second;
        vis[u] = true;

        for (auto x : adj[u])
        {
            int v = x.first;
            int w = x.second;
            if (!vis[v] && weight[v] > w)
            {
                weight[v] = w;
                pq.push({weight[v], v});
                parent[v] = u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    for (int i = 2; i <= n; i++)
    {
        if (parent[i] < i)
        {
            ans.push_back({{parent[i], i}, weight[i]});
        }
        else
        {
            ans.push_back({{i, parent[i]}, weight[i]});
        }
    }
    return ans;
}

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int, int>> adj[n + 1];
    for (auto x : g)
    {
        adj[x.first.first].push_back({x.first.second, x.second});
        adj[x.first.second].push_back({x.first.first, x.second});
    }
    return prims(adj, n, m);
}
