class Solution
{
public:
    void helper(vector<vector<int>> &board, vector<vector<string>> &ans, int n, int row, vector<int> &c, vector<int> &ld, vector<int> &rd)
    {
        if (row == n)
        {
            vector<string> temp;
            string temp2 = "";
            for (auto it : board)
            {
                for (auto x : it)
                    if (x == 0)
                        temp2 += '.';
                    else
                        temp2 += 'Q';
                temp.push_back(temp2);
                temp2 = "";
            }
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if ((!c[i]) && !(ld[n - 1 + i - row]) && !rd[i + row])
            {
                c[i] = 1;
                ld[n - 1 + i - row] = 1;
                rd[i + row] = 1;
                board[row][i] = 1;
                helper(board, ans, n, row + 1, c, ld, rd);
                board[row][i] = 0;
                c[i] = 0;
                ld[n - 1 + i - row] = 0;
                rd[i + row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<int> c(n, 0);
        vector<int> ld(2 * n - 1, 0);
        vector<int> rd(2 * n - 1, 0);
        helper(board, ans, n, 0, c, ld, rd);
        return ans;
    }
};
