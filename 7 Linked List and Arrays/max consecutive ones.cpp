class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int mx = 0;
        int count = 0;
        for (auto x : nums)
        {
            if (x == 1)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            mx = max(count, mx);
        }
        return mx;
    }
};