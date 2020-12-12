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
    int n, m, d;
    cin >> n >> d >> m;
    vector<int> small(n + 1, 0);
    vector<int> big(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x <= m)
        {
            small.push_back(x);
        }
        else
        {
            big.push_back(x);
        }
    }
    sort(small.rbegin(), small.rend());
    sort(big.rbegin(), big.rend());
    big.insert(big.begin(), 0);
    for (int i = 1; i < (int)big.size(); i++)
    {
        big[i] += big[i - 1];
    }
    // for (auto i : big)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // for (auto i : small)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    ll ans = 0;
    ll rem = 0;
    ll count_small = 0;
    for (int i = 0; i <= n; i++)
    {
        rem = n - i;
        ll num = (rem + d) / (d + 1);
        ll count_big = big[num];
        //cout << i << " " << count_big << " " << count_small << endl;
        ans = max(ans, count_big + count_small);
        count_small += small[i];
    }
    cout << ans << endl;
}

int main()
{
    fast;
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}