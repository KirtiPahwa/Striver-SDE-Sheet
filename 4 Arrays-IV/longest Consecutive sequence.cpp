class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s;
        int len = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (s.find(nums[i] - 1) == s.end())
            {
                int c = 1;
                int key = nums[i] + 1;
                while (s.find(key) != s.end())
                {
                    c++;
                    key++;
                }
                len = max(len, c);
            }
        }
        return len;
    }
};