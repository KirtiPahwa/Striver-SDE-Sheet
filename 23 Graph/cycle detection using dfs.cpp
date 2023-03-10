#include <bits/stdc++.h>
bool dfs(int s, int p, int n, vector<int> adj[], int *vis)
{
    vis[s] = 1;
    for (int i = 0; i < adj[s].size(); i++)
    {
        if (!vis[adj[s][i]])
        {
            if (dfs(adj[s][i], s, n, adj, vis))
                return true;
        }
        else if (adj[s][i] != p)
        {
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &prerequisites, int n, int m)
{
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    int *vis = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        vis[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            if (dfs(i, -1, n + 1, adj, vis))
                return "Yes";
        }
    }

    return "No";
}
