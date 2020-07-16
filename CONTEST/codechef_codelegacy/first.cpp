#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long int lli;
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool flag = true;
        while (n--)
        {
            int x;
            cin >> x;
            if (x % 2 == 0)
            {
                flag = false;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}