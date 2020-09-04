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
ll n,m;
vector<int>adj[200002];
void solve()
{
    cin>>n>>m;
    //vector<ll>arr(n);
    for(int i=0;i<m;i++)
	{
    	int a,b;
    	cin>>a>>b;
    	//a--,b--;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
	}
	int parent[n+1];
	memset(parent,-1,sizeof(parent));
	queue<int>Q;
	Q.push(1);
	parent[1]=0;
	bool flag=false;
	while(!Q.empty())
	{
		int curr = Q.front();
		Q.pop();
		if(curr==n)
		{
			flag=true;
			break;
		}
		for(auto j:adj[curr])
		{
			if(parent[j]==-1)
			{
				parent[j]=curr;
				Q.push(j);
			}
		}
	}
	if(flag)
	{
		vector<int>ans;
		ans.push_back(n);
		int i=n;
		while(i!=1)
		{
			i=parent[i];
			ans.push_back(i);
		}
		reverse(all(ans));
		cout<<ans.size()<<endl;
		for(auto j:ans)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
	else{
		cout<<"IMPOSSIBLE"<<endl;
	}
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