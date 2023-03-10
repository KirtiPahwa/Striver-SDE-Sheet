int floyds(int **adj, int n, int s, int d)
{
    int **ans = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = new int[n + 1];
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            ans[i][j] = adj[i][j];
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (ans[i][k] != 1000000000 && ans[k][j] != 1000000000 && ans[i][k] + ans[k][j] != 1000000000 && ans[i][j] > ans[i][k] + ans[k][j])
                {
                    ans[i][j] = ans[i][k] + ans[k][j];
                }
            }
        }
    }
    return ans[s][d];
}
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    int **adj = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        adj[i] = new int[n + 1];
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            adj[i][j] = 1000000000;
            if (i == j)
            {
                adj[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]][edges[i][1]] = edges[i][2];
    }
    return floyds(adj, n, src, dest);
}