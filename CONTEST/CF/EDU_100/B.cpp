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
const ll MAX  = (ll)1e9;
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


vector<ll> solve(vector<ll>arr)
{
	ll n=arr.size();
 //    cin>>n;
 //    vector<ll>arr(n);
    ll sum=0;
    //for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++)
    {
    	sum+=arr[i];
    }
	//cout<<sum<<endl;
	ll avg = sum/n;
	//cout<<avg<<endl;
	for(int i=0;i<n;i++)
	{
		
		ll rem = arr[i]%avg;
		//cout<<rem<<" ";
		if(rem <= avg/2)
		{
			//cout<<"less";
			arr[i]-=rem;
		}
		else{
			//cout<<"more";
			arr[i]+=(avg-rem);
		}
		// cout<<arr[i];
		if(arr[i]>MAX)
		{
			arr[i]-=avg;
		}
		if(arr[i]<=0)
		{
			arr[i]=1;
		}
		// cout<<endl;
	}
	return arr;
	for(auto i:arr)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	
}

void test()
{
	srand(time(0));
	ll n = rand()/50;
	vector<ll>arr(n);
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		arr[i] = rand()%MAX;
		sum+=arr[i];
	}
	vector<ll>ans = solve(arr);
	ll s=0;
	for(int i =0;i<n;i++)
	{
		s+=abs(arr[i]-ans[i]);
	}
	if(s > sum/2)
	{
		for(int i=0;i<n;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
    fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        test();
    }
    return 0;
}