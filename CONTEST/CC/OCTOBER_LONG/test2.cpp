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
const int MX = 1000; 
  
// 2D array memo for stopping  
// solving same problem again 
ll memo[MX][MX]; 
ll numberOfPermWithKInversion(ll N, ll K) 
{ 
      
    // base cases 
    if (N == 0) 
        return 0; 
    if (K == 0) 
        return 1; 
  
    // if already solved then  
    // return result directly 
    if (memo[N][K] != 0) 
        return memo[N][K]; 
  
    // calling recursively all subproblem  
    // of permutation size N - 1 
    ll sum = 0; 
    for (ll i = 0; i <= K; i++) 
    { 
  
        // Call recursively only 
        // if total inversion 
        // to be made are less  
        // than size 
        if (i <= N - 1) 
            sum += numberOfPermWithKInversion(N - 1,  
                                              K - i); 
    } 
  
    // store result into memo 
    memo[N][K] = sum; 
  
    return sum; 
}

void solve()
{
	ll n;
    cin>>n;
    cout<<"0\n1 0\n1 1 0\n";
    for(ll i=3;i<n;i++)
    {
    	for(ll j = 0;j <=i;j++)
    	{
    		cout<<numberOfPermWithKInversion(i,j)%2<<" ";
    	}
    	cout<<endl;
    }
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