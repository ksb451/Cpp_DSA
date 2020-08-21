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
    ;
    cin >> s;
    ll L = 0, R = 0, U = 0, D = 0;
    ll l, r, u, d;
    for (char i : s)
    {
        if (i == 'R')
            R++;
        if (i == 'D')
            D++;
        if (i == 'U')
            U++;
        if (i == 'L')
            l++;
    }
    ll x, y;
    cin >> x >> y;
    ll q;
    cin >> q;
    while (q--)
    {
        l = 0;
        r = 0;
        d = 0;
        u = 0;
        ll x1, y1;
        cin >> x1 >> y1;
        if (x1 >= x)
        {
            r = (x1 - x);
        }
        else
        {
            l = (x - x1);
        }
        if (y1 > y)
        {
            u = (y1 - y);
        }
        else
        {
            d = (y - y1);
        }
        ll ans;
        if ((d <= D) && (u <= U) && (l <= L) && (r <= R))
        {
            ans = d + l + r + u;
        }
        else
        {
            ans = -1;
        }
        if (ans >= 0)
        {
            cout << "YES " << ans << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

int main()
{
    fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}