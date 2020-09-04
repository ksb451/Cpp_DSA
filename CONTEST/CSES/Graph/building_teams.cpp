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
int team[200002];

bool bfs(int start)
{
	queue<int>Q;
	Q.push(start);
	team[start]=1;
	while(!Q.empty())
	{
		int curr= Q.front();
		Q.pop();
		for(auto j:adj[curr])
		{
			if(team[j]==0)
			{
				if(team[curr]==1)
				{
					team[j]=2;
				}
				else{
					team[j]=1;
				}
				Q.push(j);
			}
			else{
				if(team[j]==team[curr])
				{
					return false;
				}
			}	
		}
	}
	return true;
}

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
	memset(team,0,sizeof(team));
	for(int i=1;i<=n;i++)
	{
		if(team[i]==0)
		{
			if(!(bfs(i)))
			{
				cout<<"IMPOSSIBLE"<<endl;
				return;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<team[i]<<" ";
	}
	cout<<endl;
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