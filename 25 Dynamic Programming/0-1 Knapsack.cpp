#include <bits/stdc++.h>
int t[1002][1002];
int helper(vector<int> &values, vector<int> &weights, int n, int w)
{
    if (w == 0 || n == 0)
        return 0;
    if (t[n][w] != -1)
    {
        return t[n][w];
    }
    if (weights[n - 1] <= w)
    {
        t[n][w] = max(helper(values, weights, n - 1, w), values[n - 1] + helper(values, weights, n - 1, w - weights[n - 1]));
    }
    else
    {
        t[n][w] = helper(values, weights, n - 1, w);
    }
    return t[n][w];
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    memset(t, -1, sizeof(t));
    return helper(values, weights, n, w);
}

// or topdown

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    int t[n + 1][w + 1];
    memset(t, -1, sizeof(t));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= w)
            {
                t[i][j] = max(values[i - 1] + t[]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
}