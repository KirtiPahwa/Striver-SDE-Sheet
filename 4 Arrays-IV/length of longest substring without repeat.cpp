class Solution
{
public:
    int lengthOfLongestSubstring(string str)
    {
        int n = str.size();
        if (n == 0)
            return 0;
        int mx = 0;
        int l = 0, r = 0;
        unordered_map<int, int> s;
        while (r < n)
        {
            if (s.find(str[r]) != s.end())
            {
                if (s[str[r]] >= l)
                    l = s[str[r]] + 1;
            }

            s[str[r]] = r;
            r++;
            mx = max(mx, r - l);
        }
        // mx=max(mx,r-l);
        return mx;
    }
};