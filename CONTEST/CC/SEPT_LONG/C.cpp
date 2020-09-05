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
using pdi = pair<double,int>;
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
ll n;
set<int>infected;
vector<vector<int>>passes;

void rec(int curr,int source)
{
	int i=0;
	for(;i<passes[curr].size();i++)
	{
		if(passes[curr][i]==source)
		{
			i++;
			break;
		}
	}
	for(;i<passes[curr].size();i++)
	{
		if(infected.count(passes[curr][i])==0)
		{
			infected.insert(passes[curr][i]);
			rec(passes[curr][i],curr);
		}
	}
}

void solve()
{
    cin>>n;
    vector<ll>speed(n);
    for(int i=0;i<n;i++)cin>>speed[i];
    passes=vector<vector<int>>(n);
	set<pdi>st;
    for(int i=0;i<n;i++)
    {
    	st.clear();
    	st.insert({0,i});
    	for(int j=0;j<n;j++)
    	{
    		if(((i<j)^(speed[i]<speed[j]))&&(speed[i]!=speed[j]))
    		{
    			double t=double(abs(i-j))/double(abs(speed[i]-speed[j]));
    			st.insert({t,j});
    		}
    	}
    	for(auto k:st)
    	{
    		passes[i].push_back(k.second);
    	}
    }
    // cout<<endl;
    // for(int i=0;i<n;i++)
    // {
    // 	cout<<i+1<<": ";
    // 	for(auto j:passes[i])
    // 	{
    // 		cout<<j+1<<" ";
    // 	}
    // 	cout<<endl;
    // }
    int mn=n+1,mx=0;
    for(int i=0;i<n;i++)
    {
    	infected.clear();
    	infected.insert(i);
    	rec(i,i);
    	int curr=infected.size();
    	mn=min(mn,curr);
    	mx=max(mx,curr);
    }
    cout<<mn<<" "<<mx<<endl;
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