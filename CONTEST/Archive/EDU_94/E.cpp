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

vector<int> arr;

int rec(int start, int end)
{
    if (start > end)
        return 0;
    int outside = max(arr[start - 1], arr[end + 1]);
    int min_index = int(min_element(arr.begin() + start, arr.begin() + end + 1) - arr.begin());
    int minimum = arr[min_index];
    return min(end - start + 1, rec(start, min_index - 1) + rec(min_index + 1, end) + minimum - outside);
}

void solve()
{
    int n;
    cin >> n;
    arr.assign(n + 2, 0);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    cout << rec(1, n) << endl;
}

int main()
{
    fast;
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}