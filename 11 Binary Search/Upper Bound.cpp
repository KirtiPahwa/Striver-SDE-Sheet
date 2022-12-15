#include <iostream>
using namespace std;

int main()
{
    int n = 10;
    // int arr[n] = {1, 2, 2, 3, 3, 3, 4, 5, 6, 7};
    int arr[n] = {1, 2, 4, 5, 6, 6, 6, 6, 6, 7};
    // int arr[n] = {5, 5, 6, 6, 6, 6, 6, 7, 7, 8};

    int l = 0;
    int r = n - 1;
    int k = 9;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] <= k)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    //  low returns uppper bound  // l denotes lower bound
    if (l >= n)
    { // {1, 2, 4, 5, 6, 6, 6, 6, 6, 7} key=9 so ans=-1; bcz no uppper bound of 9 so l giving ind=10 which donot exist in array. so return -1
        cout << -1 << endl;
    }
    cout << l << " " << r << endl;
    return 0;
}