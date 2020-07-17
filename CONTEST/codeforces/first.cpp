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
        bool flag = false;
        lld a, b, c;
        lld x, y, z;
        cin >> x >> y >> z;
        if (x == y && y == z)
        {
            flag = true;
            a = b = c = x;
        }
        else if (x == y)
        {
            if (x > z)
            {
                flag = true;
                a = x;
                b = z;
                c = z;
            }
        }
        else if (y == z)
        {
            if (y > x)
            {
                flag = true;
                c = y;
                a = x;
                b = x;
            }
        }
        else if (x == z)
        {
            if (x > y)
            {
                flag = true;
                b = x;
                c = y;
                a = y;
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
            cout << a << " " << b << " " << c << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}