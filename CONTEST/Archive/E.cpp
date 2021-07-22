/******************************************
* AUTHOR : Keshab Agrawal *
* NICK : sn0wrus *
******************************************/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);

#define IN cin >>
#define OUT cout <<
#define endl "\n"
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

const int dir8[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
const int dir4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

/*
for(int i=0;i<n-1;i++)
{
    int a,b;
    cin>>a>>b;
    a--,b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
}
*/

ll a[1000001];
ll dp[1000001][2][2];
 
void solve()
{
    ll n;
    cin >> n;
 
    ll r1,r2,r3;
    cin >> r1 >> r2 >> r3;
 
    ll d;
    cin >> d;
 
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
 
    ll ans = LLONG_MAX;
 	memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        ll total = r1*a[i]+r3;
        ll laser = min(r2,r1*a[i]+r1);
 
        dp[i][0][0] = d+total + min(dp[i-1][0][0],dp[i-1][1][0]);
        dp[i][0][1] = d+laser + min(dp[i-1][0][0],dp[i-1][1][0]);
        dp[i][1][0] = min(dp[i][0][0]+d+r1+d,dp[i][0][1]+d+r1+d+r1);
 
        if(i==1)
        {
            dp[i][0][0] -= d;
            dp[i][0][1] -= d;
            dp[i][1][0] -= d;
        }
        if(i==n)
        {
        	ans= dp[i-1][0][1]+d+total+d+r1;
        }
    }
 
    cout << min({ans,dp[n][1][0],dp[n][0][0]}) << endl;
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