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
    ll n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 1;
    if (n == 1)
    {
        cout << "First" << endl;
        return;
    }
    if (arr[n - 2] == 1)
    {
        ans = 0;
    }
    else
    {
        ans = 1;
    }
    for (ll i = n - 3; i >= 0; i--)
    {
        if (arr[i] == 1)
        {
            ans ^= 1;
        }
        else
        {
            ans = 1;
        }
        //cout << ans << " ";
    }
    if (ans)
    {
        cout << "First" << endl;
    }
    else
    {
        cout << "Second" << endl;
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