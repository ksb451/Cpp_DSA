//**sn0wrus**//
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);
#define write(a)          \
    for (auto x : a)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << endl;
#define read(a)       \
    for (auto &x : a) \
    {                 \
        cin >> x;     \
    }
#define IN cin >>
#define OUT cout <<
//#define endl "\n"
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define fi first;
#define se second;

using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;   
using pii = pair<int, int>;
using plll  = pair<ll,pll>;
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
bool flag=false;
ll bfs(set<ll>adj[],vector<ll>&vis,ll i, ll mark,ll par)
{
	vis[i]=mark;
	ll res=1;
	for(auto j:adj[i])
	{
		if(vis[j]==0){
			res+=bfs(adj,vis,j,mark,i);
		}
		else if((j!=par)&&(par!=-1)&&vis[j]==mark)
		{
			flag=true;
		}
	}
	return res;
} 

void solve()
{
	ll n,m;
    cin>>n>>m;
    vector<pll>arr;
    arr.push_back({0,0});
    unordered_map<ll,ll>row;
    unordered_map<ll,ll>col;
    ll cnt=0;
    for(int i=1;i<=m;i++)
    {
		ll a,b;
		cin>>a>>b;
		row[a]=i;;
		col[b]=i;
		if(a==b)
		{
		}
		arr.push_back({a,b});
	}
	//cout<<"input"<<endl;
	set<ll>adj[m+1];
	vector<ll>vis(m+1,0);
	for(int i=1;i<=m;i++)
	{
		//cout<<arr[i].first<<" "<<arr[i].second<<endl;
		//cout<<row[arr[i].second]<<" "<<col[arr[i].first]<<endl;
		if(arr[i].first==arr[i].second){
			vis[i]=1;
			continue;
		}
		else{
			if(row[arr[i].second]==0)
			{
				// cout<<1<<endl;
				col[arr[i].second]=0;
				row[arr[i].second]=i;
				vis[i]=1;
				cnt++;
			}
			else if(col[arr[i].first]==0)
			{
				//cout<<2<<endl;
				row[arr[i].first]=0;
				col[arr[i].first]=i;
				vis[i]=1;
				cnt++;
			}
			else{
				//cout<<3<<endl;
				if(row[arr[i].second]==col[arr[i].first])
				{
					ll w = row[arr[i].second];
					cnt+=3;
					vis[i]=1;
					vis[w]=1;
					row[arr[i].first]=w;
					col[arr[w].second]=i;
				}
				adj[i].insert(row[arr[i].second]);
				adj[row[arr[i].second]].insert(i);
				adj[i].insert(col[arr[i].first]);
				adj[col[arr[i].first]].insert(i);
			}
		}
	}
	// cout<<"done"<<endl;
	// for(int i=1;i<=m;i++)
	// {
	// 	for(auto j:adj[i])
	// 	{
	// 		cout<<j<<" ";
	// 	}
	// 	cout<<endl;
	// }
	for(int i=1;i<=m;i++)
	{
		flag=false;
		if(vis[i]==0)
		{
			ll q=bfs(adj,vis,i,i+1,-1);
			// cout<<q<<endl;
			// cout<<flag<<endl;
			if(flag==false)
			{
				cnt--;
			}
			cnt+=(q+1);
			//cout<<cnt<<endl;
		}
	}
	cout<<cnt<<endl;
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