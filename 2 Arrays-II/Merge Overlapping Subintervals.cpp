class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++)
        {
            int s = intervals[i][0], e = intervals[i][1];
            int j;
            for (j = i + 1; j < intervals.size(); j++)
            {
                if (intervals[j][0] <= e)
                {
                    e = max(intervals[j][1], e);
                }
                else
                {
                    break;
                }
            }

            ans.push_back({s, e});
            i = j - 1;
        }

        return ans;
    }
};