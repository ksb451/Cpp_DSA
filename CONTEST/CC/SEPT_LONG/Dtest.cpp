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

void decToBinary(ll n) 
{ 
    // Size of an integer is assumed to be 32 bits 
    for (int i = 31; i >= 0; i--) { 
        ll k = n >> i; 
        if (k & 1) 
            cout << "1"; 
        else
            cout << "0"; 
    }
    cout<<endl; 
} 
  
void solve()
{

	srand(time(0));
	// ll n=rand()%10;
	// cout<<n<<endl;
	// vector<ll>arr(n);
	// for(int i=0;i<n;i++)
	// {
	// 	arr[i]=rand()%10000;
	// }
	ll n=2;
	vector<int>arr={1,2};
	// ll n=4;
	// vector<int>arr={1,2,3,4}; 
	ll sum=0;
	ll xorsum=0;
	ll sumxorsum=(1<<20)-1;
	for(int j=1;j<=20;j++)
	{
		ll k=(1LL<<j);
		//decToBinary(k);
		sum=0;
		xorsum=0;
		for(int i=0;i<arr.size();i++)
		{
			sum^=arr[i];
			xorsum+=(arr[i]^k);
		}
		//cout<<xorsum<<" "<<sum<<"  "<<(sum^k)<<endl;
		cout<<xorsum<<endl;
		//decToBinary(xorsum);
		sumxorsum&=xorsum;
		//decToBinary(xorsum^k);
		cout<<endl;
	}
	cout<<endl;
	decToBinary(sumxorsum);
	decToBinary(sum);
}

int main()
{
	ll tc;
    while (cin>>tc)
    {
    	if(tc==-1)
    	{
    		return 0;
    	}
        solve();
    }
    return 0;
}