//**sn0wrus**//
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
using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 998244353LL;

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

ll pow(ll x, ll y, ll mod)
{
    ll res=1LL;
    x%=mod;
    if(y==0)
    {
        return 1LL;
    }
    while(y>0)
    {
        if(y&1)
        {
            res*=x;
            res%=mod;
        }
        y=y>>1;
        x=(x*x)%mod;
        x%=mod;
    }
    return res;
}

unsigned long long power(unsigned long long x, ll y, ll p) 
{ 
    unsigned long long res = 1;
    x = x % p;
    while (y > 0) { 
        if (y & 1) 
            res = (res * x) % p; 
        y = y >> 1;
        x = (x * x) % p; 
    } 
    return res; 
} 
  
unsigned long long modInverse(unsigned long long n, ll p) 
{ 
    return power(n, p - 2, p); 
} 

unsigned long long nCrModPFermat(unsigned long long n, ll r, ll p) 
{ 
    if (r == 0) 
        return 1; 
    unsigned long long fac[n + 1]; 
    fac[0] = 1; 
    for (int i = 1; i <= n; i++) 
        fac[i] = (fac[i - 1] * i) % p; 
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
} 

void solve()
{
	ll n;
    cin>>n;
    unordered_map<ll,ll>um;
    ll mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        um[x]++;
        mx=max(mx,x);
    }
    if(um[mx]&1)
    {
        cout<<pow(2,n,mod)<<endl;
    }
    else{
        ll ans;
        ans=pow(2,n,mod);
        ans-=(((nCrModPFermat(um[mx],um[mx]/2,mod))%mod)*(pow(2,n-um[mx],mod)%mod))%mod;
        ans=(ans+mod)%mod;
        cout<<ans<<endl;
    }
    return;
}

int main()
{
    fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}