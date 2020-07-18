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
        vector<lld> arr(2 * n);
        for (auto &i : arr)
        {
            cin >> i;
        }
        unordered_map<int, int> mp;
        for (auto i : arr)
        {
            if (mp.find(i) == mp.end())
            {
                cout << i << " ";
                mp[i]++;
            }
        }
        cout << endl;
    }
    return 0;
}