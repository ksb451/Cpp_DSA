#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h>
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
    scanf("%d", &n);
    pair<int, int> arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
    map<int, int> dp;
    sort(arr, arr + n);
    int ans = 0;
    for (auto i : arr)
    {
        int pos = i.first;
        int h = i.second;
        dp[pos + h] = max(dp[pos + h], h + dp[pos]);
        dp[pos] = max(dp[pos], h + dp[pos - h]);
        ans = max(ans, max(dp[pos], dp[pos + h]));
    }
    printf("%d", ans);
    puts("");
}

int main()
{
    ll tc = 1;
    IN tc;
    for (int i = 1; i <= tc; i++)
    {
        printf("Case #%d: ", i);
        //puts("");
        solve();
    }
    return 0;
}