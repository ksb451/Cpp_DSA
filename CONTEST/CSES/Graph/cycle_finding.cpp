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
const ll MAXN=2501;
ll n, m;
vector<pll>adj[MAXN];
ll d[MAXN], p[MAXN];
int vis1[MAXN];
void solve()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
    	ll a,b,c;
    	cin>>a>>b>>c;
    	a--,b--;
    	adj[a].push_back({b,c});
    }
    fill_n(d,MAXN,1e15);
    memset(vis1, 0,sizeof(vis1));
    //d[0]=0;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		for(auto k:adj[j])
    		{
    			//cout<<i<<" "<<" "<<j<<" "<<k.first<<" "<<d[k.first]<<" "<<d[j]+k.second<<endl;
    			if(d[k.first]>d[j]+k.second)
    			{
    				d[k.first]=d[j]+k.second;
    				p[k.first]=j;
    				if(i==n-1)
    				{
						cout<<"YES"<<endl;
						int q=k.first;
						while(vis1[q]==0)
						{
							vis1[q]=1;
							q=p[q];
						}
						vector<int>ans;
						int s=q;
						while(true)
						{
							ans.push_back(q);
							q=p[q];
							if(q==s&&ans.size()>1)
							{
								break;
							}
						}
						ans.push_back(q);
						reverse(all(ans));
						for(auto x:ans)
						{
							cout<<x+1<<" ";
						}
						cout<<endl;
						return;
    				}		
    			}
    		}
    	}
    }
    cout<<"NO"<<endl;
    return;
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