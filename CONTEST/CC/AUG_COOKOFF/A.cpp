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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > k)
        {
            flag = false;
        }
    }
    int ans = -1;
    if (flag)
    {
        ans = 0;
        int curr_sum = 0;
        for (int i = 0; i < n; i++)
        {
            curr_sum += arr[i];
            if (curr_sum > k)
            {
                ans++;
                curr_sum = arr[i];
            }
        }
        ans++;
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