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

void print(vector<ll> &a)
{
    for (ll i : a)
    {
        cout << i << " ";
    }
    cout << endl;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    ll mx = INT_MIN;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    vector<ll> odd(n);
    vector<ll> even(n);
    ll mx2 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        odd[i] = mx - arr[i];
        mx2 = max(mx2, odd[i]);
    }
    for (int i = 0; i < n; i++)
    {
        even[i] = mx2 - odd[i];
    }
    if (k == 0)
    {
        print(arr);
    }
    if (k % 2 == 1)
    {
        print(odd);
    }
    if (k % 2 == 0)
    {
        print(even);
    }
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