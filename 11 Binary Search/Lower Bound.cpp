#include <iostream>
using namespace std;

int main()
{
    int n = 10;
    // int arr[n] = {1, 2, 2, 3, 3, 3, 4, 5, 6};
    int arr[n] = {1, 2, 4, 5, 6, 6, 6, 6, 6, 7};

    int l = 0;
    int r = n - 1;
    int k = 3;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] < k)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    //  low returns lower bound // l denotes lower bound
    if (l >= n)
    { // {1, 2, 4, 5, 6, 6, 6, 6, 6, 7} key=9 so ans=-1; bcz no uppper bound of 9 so l giving ind=10 which donot exist in array. so return -1
        cout << -1 << endl;
    }
    cout << l << " " << r << endl;
    return 0;
}