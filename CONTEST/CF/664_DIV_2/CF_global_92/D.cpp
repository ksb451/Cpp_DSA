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
    string s;
    cin >> s;
    bool flag = true;
    int start;
    char cu = s[0];
    for (int i = 1; i < n; i++)
    {
        if (s[i] == cu)
            continue;
        else
        {
            start = i;
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << (n + 2) / 3 << endl;
        return;
    }
    ll ans = 0;
    ll curr = 1;
    cu = s[start];
    for (int i = (start + 1) % n; i != start; i = ((i + 1) % n))
    {
        if (s[i] == cu)
        {
            curr++;
        }
        else
        {
            if (curr >= 3)
                ans += (curr) / 3;
            cu = s[i];
            curr = 1;
        }
    }
    if (curr >= 3)
        ans += (curr / 3);
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