#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long int lld;
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    lld t = 1;
    cin >> t;
    while (t--)
    {
        lld n;
        cin >> n;
        lld arr[n];
        for (lld i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        //sort(arr.begin(), arr.end());
        lld q;
        cin >> q;
        while (q--)
        {
            lld x, y;
            cin >> x >> y;
            lld sum = x + y;
            lld index = lower_bound(arr, arr + n, sum) - arr;
            if (arr[index] == sum)
            {
                cout << "-1" << endl;
            }
            else
            {
                cout << index << endl;
            }
        }
    }
    return 0;
}