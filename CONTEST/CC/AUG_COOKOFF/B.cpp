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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int x = n / k;
    int c1 = 0, c0 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            c0++;
        }
        else
        {
            c1++;
        }
    }
    string ans = "";
    if (((c1 % x) != 0) || ((c0 % x) != 0))
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    else
    {
        c0 /= x;
        c1 /= x;
        string temp = string(c0, '0');
        temp += string(c1, '1');
        string rev = temp;
        reverse(all(rev));
        for (int i = 0; i < x; i++)
        {
            if (i & 1)
            {
                ans += rev;
            }
            else
            {
                ans += temp;
            }
        }
    }
    cout << ans << endl;
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