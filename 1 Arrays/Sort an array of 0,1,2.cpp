class Solution
{
public:
    void sortColors(vector<int> &arr)
    {
        int n = arr.size();
        int l = 0, i = 0, h = n - 1;
        while (i <= h)
        {

            if (arr[i] == 0)
            {
                swap(arr[i], arr[l]);
                i++;
                l++;
            }
            else if (arr[i] == 1)
            {
                i++;
            }
            else
            {
                swap(arr[i], arr[h]);
                h--;
            }
        }
    }
};