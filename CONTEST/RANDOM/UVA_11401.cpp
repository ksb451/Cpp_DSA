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
    while (cin>>n)
    {
        if (n<3)
        {
            return;
        }
        vector<ll>dp(n+1);
        dp[3]=0;
        dp[4]=1;
        for (ll i=5;i<=n;i++)
        {
            ll x=i-(i/2)-1;
            if (i&1)
            {
                dp[i]=dp[i-1]+(x*(x-1));
            }
            else {
                dp[i]=dp[i-1]+(x*x);
            }
        }
        cout<<dp[n]<<endl;
    }
}


void solve1() {
    ll n;
    while (cin>>n)
    {
        if (n<3)
        {
            return;
        }
        if (n&1)
        {
            ll ans=((2*n*n*n)-(9*n*n)+(10*n)-3)/24;
            cout<<ans<<endl;
        }
        else {
            ll ans=((2*n*n*n)-(9*n*n)+(10*n))/24;
            cout<<ans<<endl;
        }
    }
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