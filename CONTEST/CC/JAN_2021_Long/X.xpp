/* Nitin Madhukar */
#include<bits/stdc++.h>
#include<tuple>

#define ll              long long
#define mp              make_pair
#define pb              push_back
#define lb              lower_bound
#define ub              upper_bound
#define all(x)          x.begin(), x.end()
#define big(x)          greater<x>()

#define sp              fixed<<setprecision
#define vi              vector<int>
#define vvi             vector<vi>
#define pi              pair<int,int>

#define PI              3.14159265
#define M               (int)1000000007
#define LINF            LONG_MAX
#define NL              LONG_MIN
#define INF             INT_MAX
#define NI              INT_MIN

#define IOS()           ios_base::sync_with_stdio(0);cin.tie(0);
#define deb(x)          cerr<<#x<<" : "<<x<<"\n";
#define deball(x)       for(auto iit:x) cerr<<" "<<iit;cerr<<"\n";
#define rep(i,b,c)      for(i=b; i<c; ++i)
#define rrep(i,b,c)     for(i=b; i>=c; --i)

using namespace std;

void solve() {
    ll n;
    cin>>n;
    set<ll>s;
    ll ans=0;
    vector<vector<ll>>re(n,vector<ll>(4,0));
    unordered_map<ll,vector<ll>>mp;
    vector<ll>usl(1000);
    for(ll i=0;i<1000;i++)usl[i]+=i*3;
    
    for(ll i=0;i<n;i++){
    	ll m;
    	cin>>m;
    	for(ll j=0;j<m;j++){
    		ll x;
    		cin>>x;
    		if(x<=1){
    		    re[i][2]++;
    		}
    		else{
    			re[i][0]++;
    			re[i][1]++;
    		}
    		s.insert(abs(x));
    		mp[x].pb(i);
    	}
    }
    for(ll i=0;i<1000;i++)usl[i]+=i*335;
    for(auto i:s){
    	ll si=0;
    	if(mp.find(i)!=mp.end())si+=mp[i].size();
    	ll neg = (0-i);
    	if(mp.find(neg)!=mp.end())si+=mp[neg].size();
        
    	if(si>1){
    	    ans++;
    		if(mp.find(i)!=mp.end()){
	    		for(auto j: mp[i]){
	    			re[j][1]--;
	    			re[j][0]--;
	    			ans+=re[j][1];
    			}
	    	}
	    	if(mp.find(neg)!=mp.end()){
	    		for(auto j:mp[neg]){
	    			re[j][2]--;
	    			ans+=re[j][2];
	    			ans+=re[j][3];
	    		}
	    	}
    	}
    	else{
    	    if(mp[i].size()==1){
    			ll j=mp[i][0];
    			re[j][1]--;
    			re[j][3]++;
    		}
    		if(mp[neg].size()==1){
    			ll j=mp[neg][0];
				ans+=re[j][0];
				re[j][2]--;
    		}
    	}
    }
     for(ll i=0;i<1000;i++)usl[i]+=i*5;
     for(ll i=0;i<1000;i++)usl[i]+=i*23;

   cout<<ans<<'\n';
}
int main(){
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}