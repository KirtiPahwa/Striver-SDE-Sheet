class Solution
{
public:
    bool bfs(vector<vector<int>> &adj, int node, int *color)
    {
        queue<int> q;
        q.push(node);
        color[node] = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            // cout<<node<<" "<<color[node]<<endl;
            for (auto x : adj[node])
            {
                if (color[x] == -1)
                {
                    color[x] = color[node] ^ 1;
                    // cout<<x<<" true "<<color[x]<<endl;
                    q.push(x);
                }
                else if (color[x] == color[node])
                {
                    // cout<<x<<" f "<<color[x]<<endl;
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int v = graph.size();

        int *color = new int[v];
        for (int i = 0; i < v; i++)
        {
            color[i] = -1;
        }

        for (int i = 0; i < v; i++)
        {
            if (color[i] == -1)
            {
                if (!bfs(graph, i, color))
                {
                    return false;
                }
            }
        }
        return true;
    }
};