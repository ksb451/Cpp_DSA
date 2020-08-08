#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long int lld;
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        lld n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        bool flag = true;
        int r = n - 1;
        while (r > 0 && arr[r - 1] >= arr[r])
            r--;
        while (r > 0 && arr[r - 1] <= arr[r])
            r--;
        cout << r << endl;
    }
    return 0;
}