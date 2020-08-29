#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h>
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

ll moduloMultiplication(ll a, ll b, ll mod = mod)
{
    long long res = 0;

    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;

        b >>= 1; // b = b / 2
    }
    return res;
}

void solve()
{
    ll n, k, w;
    cin >> n >> k >> w;
    vector<ll> L(n);
    for (int i = 0; i < k; i++)
    {
        cin >> L[i];
    }
    ll Al, Bl, Cl, Dl;
    ll Ah, Bh, Ch, Dh;
    cin >> Al >> Bl >> Cl >> Dl;
    vector<ll> H(n);
    for (int i = 0; i < k; i++)
    {
        cin >> H[i];
    }
    cin >> Ah >> Bh >> Ch >> Dh;
    for (int i = k; i < n; i++)
    {
        L[i] = ((Al * L[i - 2] + Bl * L[i - 1] + Cl) % Dl) + 1;
        H[i] = ((Ah * H[i - 2] + Bh * H[i - 1] + Ch) % Dh) + 1;
    }
    // write(L);
    // write(H);
    ll prev = 0;
    ll ans = 1;
    ll curr_height = 0;
    ll curr_end = L[0] + w;
    ll curr_start = L[0];
    for (int i = 0; i < n; i++)
    {
        if (L[i] <= curr_end)
        {
            curr_end = max(curr_end, L[i] + w);
        }
        else
        {
            prev += ((curr_end - curr_start) + curr_height) * 2;
            curr_start = L[i];
            curr_end = L[i] + w;
            curr_height = H[i];
        }
        curr_height = max(curr_height, H[i]);
        //cerr << curr_height << " " << curr_start << " " << curr_end << endl;
        ll temp = ((curr_end - curr_start) + curr_height) * 2;
        //cout << (prev + temp) << " ";
        ans = moduloMultiplication((temp + prev), ans);
        ans %= mod;
    }
    cout << ans << endl;
}

int main()
{
    ll tc = 1;
    IN tc;
    for (int i = 1; i <= tc; i++)
    {
        printf("Case #%d: ", i);
        //puts("");
        solve();
    }
    return 0;
}