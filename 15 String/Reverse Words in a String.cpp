#include <bits/stdc++.h>
class Solution
{
public:
       string reverseWords(string s)
    {
        int i = 0, j = s.length() - 1;
        while (s[i] == ' ')
        {
            i++;
        }
        while (s[j] == ' ')
        {
            j--;
        }
        // cout<<i<<" "<<j<<endl;
        string ans = "";
        string temp = "";
        while (i <= j)
        {
            if (s[i] == ' ')
            {
                if (ans == "")
                {
                    ans = temp;
                }
                else if (temp != "")
                    ans = temp + " " + ans;
                temp = "";
            }
            else
                temp += s[i];
            i++;
        }
        if (ans != "")
            ans = temp + " " + ans;
        else
            ans = temp;
        return ans;
    }
};