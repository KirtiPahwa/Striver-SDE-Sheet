#include <bits/stdc++.h>
void helper(vector<vector<int>> &ans, vector<vector<int>> &maze, int i, int j, vector<vector<int>> &vis, vector<vector<int>> &ds, int n)
{

    //    boundary cond

    if (i < 0 || j < 0 || i >= n || j >= n)
    {
        return;
    }
    //     end state
    if (i == n - 1 && j == n - 1)
    {
        vector<int> temp;
        ds[i][j] = 1;

        for (int k = 0; k < n; k++)
        {
            for (int p = 0; p < n; p++)
            {
                temp.push_back(ds[k][p]);
            }
        }
        ans.push_back(temp);
        return;
    }
    //     already visited
    if (vis[i][j] == 1)
    {
        return;
    }
    //     blocked
    if (maze[i][j] == 0)
    {
        return;
    }

    //     visited
    vis[i][j] = 1;

    //     up
    ds[i][j] = 1;

    helper(ans, maze, i - 1, j, vis, ds, n);
    //         down

    helper(ans, maze, i + 1, j, vis, ds, n);

    //         right

    helper(ans, maze, i, j + 1, vis, ds, n);

    //         left

    helper(ans, maze, i, j - 1, vis, ds, n);
    ds[i][j] = 0;
    vis[i][j] = 0;
}
vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n)
{
    vector<vector<int>> ans;
    vector<vector<int>> ds(n, vector<int>(n, 0));
    vector<vector<int>> vis(n, vector<int>(n));
    helper(ans, maze, 0, 0, vis, ds, n);
    return ans;
}