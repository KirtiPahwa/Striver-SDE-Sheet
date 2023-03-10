class Solution
{
public:
    bool dfs(vector<vector<int>> &adj, int node, bool *vis, int *color)
    {
        vis[node] = true;
        cout << node << " " << color[node] << endl;
        for (auto x : adj[node])
        {
            if (vis[x] && color[x] == color[node])
            {
                cout << "vis but same colored " << x << endl;
                return false;
            }
            else if (!vis[x] && color[x] == -1)
            {
                cout << "non vis and non colored " << x << endl;
                color[x] = color[node] == 1 ? 0 : 1;
                if (!dfs(adj, x, vis, color))
                {
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
        bool *vis = new bool[v];
        for (int i = 0; i < v; i++)
        {
            color[i] = -1;
            vis[i] = 0;
        }

        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                color[i] = 0;

                if (!dfs(graph, i, vis, color))
                {

                    return false;
                }
            }
        }
        return true;
    }
};