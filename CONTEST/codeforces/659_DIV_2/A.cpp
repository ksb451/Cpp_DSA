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
    vector<int> arr(n, 0);
    int mx = 0;
    for (int &i : arr)
    {
        cin >> i;
        mx = max(mx, i);
    }
    string ex = string(mx + 1, 'a');
    //cout << ex;
    vector<string> ans(n + 1, ex);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < arr[i - 1]; j++)
        {
            ans[i][j] = ans[i - 1][j];
        }
        if (arr[i - 1] < ans[i].length())
        {
            if (ans[i - 1][arr[i - 1]] == 'z')
            {
                ans[i][arr[i - 1]] = 'a';
            }
            else
            {
                ans[i][arr[i - 1]] = ans[i - 1][arr[i - 1]] + 1;
            }
        }
    }
    for (auto i : ans)
    {
        cout << i << endl;
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