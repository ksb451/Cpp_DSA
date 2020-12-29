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
		string s;
		cin>>s;
		ll n = s.length();
		ll arr[26] = {0};
		for(int i=0; i<n; i++){
			arr[s[i]-'a']++;
		}
		sort(arr, arr+26, greater<int>());
		int j = 0;
		for(; j<26; j++){
			if(arr[j] == 0)
				break;
		}
		j--;
//		cout<<j<<endl;
		int i = 0;
		ll ans = 0;
		ll one = 0;
		
		while(i <= j && s.length() >= 3){
			if(i != j){
				if(arr[i] % 3 == 0){
//					cout<<"ujjwa"<<endl;
					ans += arr[i] / 3;
					i++;
//					cout<<i<<" "<<j<<endl;
					continue;	
				}
//				cout<<"hell"<<endl;
				int x = arr[j] * 2;
				if(arr[i] == 1)
					one++;
				if(x > arr[i]){
					arr[j] -= arr[i]/2;
					ans += arr[i]/2;
					arr[i] -= arr[i]/2;
					if(arr[i] == 1)
						one++;
					i++;
				}
				else if(x < arr[i]){
					arr[i] -= x;
					ans += arr[j];
					if(arr[i] == 1)
						one++;
					j--;
				}
				else{
					ans += arr[j];
					i++; j--;
				}
			}
			else{
				if(arr[i] % 3 == 0){
//					cout<<"ujjwa"<<endl;
					ans += arr[i] / 3;
					i++;
					break;	
				}
				int rem = arr[i] % 3;
				ans += arr[i]/3;
				if(one >= 1 && rem == 2)
					ans++;
				i++;j--;
			}
		}
		cout<<ans<<endl;
	}

    return 0;
}