class Solution
{
public:
    bool emptySudoku(vector<vector<char>> &board, int &row, int &col)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    row = i;
                    col = j;
                    return true;
                }
            }
        }
        return false;
    }
    bool isrow(vector<vector<char>> &board, int row, int k)
    {
        for (int i = 0; i < board.size(); i++)
        {
            if (board[row][i] == k + '0')
                return false;
        }
        return true;
    }
    bool iscol(vector<vector<char>> &board, int col, int k)
    {
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][col] == k + '0')
                return false;
        }
        return true;
    }
    bool isSafe(vector<vector<char>> &board, int row, int col, int i)
    {
        if (isrow(board, row, i) && iscol(board, col, i) && isBlock(board, row, col, i))
        {
            return true;
        }
        return false;
    }
    bool isBlock(vector<vector<char>> &board, int row, int col, int k)
    {
        int rf = row - (row % 3);
        int cf = col - (col % 3);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i + rf][j + cf] == k + '0')
                    return false;
            }
        }
        return true;
    }
    bool helper(vector<vector<char>> &board)
    {
        int row, col;
        if (!emptySudoku(board, row, col))
        {
            return true;
        }
        for (int i = 1; i <= 9; i++)
        {
            if (isSafe(board, row, col, i))
            {
                // cout<<(i+'0')<<endl;
                char a = i + '0';
                board[row][col] = a;
                if (helper(board))
                {
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        helper(board);
    }
};