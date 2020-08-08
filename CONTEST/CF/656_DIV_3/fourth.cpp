#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long int lli;

int calculate(string s, char c)
{
    if (s.length() == 1)
    {
        return s[0] != c;
    }
    int mid = s.length() / 2;
    int cntl = calculate(string(s.begin(), s.begin() + mid), c + 1);
    cntl += s.size() / 2 - count(s.begin() + mid, s.end(), c);
    int cntr = calculate(string(s.begin() + mid, s.end()), c + 1);
    cntr += s.size() / 2 - count(s.begin(), s.begin() + mid, c);
    return min(cntl, cntr);
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        cout << calculate(s, 'a') << endl;
    }
    return 0;
}