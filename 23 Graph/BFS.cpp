#include <bits/stdc++.h>
vector<int> BFS(int V, vector<pair<int, int>> edges)
{
    vector<int> ans;
    set<int> adj[V];
    for (auto x : edges)
    {
        adj[x.first].insert(x.second);
        adj[x.second].insert(x.first);
    }
    int vis[V] = {};
    for (int j = 0; j < V; j++)
    {
        if (vis[j] == 0)
        {
            queue<int> q;
            vis[j] = 1;
            q.push(j);
            while (!q.empty())
            {
                int node = q.front();
                ans.push_back(node);
                q.pop();
                for (auto it : adj[node])
                {
                    if (vis[it] == 0)
                    {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    return ans;
}