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
vector<bool>vis;

int next(int j)
{
	for(int i=j;i<vis.size();i++)
	{
		if(vis[i]==0)
		{
			return i;
		}
	}
	return vis.size();
}

bool solve()
{
	int n;
    cin>>n;
    int in;
    if(n==1)
    {
    	cout<<"! "<<1<<endl;
    	cout.flush();
    	cin>>in;
    	if(in==0)
    	{
    		return true;
    	}
    	else{
    		return false;
    	}
    }
    int cnt=0;
    int i=0;
    int j=1;
    vis=vector<bool>(n,0);
    vis[0]=1;
    vis[1]=1;
    vector<int>ans(n,-1);
    while(cnt<n)
    {
    	int in1,in2;
    	cout<<"? "<<i+1<<" "<<j+1;
    	cout<<endl;
    	cout.flush();
    	cin>>in1;
    	cout<<"? "<<j+1<<" "<<i+1;
    	cout<<endl;
    	cout.flush();
    	cin>>in2;

    	if(in1<in2)
    	{
    		ans[j]=in2;
    		cnt++;
    		j=next(j);
    		if(j<n)
    		{
    			vis[j]=1;
    		}
    		else{
    			break;
    		}
    	}
    	else{
    		ans[i]=in1;
    		cnt++;
    		i=next(i);
    		if(i<n)
    		{
    			vis[i]=1;
    		}
    		else{
    			break;
    		}
    	}
    }
    for(int i=0;i<n;i++)
    {
    	if(ans[i]==-1)
    	{
    		ans[i]=n;
    	}
    }
    cout<<"! ";
    for(auto i:ans)
    {
    	cout<<i<<" ";
    }
    cout<<endl;
    cout.flush();
    cin>>in;
    if(in==0)
    {
    	return true;
    }
    else{
    	return false;
    }

}

int main()
{
	fast;
    ll tc = 1;
    while (tc--)
    {
        if(solve())
        {

        }
        else{
        	return 0;
        }
    }
    return 0;
}