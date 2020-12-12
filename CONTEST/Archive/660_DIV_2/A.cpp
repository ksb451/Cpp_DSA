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
    int n;
    cin >> n;
    if (n < 31)
    {
        cout << "NO" << endl;
        return;
    }
    else if (n == 36)
    {
        cout << "YES" << endl;
        cout << 6 << " " << 10 << " " << 15 << " " << 5 << endl;
        return;
    }
    else if (n == 40)
    {
        cout << "YES" << endl;
        cout << 6 << " " << 10 << " " << 15 << " " << 9 << endl;
        return;
    }
    else if (n == 44)
    {
        cout << "YES" << endl;
        cout << 6 << " " << 10 << " " << 15 << " " << 13 << endl;
        return;
    }
    else
    {
        cout << "YES" << endl;
        cout << 6 << " " << 10 << " " << 14 << " " << (n - 30) << endl;
        return;
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