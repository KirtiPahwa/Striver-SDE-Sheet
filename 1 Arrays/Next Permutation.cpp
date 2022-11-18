class Solution
{
public:
    void nextPermutation(vector<int> &permutation)
    {
        int n = permutation.size();
        if (n == 0 || n == 1)
            return;
        int i;
        for (i = n - 1; i >= 1; i--)
        {
            if (permutation[i] > permutation[i - 1])
            {
                break;
            }
        }
        if (i == 0)
        {
            reverse(permutation.begin(), permutation.end());
        }
        else
        {
            int ind = i - 1;

            for (i = n - 1; i > ind + 1; i--)
            {
                if (permutation[i] > permutation[ind])
                {
                    break;
                }
            }
            swap(permutation[i], permutation[ind]);
            reverse(permutation.begin() + ind + 1, permutation.end());
        }
    }
};