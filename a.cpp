#include <bits/stdc++.h>
using namespace std;

int distinctPrimeFactors(vector<int> &nums)
{
    long long num = 1;
    for (auto x : nums)
    {
        num *= x;
    }
    int ans = 0;
    int temp = num;
    long long n = num;

    if (n <= 2)
        return 1;

    int size = sqrt(n);
    bool *prime = new bool(size);
    for (int i = 0; i <= size; i++)
    {
        prime[i] = 1;
        // cout << i << " " << prime[i] << endl;
    }
    for (int i = 2; i * i <= size; i++)
    {
        if (prime[i])
        {

            for (int j = i; j * i <= size; j++)
            {
                prime[j * i] = false;
            }
        }
    }

    // for (int i = 0; i <= size; i++)
    // {
    //     cout << i << " " << prime[i] << endl;
    // }

    for (int i = 2; i <= size; i++)
    {
        if (prime[i] && (num % i == 0))
            ans++;
    }
    // cout << ans << endl;
    // delete prime;

    return ans;
}
int main()
{
    vector<int> a{2, 4, 3, 7, 10, 6};
    cout << distinctPrimeFactors(a) << endl;
    return 0;
}