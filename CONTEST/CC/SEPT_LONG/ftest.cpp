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

void solve(int n,int x)
{
	srand(time(0));
	ll l1=rand()%20;
	ll l2=rand()%30;
	deque<int>arr1,arr2;
	int x1=0,x2=0;
	for(int i=0;i<l1;i++)
	{
		arr1.push_back(rand()%n);
		if((rand()%2)==1 && x1<x)
		{
			arr1.push_back(n);
			x1++;
		}
	}

	for(int i=0;i<l2;i++) 
	{
		arr2.push_back(rand()%n);
		if((rand()%2)==1 && x2<x)
		{
			arr2.push_back(n);
			x2++;
		}
	}
	while(x1<x)
	{
		arr1.push_back(n);
		x1++;
	}
	while(x2<x)
	{
		arr2.push_back(n);
		x2++;
	}
	arr1.push_back(n);
	for(int i=0;i<1000;i++)
	{
		int a=arr1.front();
		int b=arr2.front();
		arr1.pop_front();	
		arr2.pop_front();
		if(a==b)
		{
			arr1.push_back(a);
			arr2.push_back(b);
		}
		else if(a<b)
		{
			arr2.push_back(b);
			a--;
			if(a>0)
				arr2.push_back(a);
		}
		else{
			arr1.push_back(a);
			b--;
			if(b>0)
				arr1.push_back(b);
		}
	}
	for(auto i:arr1)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	for(auto i:arr2)
	{
		cout<<i<<" ";
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
    	int n,x;
    	cin>>n>>x;
        solve(n,x);
    }
    return 0;
}