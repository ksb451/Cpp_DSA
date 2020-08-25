#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);

#define IN cin >>
#define OUT cout <<
#define nl "\n"
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define write(a)          \
    for (auto x : a)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << nl;
#define read(a)       \
    for (auto &x : a) \
    {                 \
        cin >> x;     \
    }
using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 988244353LL;

void solve()
{
    string s;
    cin >> s;
    int x;
    cin >> x;
    int n = s.length();
    vector<int> confirm(n, 0);
    string ans = string(n, '0');
    //cout << n << endl;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            if (i >= x)
            {
                if (confirm[i - x] == 1 && ans[i - x] == '1')
                {
                    flag = false;
                    break;
                }
                else
                {
                    ans[i - x] = '0';
                    confirm[i - x] = 1;
                }
            }
            if (i + x < n)
            {
                if (confirm[i + x] == 1 && ans[i + x] == '1')
                {
                    flag = false;
                    break;
                }
                else
                {
                    ans[i + x] = '0';
                    confirm[i + x] = 1;
                }
            }
        }
        else
        {
            if (i >= x && (i + x) < n)
            {
                if (confirm[i - x] == 1 && ans[i - x] == '0')
                {
                    if ()
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        ans[i + x] = '1';
                        confirm[i + x] = 1;
                    }
                }
                else
                {
                    confirm[i - x] = 1;
                    ans[i - x] = '1';
                }
            }
            else if (i >= x)
            {
                if (confirm[i - x] == 1 && ans[i - x] == '0')
                {
                    flag = false;
                    break;
                }
                else
                {
                    confirm[i - x] = 1;
                    ans[i - x] = '1';
                }
            }
            else if (i + x < n)
            {
                if (confirm[i + x] == 1 && ans[i + x] == '0')
                {
                    flag = false;
                    break;
                }
                else
                {
                    confirm[i + x] = 1;
                    ans[i + x] = '1';
                }
            }
        }
    }
    if (flag)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
