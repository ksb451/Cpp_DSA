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

const ll limit = 500001L;

ll fact[limit];

ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res % p;
}

ll modinverse(ll n, ll p)
{
    return power(n, p - 2, p);
}

ll ncrModPFermat(ll n, ll r, ll m)
{
    if (r == 0)
    {
        return 1;
    }
    return (((fact[n] * modinverse(fact[n - r], mod)) % m) * modinverse(fact[r], mod)) % m;
}

void factcalculate()
{
    fact[0] = 1;
    fact[1] = 1;
    for (ll i = 2; i < limit; i++)
    {
        fact[i] = (1LL * i * fact[i - 1]) % mod;
    }
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    map<ll, ll> fre;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        fre[arr[i]]++;
        //arr[i]=i+1;
    }
    ll prefix[n + 3];
    ll suffix[n + 1];

    for (int i = 0; i < n; i++)
    {
        prefix[i] = 1;
        suffix[i] = 1;
    }
    for (auto each : fre)
    {
        ll total = 1;
        for (int k = 1; k <= each.second; k++)
        {
            total += ncrModPFermat(each.second, k, mod);
            total %= mod;
            prefix[k] *= total;
            prefix[k] %= mod;
        }
        suffix[each.second + 1] *= total;
        suffix[each.second + 1] %= mod;
    }
    ll mul = 1;
    for (int i = 1; i <= n; i++)
    {
        mul *= suffix[i];
        mul %= mod;
        prefix[i] *= mul;
        prefix[i] %= mod;
    }
    for (int i = 1; i <= n; i++)
    {
        ll ans, ans1, total;
        ans = 0;
        total = 1;
        for (int j = 1; j <= fre[i]; j++)
        {
            ll var;
            ans1 = ncrModPFermat(fre[i], j, mod);
            var = ans1;
            total += var;
            total %= mod;

            prefix[j] = (prefix[j] * modinverse(total, mod)) % mod;
            ans1 *= prefix[j];
            ans1 %= mod;

            prefix[j] = (prefix[j] * (total - var + mod) % mod) % mod;
            ans += ans1;
            ans %= mod;
        }
        cout << ans << " ";
    }
    cout << endl;
}

int main()
{
    fast;
    factcalculate();
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}