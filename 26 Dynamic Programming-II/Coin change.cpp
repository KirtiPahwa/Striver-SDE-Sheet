class Solution
{
public:
    int helper(vector<int> &coins, int a, int n, vector<vector<int>> &dp)
    {
        if (a == 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return INT_MAX;
        }
        if (dp[n][a] != -1)
        {
            return dp[n][a];
        }
        if (coins[n - 1] <= a)
        {
            int ans = helper(coins, a - coins[n - 1], n, dp);

            if (ans != INT_MAX)
            {
                ans = 1 + ans;
            }
            return dp[n][a] = min(ans, helper(coins, a, n - 1, dp));
        }
        return dp[n][a] = helper(coins, a, n - 1, dp);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        int ans = helper(coins, amount, coins.size(), dp);
        if (ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};

// or

class Solution
{
public:
    int helper(vector<int> &coins, int a, int n, vector<vector<int>> &dp)
    {
        if (a == 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return INT_MAX - 1;
        }
        if (dp[n][a] != -1)
        {
            return dp[n][a];
        }
        if (coins[n - 1] <= a)
        {
            int ans = helper(coins, a - coins[n - 1], n, dp);
            return dp[n][a] = min(ans + 1, helper(coins, a, n - 1, dp));
        }
        return dp[n][a] = helper(coins, a, n - 1, dp);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        int n = coins.size();
        int w = amount;
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < w + 1; j++)
            {
                if (i == 0)
                {
                    dp[i][j] = INT_MAX - 1;
                }
            }
        }
        dp[0][0] = 0;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < w + 1; j++)
            {
                if (coins[i - 1] <= j)
                {
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        if (dp[n][w] == INT_MAX - 1)
        {
            return -1;
        }
        return dp[n][w];
    }
};