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

int len(int n)
{
	int ans=0;
	while(n)
	{
		ans++;
		n>>=1;
	}
	return ans;
}

void solve()
{
	int n;
    cin>>n;
    if(n==1)
    {
    	cout<<1<<endl;
    	return;
    }
   	if((n&(n-1))==0)
   	{
   		cout<<-1<<endl;
   	}
   	else{
   		int l = len(n);
   		l--;
   		while(l>1)
   		{
   			int stop = (1<<l)+1;
   			int i =min(n,int(pow(2,l+1)-1));
   			while(i!=stop)
   			{
   				cout<<i<<" ";
   				i--;

   			}
   			cout<<(1<<l)<<" ";
   			cout<<(stop)<<" ";
   			l--;
   		}
   		cout<<"1 3 2"<<endl;
   	}

   	return;
   	
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