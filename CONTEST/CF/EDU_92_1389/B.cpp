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
int a[100001];
int s[100001];
void solve()
{
    int t, n, k, z;
    cin >> n >> k >> z;
    for (int i = 1; i <= n;i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    int ans = s[k+1];
    for (int i = 1; i <= k; i++) {
        int x = min(z, (k-i+1)/2);
        ans = max(ans, (a[i] + a[i+1])*x + s[k+ 1 - 2*x]);
    }
    cout << ans << endl;
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