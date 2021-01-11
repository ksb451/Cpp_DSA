#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
const int mod=998244353;
//const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}


int subtask_n=200000,subtask_a=200000;
int a[200005];
int dp[200005][2];
void solve() {
    int n; cin>>n;
    fr(i,1,n) cin>>a[i];
	int maxi=0;
	fr(i,1,n) {
		dp[i][1]=-1;
		dp[i][0]=0;
	}
	fr(i,1,n) {
		dp[a[i]][0]=max(dp[a[i]][1]+1,dp[a[i]][0]);
		cout<<"dp[a[i]][0] "<<dp[a[i]][0]<<"\n";
		dp[a[i]][1]=max(dp[a[i]][1],maxi+1);
			cout<<"dp[a[i]][1] "<<dp[a[i]][1]<<"\n";
		maxi=max(maxi,dp[a[i]][0]);
		cout<<"maxi "<<maxi<<"\n\n";
	}
	cout<<n-maxi<<endl;
}


signed main() {
      int t; cin>>t;
      while(t--){
      	solve();
	  }
}