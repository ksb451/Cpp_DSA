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

ll n, m;

int dfs(vector<string> &g, int i, int j, vector<vector<int> > &vis, char check){
	if(i >= n || i < 0 || j >= m || j < 0 || vis[i][j] == 1 || g[i][j] == '#')
		return 0;
	vis[i][j] = 1;
	if(g[i][j] >= 'a' && g[i][j] <= 'z' && check != g[i][j]){
		return 1;
	}
	int a = dfs(g, i+1, j, vis, check);
	int b = dfs(g, i, j+1, vis, check);
	int c = dfs(g, i-1, j, vis, check);
	int d = dfs(g, i, j-1, vis, check);
	return a+b+c+d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int tc = 1;
    cin>>tc;
    int t1 = 1;
    while(tc--){
		cin>>n>>m;
		vector<string> g;
		for(int i=0; i<n; i++){
			string s;
			cin>>s;
			g.pb(s);
		}
		vector<int> ans(27, 0);
		vector<vector<int> > vis(n, vector<int> (m, 0));
		
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(!vis[i][j] && (g[i][j] >= 'a' && g[i][j] <= 'z')){
					int x = dfs(g, i, j, vis, g[i][j]);
					if(x == 0)
						ans[g[i][j] - 'a']++;
					else
						ans[26]++;
				}
			}
		}
		cout<<"Case "<<t1<<":"<<endl;
		for(int i=0; i<27; i++){
			if(i == 26){
				cout<<"contested "<<ans[i]<<endl;
				break;
			}
			if(ans[i] != 0){
				char x = 'a'+i;
				cout<<x<<" "<<ans[i]<<endl;
			}
		}
		t1++;
	}

    return 0;
}