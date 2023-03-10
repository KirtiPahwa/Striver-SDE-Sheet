#define p pair<int, int>
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (auto x : nums)
        {
            mp[x]++;
        }
        priority_queue<p, vector<p>, greater<p>> minheap;
        for (auto x : mp)
        {
            minheap.push({x.second, x.first});
            if (minheap.size() > k)
            {
                minheap.pop();
            }
        }
        vector<int> ans;
        while (!minheap.empty())
        {
            ans.push_back(minheap.top().second);
            minheap.pop();
        }
        return ans;
    }
};