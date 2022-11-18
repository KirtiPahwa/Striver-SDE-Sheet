class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = INT_MIN;
        int mn = INT_MAX;
        int mx = INT_MIN;
        for (auto x : prices)
        {
            mn = min(mn, x);
            ans = max(ans, x - mn);
        }
        return ans;
    }
};