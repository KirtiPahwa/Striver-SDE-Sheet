#include <bits/stdc++.h>
bool valid(int c, vector<vector<int>> &mat, int node, vector<int> &colors)
{
    for (int i = 0; i < mat.size(); i++)
    {
        if (mat[node][i] == 1 && colors[i] == c)
        {
            return false;
        }
    }
    return true;
}
bool helper(vector<vector<int>> &mat, int m, vector<int> &colors, int node, int t)
{
    if (node == mat.size())
    {
        return true;
    }

    for (int i = 1; i <= m; i++)
    {
        if (valid(i, mat, node, colors))
        {
            colors[node] = i;
            if (helper(mat, m, colors, node + 1, --t))
                return true;
            colors[node] = 0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m)
{
    vector<int> colors(mat.size(), 0);

    if (helper(mat, m, colors, 0, m))
    {
        return "YES";
    }
    return "NO";
}