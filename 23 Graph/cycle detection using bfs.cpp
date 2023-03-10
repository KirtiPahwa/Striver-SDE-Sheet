#include <bits/stdc++.h>
bool bfs(int s, int n, vector<int> adj[], int *vis)
{
    queue<pair<int, int>> q;
    q.push({s, -1});
    vis[s] = 1;
    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();
        for (int i = 0; i < adj[node.first].size(); i++)
        {
            if (vis[adj[node.first][i]] == 1 && adj[node.first][i] != node.second)
            {
                return true;
            }
            else if (vis[adj[node.first][i]] == 0 && adj[node.first][i] != node.second)
            {
                q.push({adj[node.first][i], node.first});
                vis[adj[node.first][i]] = 1;
            }
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
        if (vis[i] != 1)
        {
            if (bfs(i, n + 1, adj, vis))
                return "Yes";
        }
    }

    return "No";
}
