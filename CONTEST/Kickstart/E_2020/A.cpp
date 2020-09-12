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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = INT_MIN;
    int curr = 0;
    int currdiff = 0;
    if (n == 2)
    {
        cout << 2 << endl;
        return;
    }
    curr = 2;
    currdiff = arr[1] - arr[0];
    for (int i = 2; i < n; i++)
    {
        if ((arr[i] - arr[i - 1]) == currdiff)
        {
            curr++;
        }
        else
        {
            ans = max(ans, curr);
            currdiff = arr[i] - arr[i - 1];
            curr = 2;
        }
    }
    ans = max(ans, curr);
    cout << ans << endl;
}

int main()
{
    ll tc = 1;
    IN tc;
    for (int i = 1; i <= tc; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}