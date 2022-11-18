class Solution
{
public:
    int maxSubArray(vector<int> &arr)
    {
        int ans = INT_MIN;
        int n = arr.size();
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            curr += arr[i];
            ans = max(ans, curr);
            if (curr < 0)
            {
                curr = 0;
            }
        }
        return ans;
    }
};