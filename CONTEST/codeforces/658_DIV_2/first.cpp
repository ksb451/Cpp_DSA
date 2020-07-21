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
    ll n, m;
    cin >> n >> m;
    vector<ll> arr1(n);
    vector<ll> arr2(m);
    unordered_map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr1[i];
        mp[arr1[i]] = i;
    }
    bool flag = false;
    ll ans;
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
        if (mp.find(arr2[i]) != mp.end())
        {
            flag = true;
            ans = arr2[i];
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
        cout << 1 << " " << ans << endl;
        return;
    }
    cout << "NO" << endl;
    return;
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