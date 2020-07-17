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
        lld i = n - 1;
        for (; i > 0; i--)
        {
            if (flag)
            {
                if (arr[i - 1] >= arr[i])
                {
                    continue;
                }
                else
                {
                    flag = false;
                }
            }
            if (!flag)
            {
                if (arr[i - 1] > arr[i])
                {
                    break;
                }
            }
        }
        cout << i << endl;
    }
    return 0;
}