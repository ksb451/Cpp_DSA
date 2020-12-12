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

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    bool flag = true;
    int mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i >= 1)
        {
            if (a[i] < a[i - 1])
                flag = false;
        }
        b[i] = a[i];
        mn = min(mn, a[i]);
    }
    if (flag || mn == 1)
    {
        cout << "YES\n";
        return;
    }

    sort(all(b));
    vector<int> c;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            c.push_back(a[i]);
        }
    }
    int gcd;
    gcd = mn;
    for (int i = 0; i < c.size(); i++)
    {
        gcd = GCD(gcd, c[i]);
    }
    if (gcd == mn)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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