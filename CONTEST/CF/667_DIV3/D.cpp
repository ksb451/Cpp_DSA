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
int rec(string num, int s)
{
	int curr=0;
	for(int i=0;i<num.length();i++)
	{
		curr+=(num[i]-'0');
		if(curr>s)
		{
			return i-1;
		}
	}
	return num.length();
}

string add(string num,int pos)
{
	if(pos==-1)
	{
		num='1'+num;
		return num;
	}
	else{
		if(num[pos]=='9')
		{
			num[pos]='0';
			return add(num,pos-1);
		}
		else{
			num[pos]+=1;
			return num;
		}
	}
}
void solve()
{
	ll n,s;
    cin>>n>>s;
    string num=to_string(n);
    while(true)
    {
    	int pos=rec(num,s);
	    if(pos==-1)
	    {
	    	int x=num.length();
	    	num='1';
	    	for(int i=0;i<x;i++)
	    	{
	    		num+='0';
	    	}
	    }
	    else if(pos==num.length())
	    {
	    	break;
	    }
	    else{
	    	for(int i=pos+1;i<num.length();i++)
	    	{
	    		num[i]='0';
	    	}
	    	num=add(num,pos);
	    }
	}
	ll ans=stoll(num, nullptr, 10);
	cout<<ans-n<<endl;
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