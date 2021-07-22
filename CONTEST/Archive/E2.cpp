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


void solve()
{
	ll n,r1,r2,r3,d;
    cin>>n>>r1>>r2>>r3>>d;
    vector<ll>arr(n);
    read(arr);
    ll dp[n+1][2][2];
    dp[0][0][0]=dp[0][0][1]=dp[0][1][0]=0;
    for(int i=1;i<n;i++)
    {
    	ll total=arr[i-1]*r1+r3;
    	ll laser=min(r2,(arr[i-1]+1)*r1);

    	dp[i][0][0]=d+total+min();
    	dp[i][0][1]=d+laser+;
    	
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