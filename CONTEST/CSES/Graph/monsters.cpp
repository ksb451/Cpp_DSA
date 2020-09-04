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
	ll n,m;
    cin>>n>>m;
    vector<string>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int mon[n][m];
	memset(mon,0,sizeof(mon));
    queue<pii>Q,MQ;
	vector<vector<int>>parent(n,vector<int>(m,-1));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]=='A')
				Q.push({i,j});
			else if(arr[i][j]=='M')
			{
				MQ.push({i,j});
			}
		}
	}
	bool flag=false;
	pii dest;
	while(!Q.empty())
	{
		int qs=Q.size();
		while(qs--)
		{
			pii curr = Q.front();
			Q.pop();
			//cout<<curr.first<<" "<<curr.second<<" "<<mon[curr.first][curr.second]<<endl;
			if(curr.first==0||curr.first==n-1||curr.second==0||curr.second==m-1)
			{
				if(mon[curr.first][curr.second]==0)
				{
					flag=true;
					dest=curr;
					break;
				}
			}
			if(mon[curr.first][curr.second]==0)
			{
				for(int i=0;i<4;i++)
				{
					int ii=curr.first+dir4[i][0];
					int jj = curr.second + dir4[i][1];
					if(ii>=0&&ii<n&&jj>=0&&jj<m)
					{
						if(arr[ii][jj]!='#'&&parent[ii][jj]==-1&&mon[ii][jj]==0)
						{
							parent[ii][jj]=i;
							Q.push({ii,jj});
						}
					}
				}
			}
		}
		int mqs=MQ.size();
		while(mqs--)
		{
			pii curr = MQ.front();
			MQ.pop();
			for(int i=0;i<4;i++)
			{
				int ii=curr.first+dir4[i][0];
				int jj = curr.second + dir4[i][1];
				if(ii>=0&&ii<n&&jj>=0&&jj<m)
				{
					if(arr[ii][jj]!='#'&&mon[ii][jj]==0)
					{
						mon[ii][jj]=1;
						MQ.push({ii,jj});
					}
				}
			}
		}
	}
	if(flag)
	{
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
		return;
	}
	string ans="";
	int i=dest.first,j=dest.second;
	while(arr[i][j]!='A')
	{
		if(parent[i][j]==1)
		{
			ans+='R';
			j--;
		}
		else if(parent[i][j]==2) {
			ans+='U';
			i++;
		}
		else if(parent[i][j]==3) {
			ans+='L';
			j++;
		}
		else {
			ans+='D';
			i--;
		}
	}
	reverse(all(ans));
	cout<<ans.length()<<endl<<ans<<endl;
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