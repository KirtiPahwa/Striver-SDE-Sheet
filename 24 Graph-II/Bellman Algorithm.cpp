#include <bits/stdc++.h>
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    int *dis = new int[n + 1];
    for (int i = 1; i < n + 1; i++)
    {
        dis[i] = 1000000000;
    }
    dis[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if (dis[u] != 1000000000 && dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
            }
        }
    }
    return dis[dest];
}