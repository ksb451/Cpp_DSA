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

void solve()
{
	ll n;
	cin>>n;
    int arr[n+1]={0};
    arr[0]=arr[1]=1;
    for(int i=2;i<=n;i++)
    {
    	for(int j=1;j<=6;j++)
    	{
    		if(i-j>=0)
    		{
    			arr[i]+=arr[i-j];
    			arr[i]%=mod;
    		}
    	}
    }
    cout<<arr[n]<<endl;
}

int main()
{
    ll tc = 1;
    while (tc--)
    {
        solve();
    }
    return 0;
}