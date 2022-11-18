class Solution
{
public:
    vector<vector<int>> generate(int n)
    {
        vector<vector<int>> ans;

        vector<int> temp;
        temp.push_back(1);
        ans.push_back(temp);
        for (int i = 1; i < n; i++)
        {
            int k = ans[i - 1].size();

            vector<int> temp2;
            temp2.push_back(ans[i - 1][0]);
            for (int j = 1; j <= i - 1; j++)
            {
                temp2.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            }
            temp2.push_back(ans[i - 1][k - 1]);
            ans.push_back(temp2);
        }
        return ans;
    }
};