class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &arr, int target)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>> s;
        int n = arr.size();
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                long long key = ((long long)target - ((long long)arr[i] + (long long)arr[j]));
                int l = j + 1, h = arr.size() - 1;
                while (l < h)
                {
                    long long sum = arr[l] + arr[h];
                    if (sum == key)
                    {
                        vector<int> temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[l]);
                        temp.push_back(arr[h]);
                        s.push_back(temp);
                        do
                        {
                            l++;
                        } while (l < h && arr[l] == arr[l + 1]);
                        do
                        {
                            h--;
                        } while (l < h && arr[h] == arr[h - 1]);
                    }
                    else if (sum < key)
                    {
                        l++;
                    }
                    else
                    {
                        h--;
                    }
                }

                while (j < n && arr[j] == arr[j + 1])
                {
                    j++;
                }
            }
            while (i < n && arr[i] == arr[i + 1])
            {
                i++;
            }
        }

        vector<vector<int>> res(s.begin(), s.end());
        return res;
    }
};