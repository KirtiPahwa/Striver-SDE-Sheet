void dfs(vector<int> adj[], int vis[], int start, vector<int> &temp)
{
    temp.push_back(start);
    vis[start] = 1;
    for (int i = 0; i < adj[start].size(); i++)
    {
        if (vis[adj[start][i]] == 0)
        {
            dfs(adj, vis, adj[start][i], temp);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    vector<int> adj[V];
    for (auto x : edges)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    int vis[V] = {};

    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            vector<int> temp;
            dfs(adj, vis, i, temp);
            ans.push_back(temp);
        }
    }
    return ans;
}