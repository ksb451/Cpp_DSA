
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
typedef long double ld;

ld fac;
ld total;

void rec(vector<ll>arr,ld score)
{
	if(arr.size()==1)
	{
		total+=(score/fac);
	}
	else{
		ll n = arr.size();
		for(int i=0;i<n-1;i++)
		{
			ld curr=score;
			curr+=(arr[i]+arr[i+1]);
			vector<ll>x;
			for(int j=0;j<n;j++)
			{
				if(j==i)
				{
					x.push_back(arr[i]+arr[i+1]);
					j++;	
				}
				else{
					x.push_back(arr[j]);
				}
			}
			rec(x,curr);
		}
	}
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(6);
    std::cout.setf( std::ios::fixed, std:: ios::floatfield );
    cout << fixed;

    int tc = 1;
    cin>>tc;
    int tm = 1;
    while(tc--){
    	ll n;
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    }
    total =0;
    fac=1;
    for(ll i=1;i<n;i++)
    {
    	fac*=i;
    }

    rec(arr,0);
	cout<<"Case #"<<tm<<": "<<total<<endl;;
		
		tm++;
	}

    return 0;
}