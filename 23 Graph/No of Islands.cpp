class Solution
{
public:
    void bfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vis[r][c] = 1;
        queue<pair<int, int>> q;
        q.push({r, c});
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            // delta row and delta column
            int dr[] = {-1, 0, +1, 0};
            int dc[] = {0, -1, 0, +1};
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + dr[i];
                int ncol = c + dc[i];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
                {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return cnt;
    }
};

// or

class Solution
{
public:
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vis[r][c] = 1;
        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, -1, 0, +1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + dr[i];
            int ncol = c + dc[i];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
            {
                dfs(nrow, ncol, vis, grid);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return cnt;
    }
};