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
const ll maxn = 4e5;

unsigned long long fac[maxn]; 

void cal()
{
	fac[0] = 1; 
    for (int i = 1; i <= maxn; i++) 
        fac[i] = (fac[i - 1] * i) % M; 
}

unsigned long long power(unsigned long long x, int y, int p) 
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
  
unsigned long long modInverse(unsigned long long n, int p) 
{ 
    return power(n, p - 2, p); 
} 

unsigned long long nCrModPFermat(unsigned long long n, int r, int p) 
{ 
    if (r == 0) 
        return 1; 
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
}

bool compare(pll a, pll b){
	if(a.first == b.first)
	{
		return a.second > b.second;
	}
	else{
		return a.first < b.first;
	}
}

void solve()
{
	ll n,k;
    cin>>n>>k;
    vector<pll>arr;
    for(int i=0;i<n;i++)
    {
    	ll a,b;
    	cin>>a>>b;
    	arr.push_back({a,1});
    	arr.push_back({b,0});
    }
    sort(all(arr),compare);
    ll ans = 0;
    ll curr = 0;
    for(auto x : arr)
    {
    	//cout<<x.first<<" "<<x.second<<endl;
    	if(x.second==1)
    	{
    		curr++;
    		if(curr==k)
    		{
    			ans+=1;
    			ans%=M;
    		}
    		else if(curr>k)
    		{
    			ans+=nCrModPFermat(curr-1, k-1,M);
    			ans%=M;
    		}
    	}
    	else{
    		curr--;
    	}
    }
    cout<<ans<<endl;
}

int main()
{
	cal();
    fast;
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}