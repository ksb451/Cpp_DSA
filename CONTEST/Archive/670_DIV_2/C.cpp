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
const int MAX_N=100005;
int n;
vector<int>adj[MAX_N];
vector<int>sz;
vector<int>centroid;

void dfs(int u, int p)
{
	sz[u] = 1;
	int flag = 1;
	for (auto v : adj[u])
		if (v != p) {
	        dfs(v, u);
	        sz[u] += sz[v];
	        if (sz[v] > n / 2) 
				flag = 0;
		}
	if (n - sz[u] > n / 2)
		flag = 0;
	if (flag == 1) 
		centroid.push_back(u);
}

void solve()
{
	cin>>n;
	//cout<<"n done"<<endl;
    for(int i=0;i<MAX_N;i++)
    {
    	adj[i].clear();
    }
    sz=vector<int>(n+1,0);
	for(int i=0;i<n-1;i++)
	{
	    int a,b;
	    cin>>a>>b;
	    adj[a].push_back(b);
	    adj[b].push_back(a);
	}
	//cout<<"input done"<<endl;
	centroid.clear();
	dfs(1,-1);
	//cout<<centroid.size()<<endl;
	if(centroid.size()==1)
	{
		int i=centroid[0];
		int j=adj[i][0];
		cout<<i<<" "<<j<<endl;
		cout<<i<<" "<<j<<endl;
		return;
	}
	else if(centroid.size()==2){
		int i=centroid[0];
		int j=centroid[1];
		int k;
		if(adj[i].size()>1)
		{
			for(int q:adj[i])
			{
				if(q!=j)
				{
					k=q;
					break;
				}
			}
			cout<<i<<" "<<k<<endl;
			cout<<j<<" "<<k<<endl;
		}
		else{
			for(int q:adj[j])
			{
				if(q!=i)
				{
					k=q;
					break;
				}
			}
			cout<<j<<" "<<k<<endl;
			cout<<i<<" "<<k<<endl;
		}
		return;	
	}
return;
}

int main()
{
    //fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}