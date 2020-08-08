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
    string a, b;
    cin >> a >> b;
    int ans;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            cout << "-1" << endl;
            return;
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < b[i])
        {
            count++;
            while (i < n - 1 && (a[i + 1] == a[i]) && b[i + 1] == b[i])
            {
                i++;
            }
        }
    }
    cout << count << endl;
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