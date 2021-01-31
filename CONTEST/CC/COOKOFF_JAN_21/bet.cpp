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
 
bool all_even(ll arr[], ll n){
	for0(i, 2*n)
		if(arr[i] % 2 != 0)
			return false;
	return true;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
 
    int tc = 1;
    cin>>tc;
    while(tc--){
		ll n;
		cin>>n;
		ll arr[2*n];
		for0(i, 2*n)
			cin>>arr[i];
		if(all_even(arr, n) == false){
			cout<<"NO"<<endl;
			continue;
		}
		map<int, int> m;
		int flag = 0;
		for0(i, 2*n){
			m[arr[i]]++;
			if(m[arr[i]] > 2){
				cout<<"NO"<<endl;
				flag = 1;
				break;
			}
		}
		for0(i, 2*n){
			if(m[arr[i]] < 2){
				cout<<"NO"<<endl;
				flag = 1;
				break;
			}
		}
		if(flag == 1)
			continue;
		vector<long long int> dp;
		ll j = 2;
		sort(arr, arr+2*n);
		int arr1[n];
		for(int i=0; i<n; i+=2){
			arr1[i/2] = arr[i];
		}
		for(int i=1; i<n; i++){
			dp.pb((arr1[i] - arr1[i-1]) / j);
			j += 2; 
		}
		ll k = 1, sum = 0;
		for(int i=dp.size()-1; i>=0; i--){
			sum = sum + (dp[i]*k);
			k++;
		}
		ll first = (arr1[0] - sum)/n;
		if(first > 0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		
	}
 
    return 0;
}