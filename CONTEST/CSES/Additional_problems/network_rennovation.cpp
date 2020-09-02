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
vector<int>ans;
vector<int>adj[100002];


void dfs(int curr, int parent)
{
	for(auto i: adj[curr])
	{
		if(i!=parent)
		{
			dfs(i,curr);
		}
	}
	if(adj[curr].size()==1)
	{
		ans.push_back(curr);
	}
}
void solve()
{
	ll n;
    cin>>n;
    for(int i=0;i<n-1;i++)
	{
    	int a,b;
    	cin>>a>>b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
	}
	dfs(1,0);
	int si=ans.size();
	if(si%2){
	    ans.push_back(ans[0]);
	    si++;}
	cout<<si/2<<endl;
	for(int i=0;i<si/2;i++)
	cout<<ans[i]<<" "<<ans[i+si/2]<<endl;
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