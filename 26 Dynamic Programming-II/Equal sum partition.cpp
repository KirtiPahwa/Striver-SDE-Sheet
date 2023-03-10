class Solution
{
public:
    bool helper(int w, vector<int> &nums, int n, vector<vector<int>> &t)
    {
        if (w == 0)
        {
            return true;
        }
        if (n == 0)
        {
            return false;
        }
        if (t[n][w] != -1)
        {
            return t[n][w];
        }
        if (nums[n - 1] <= w)
        {
            if (helper(w - nums[n - 1], nums, n - 1, t) || helper(w, nums, n - 1, t))
            {
                t[n][w] = true;
            }
            else
                t[n][w] = false;
        }
        else
        {
            t[n][w] = helper(w, nums, n - 1, t);
        }
        return t[n][w];
    }
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int s = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            s += nums[i];
        }
        if (s % 2 != 0)
            return false;
        int w = s / 2;
        vector<vector<int>> t(n + 1, vector<int>(w + 1, -1));
        return helper(w, nums, n, t);
    }
};

// or

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int s = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            s += nums[i];
        }
        if (s % 2 != 0)
            return false;
        int w = s / 2;
        vector<vector<int>> t(n + 1, vector<int>(w + 1, -1));
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < w + 1; j++)
            {
                if (j == 0)
                    t[i][j] = 0;
                else if (i == 0)
                    t[i][j] = 1;
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < w + 1; j++)
            {
                if (nums[i - 1] <= j)
                {
                    t[i][j] = t[i - 1][j] || t[i - 1][j - nums[i - 1]];
                }
                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        return t[n][w];
    }
};