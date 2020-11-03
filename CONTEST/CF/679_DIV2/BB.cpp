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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int tc = 1;
    cin>>tc;
    while(tc--){
		ll n, m;
		cin>>n>>m;
		map<int, vector<int> > mp;
		set<int> s;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			s.insert(x);
			mp[x].pb(x);
			for(int j=1; j<m; j++){
				int y;
				cin>>y;
				mp[x].pb(y);
			}
		}
		int col[m][n];
		vector<vector<int> > ans;
		for(int i=0; i<m; i++){
			int flag = 0;
			for(int j=0; j<n; j++){
				int x;
				cin>>x;
				if(j == 0 && s.find(x) != s.end()){
					flag = 1;
				}
				if(flag == 1){
					ans.pb(mp[x]);
				}
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}
	}

    return 0;
}