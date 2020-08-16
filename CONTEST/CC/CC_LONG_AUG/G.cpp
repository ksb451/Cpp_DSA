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

ll n, c, k;
vector<ll> lines;
vector<ll> cost;
set<pair<ll, ll>, greater<>> st;
ll count_triangle()
{
    ll ans = 0;
    for (ll i = 1; i <= c; i++)
    {
        ll temp = lines[i];
        temp = (temp * (temp - 1) * (temp - 2)) / 6;
        ans += temp;
    }
    return ans;
}

void solve()
{
    cin >> n >> c >> k;
    lines = vector<ll>(c + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        lines[c]++;
    }
    cost = vector<ll>(c + 1, 0);
    for (ll i = 1; i <= c; i++)
    {
        st.insert({lines[i], i});
        cin >> cost[i];
    }
    ll total;
    ll allowed = k / cost[1];
    if (n - allowed < 3)
    {
        total = 0;
    }
    else
    {
        for (ll i = 0; i < allowed; i++)
        {
            ll a = (*st.begin()).second;
            st.erase(st.begin());
            lines[a]--;
            st.insert({lines[a], a});
        }
        total = count_triangle();
    }
    cout << total << endl;
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