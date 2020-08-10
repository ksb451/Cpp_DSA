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

int dp[1<<4];

void solve()
{
    memset(dp, 0, sizeof(dp));
    int n, k;
    cin>>n>>k;
    for (int i=0;i<n;i++)
    {
        int q=0;
        for (int i=0;i<k;i++)
        {
            int a;
            cin>>a;
            a<<=(k-i-1);
            q|=a;
        }
        //cout<<q<<endl;
        dp[q]=1;
    }
    if (dp[0])
    {
        cout<<"YES"<<endl;
        return;
    }
    for (int i=1;i<(1<<k);i++)
    {
        for (int j=1;j<(1<<k);j++)
        {
            if (dp[i]&&dp[j])
            {
                if (!(i&j))
                {
                    cout<<"YES"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"NO"<<endl;
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