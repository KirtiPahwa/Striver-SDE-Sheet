#include <bits/stdc++.h>
#include <bits/stdc++.h>
int subarraysXor(vector<int> &arr, int k)
{
    int xr = 0;
    int cnt = 0;
    int n = arr.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        xr ^= arr[i];
        if (xr == k)
        {
            cnt++;
        }
        int y = xr ^ k;
        if (mp.find(y) != mp.end())
        {
            cnt = cnt + (mp[y]);
        }

        mp[xr]++;
    }
    return cnt;
}