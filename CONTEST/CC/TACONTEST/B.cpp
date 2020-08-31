/******************************************
* AUTHOR : Keshab Agrawal *
* NICK : sn0wrus *
******************************************/
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
#define write(a)          \
    for (auto x : a)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << nl;
#define read(a)       \
    for (auto &x : a) \
    {                 \
        cin >> x;     \
    }
using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 988244353LL;

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

#define BITS 32

void solve()
{
	int n;
    cin>>n;
    vector<int>arr(n);
    read(arr);
    int index = 0;
    for(int i=BITS-1;i>=0;i--)
    {
    	int mx_ind=index;
    	int mx_ele=INT_MIN;
    	for(int j=index; j<n;j++)
    	{
    		if((arr[j]&(1<<i)))
    		{
    			if(arr[j]>mx_ele)
    			{
    				mx_ele=arr[j];
    				mx_ind=j;
    			}
    		}
    	}
		if(mx_ele==INT_MIN)
		{
			continue;
		}
		int temp=arr[index];
		arr[index]=arr[mx_ind];
		arr[mx_ind]=temp;

		mx_ind=index;

		for(int j=0;j<n;j++)
		{
			if(j!=mx_ind && (arr[j]&(1<<i)))
			{
				arr[j]=arr[j]^arr[mx_ind];
			}
		}
    	index++;
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans^=arr[i];
	}
	cout<<ans<<endl;
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