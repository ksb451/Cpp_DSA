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
    ll x0, x1, x2;
    ll y0, y1, y2;
    cin >> x0 >> x1 >> x2 >> y0 >> y1 >> y2;
    ll a = 0, b = 0, c = 0;
    a = min(x2, y1);
    x2 -= a;
    y1 -= a;
    b = min(x0, y2);
    x0 -= b;
    y2 -= b;
    if (y2 != 0)
    {
        b = min(y2, x2);
        y2 -= b;
        x2 -= b;
        if (y2 != 0)
        {
            c = y2;
        }
    }
    cout << (a * 2) - (c * 2) << endl;
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