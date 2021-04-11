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
using ll = unsigned long long int;
// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;


ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
ll findlcm(vector<ll> arr, ll n, ll x){
    ll ans = arr[0];
    for (ll i = 1; i < n; i++)
    {
        ans = (((arr[i] * ans)) /
                (gcd(arr[i], ans)));
        if((ans < 0) || (ans>x))
        {
        	return -1;
        }
    }
 
    return ans;
}

void printSubsequences(vector<ll> arr, ll index, vector<ll> subarr, vector<vector<ll> >& perm)
{
    if (index == arr.size()){
        ll l = subarr.size();
        if (l != 0)
            perm.pb(subarr);
    }
    else{
        printSubsequences(arr, index + 1, subarr, perm);
        subarr.push_back(arr[index]);
        printSubsequences(arr, index + 1, subarr, perm);
    }
    return;
}

void solve()
{
	ll n, k, x;
	cin>>n>>k>>x;
	if(k >= n)
	{
		cout<<n<<endl;
		return;
	}
	vector<ll> v;
	for(ll i=0; i<n; i++){
		ll y;
		cin>>y;
		v.pb(y);
	}
	vector<vector<ll> > perm;
	vector<ll> temp;
	printSubsequences(v, 0, temp, perm);
	
	map<ll, vector<ll> > m;
	for(ll i=0; i < perm.size(); i++){
		if(perm.size() == 1)
			continue;
		ll y = findlcm(perm[i], perm[i].size(),x);
		if(y==-1)
		{
			continue;
		}
		if(y > x)
		    continue;
		if(m.find(y) == m.end())
			m[y] = perm[i];
		else{
			if(m[y].size() < perm[i].size())
				m[y] = perm[i];
		}
	}
	
	// map<ll, vector<ll> > :: iterator itr;
	// for(itr = m.begin(); itr != m.end(); itr++){
	// 	cout<<itr->first<<" ";
	// 	for(ll i=0; i<itr->second.size(); i++){
	// 		cout<<itr->second[i]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	multiset<ll>MM;
	for(auto i:m)
	{
		if(i.first > x)
		{
			cout<< n - MM.size() << endl;
			return;
		}
		if(i.second.size() > k)
		{
			vector<ll>vv;
			for(auto j:i.second)
			{
				if(MM.count(j))
				{

				}
				else{
					vv.push_back(j);
				}
			}
			if(vv.size() > k)
				MM.insert(all(vv));
		}
	}
	cout<< n -MM.size()<<endl;
	return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    ll tc = 1;
    cin>>tc;
    while(tc--){
		solve();
	}
    return 0;
}