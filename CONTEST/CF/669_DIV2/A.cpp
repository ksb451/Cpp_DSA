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
    vector<ll>arr(n);
    ll cnt0=0,cnt1=0;
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    	if(arr[i]==0)
    	{
    		cnt0++;
    	}
    	else
    		cnt1++;
    }
    if(cnt0>=cnt1)
    {
    	cout<<cnt0<<endl;
    	for(int i=0;i<cnt0;i++)
    	{
    		cout<<0<<" ";
    	}
    	cout<<endl;
    }
    else{
    	if(cnt1&1)cnt1--;
    	cout<<cnt1<<endl;
    	for(int i=0;i<cnt1;i++)
    	{
    		cout<<1<<" ";
    	}
    	cout<<endl;
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