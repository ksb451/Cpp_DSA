#include <bits/stdc++.h>  // This will work only for g++ compiler.


#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) // reverse 1 based

//short hand for usual tokens
#define pb push_back
#define fi first
#define se second

// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal

// find if a given value is present in a container. Container version. Runs in log(n) for set and map
#define present(c,x) ((c).find(x) != (c).end())

// Avoiding wrap around of size()-1 where size is a unsigned int.
#define sz(a) int((a).size())


using namespace std;

// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
void compute(string &s, int qx, int i)
{
	//cout<<q<<" ";
	while(qx--)
	{
		s[i]='W';
		i++;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int tc = 1;
    cin>>tc;
    while(tc--){
    	ll n, k;
		cin>>n>>k;
		string s;
		cin>>s;
		ll ans = 0;
		ll st=0;
		ll i=0;
		if(s[i]=='L')
		{
			ll count=0;
			while(i<n && s[i]=='L'){
				i++;
				count++;
			}
			st = count;
		}
		if(i==n){
			ans = (2*k - 1);
			continue;
		}
		ll j = n-1;
		ll l = 0;
		if(s[j]=='L'){
			ll c=0;
			while(j>=0 && s[j]=='L')
			{
				j--;
				c++;
			}
			l=c;
		}
		set<pair< long long int, long long int > > s1;
		for(ll x=i;x<=j;x++){
			if(s[x]=='L'){
				ll q=x;
				ll c=0;
				while(x<=j && s[x]=='L'){
					c++;
					x++;
				}
				s1.insert({c,q});
			}
		}
		while(k>0){
			if(!s1.empty()){
				auto itr = *s1.begin();
				if(itr.first<=k)
				{
					s1.erase(s1.begin());
					compute(s,itr.first,itr.second);
					k-=itr.first;
				}
				else{
					break;
				}
			}
			else{
				break;
			}
		
		}
		if(!s1.empty())
		{
			auto itr = *s1.begin();
			ll c = min(k,itr.first);
			s1.erase(s1.begin());
			compute(s,c,itr.second);
			k-=c;
		}
		if(k>0)
		{
			ll c = min(l,k);
			k-=c;
			compute(s,c,n-l);
		}
		if(k>0)
		{
			ll c = min(k,st);
			compute(s, c, st-c);
		}
		ans=0;
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='W')
			{
				if(flag ==1)
				{
					ans+=2;
				}
				else{
					ans+=1;
					flag=1;
				}
			}
			else{
				flag=0;
			}
		}
		cout<<ans<<endl;
	}

    return 0;
}