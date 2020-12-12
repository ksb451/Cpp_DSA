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

bool subsetsum(vll &ss, ll x)
{
    ll n = ss.size();
    vector<vi> dp(n + 1, vi(x + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (ss[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - ss[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][x];
}

void solve()
{
    ll n;
    IN n;
    vll arr(2 * n);
    vll max_ind;
    ll mx = INT_MIN;
    for (int i = 0; i < 2 * n; i++)
    {
        IN arr[i];
        if (arr[i] > mx)
        {
            mx = arr[i];
            max_ind.push_back(i);
        }
    }
    ll lst = 2 * n - 1;
    vll ss;
    for (int i = max_ind.size() - 1; i >= 0; i--)
    {
        ss.push_back(lst - max_ind[i] + 1);
        lst = max_ind[i] - 1;
    }
    if (subsetsum(ss, n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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