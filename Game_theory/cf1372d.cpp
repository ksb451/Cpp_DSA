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
    cin>>n;
    vector<int>arr(n);
    for (int i=0;i<n;i++)cin>>arr[i];
    vector<int>ans;
    for (int i=0;i<n;i+=2)
    {
        ans.push_back(arr[i]);
    }
    for (int i=1;i<n;i+=2)
    {
        ans.push_back(arr[i]);
    }
    for (int i=0;i<n;i++)
    {
        ans.push_back(ans[i]);
    }
    int l=(n+1)/2;
    ll curr=0;
    ll max_sum=LLONG_MIN;
    for (int i=0;i<l;i++)
    {
        curr+=ans[i];
    }
    max_sum=max(max_sum, curr);
    for (int j=l;j<ans.size();j++)
    {
        curr+=ans[j];
        curr-=ans[j-l];
        max_sum=max(max_sum, curr);
    }
    cout<<max_sum<<endl;
}

int main()
{
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}