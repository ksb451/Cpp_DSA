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

ll max(ll x, ll y, ll z)
{
    return max(x, max(y, z));
}
vector<int> red;

vector<int> green;

vector<int> blue;
ll dp[210][210][210];

ll rec(int r, int g, int b)
{
    if (r == 0 && g == 0 || r == 0 && b == 0 || g == 0 && b == 0)
    {
        return dp[r][g][b] = 0;
    }
    else if (dp[r][g][b] != -1)
    {
        return dp[r][g][b];
    }
    else
    {
        ll temp = 0;
        if (r != 0 && g != 0)
        {
            temp = max(temp, (red[r - 1] * green[g - 1]) + rec(r - 1, g - 1, b));
        }

        if (g != 0 && b != 0)
        {
            temp = max(temp, (blue[b - 1] * green[g - 1]) + rec(r, g - 1, b - 1));
        }

        if (r != 0 && b != 0)
        {
            temp = max(temp, (red[r - 1] * blue[b - 1]) + rec(r - 1, g, b - 1));
        }
        return dp[r][g][b] = temp;
    }
}

void solve()
{
    int r, g, b;
    cin >> r >> g >> b;
    red.clear();
    blue.clear();
    green.clear();
    for (ll i = 0; i < r; i++)
    {
        ll x;
        cin >> x;
        red.push_back(x);
    }

    for (ll i = 0; i < g; i++)
    {
        ll x;
        cin >> x;
        green.push_back(x);
    }

    for (ll i = 0; i < b; i++)
    {
        ll x;
        cin >> x;
        blue.push_back(x);
    }
    sort(red.begin(), red.end());
    sort(green.begin(), green.end());
    sort(blue.begin(), blue.end());
    memset(dp, -1, sizeof(dp));
    cout << rec(r, g, b) << endl;
}

int main()
{
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}