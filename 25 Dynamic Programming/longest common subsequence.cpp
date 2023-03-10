class Solution
{
public:
    int helper(string text1, string text2, int i, int j)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }
        if (text1[i] == text2[j])
        {
            return 1 + helper(text1, text2, i - 1, j - 1);
        }
        else
        {
            return max(helper(text1, text2, i - 1, j), helper(text1, text2, i, j - 1));
        }
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        return helper(text1, text2, text1.size() - 1, text2.size() - 1);
    }
};

// OR

class Solution
{
public:
    int helper(string text1, string text2, int i, int j, vector<vector<int>> dp)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (text1[i] == text2[j])
        {
            return dp[i][j] = 1 + helper(text1, text2, i - 1, j - 1, dp);
        }
        else
        {
            return dp[i][j] = max(helper(text1, text2, i - 1, j, dp), helper(text1, text2, i, j - 1, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));

        return helper(text1, text2, text1.size() - 1, text2.size() - 1, dp);
    }
};