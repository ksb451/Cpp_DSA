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
#define endl "\n"
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



void solve()
{
	ll n,x;
    cin>>n>>x;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

  	deque<ll>ind[32];
  	for(int i=0;i<n;i++)
  	{
  		for(int j=31;j>=0;j--)
  		{
  			if((arr[i])&(1LL<<j))
  			{
  				ind[j].push_back(i);
  			}
  		}
  	}
  	int flag=0;
  	for(int i=0;i<n-1;i++)
  	{
  		if(x==0)
  		{
  			break;
  		}
 		for(int j=31;j>=0;j--)
 		{
 			if(x==0)
 			{
 				break;
 			}
 			if(arr[i]&(1<<j))
 			{
 				ind[j].pop_front();
 				int next;
 				if(ind[j].empty())
 				{
 					next=n-1;
 					ind[j].push_back(n-1);
 				}
 				else{
 					next = ind[j].front();
 					ind[j].pop_front();
 				}
 				if((i!=n-1)&&(next!=n-1))
 					flag=1;
 				//cout<<i<<" "<<next<<" "<<j<<endl;
 				arr[i]^=(1<<j);
 				arr[next]^=(1<<j);
 				x--;
 			}
 		}
  	}
  	if(!flag)
  	{
  	if(x%2==1)
  	{
  		arr[n-2]=1;
  		arr[n-1]^=1;
  	}
  }
  	for(int i=0;i<n;i++)
  	{
  		cout<<arr[i]<<" ";
  	}
  	cout<<endl;
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


