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
    int t1 = 1;
    while(tc--){
		ll n, m;
		cin>>n>>m;
		vector<vector<int> > range;
		for(int i=0; i<n; i++){
			int x, y;
			cin>>x>>y;
			vector<int> temp;
			temp.pb(x); temp.pb(y);
			range.push_back(temp);
		}
		
		int arr[1001] = {0};
		for(int i=1; i<1001; i++){
			for(int j=0; j<range.size(); j++){
				if(i >= range[j][0] && i <= range[j][1]){
					arr[i] = 1;
					break;
				}
			}
		}
		
		vector<int> ans;
		for(int i=0; i<m; i++){
			int x;
			cin>>x;
			int prev = x, next = x;
			while(prev != 0 && arr[prev] != 1){
				prev--;
			}
			if(prev == 0)
				prev = -10000;
	
			while(next != 1001 && arr[next] != 1)
				next++;
			if(next == 1001){
				next = 10000;
			}
			if(next-x >= x-prev){
				arr[prev] = 2;
				ans.push_back(prev);
			}
			else if(next-x < x-prev){
				arr[next] = 2;
				ans.push_back(next);
			}
		}
		cout<<"Case #"<<t1<<": ";
		for(int i=0; i<m; i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
		t1++;
	}

    return 0;
}