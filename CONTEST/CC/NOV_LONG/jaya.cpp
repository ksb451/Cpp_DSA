#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

using ll = long long int;

struct call 
{ 
	int start, finish, vol; 
}; 

bool myfunction(call c1, call c2) 
{ 
	return (c1.finish < c2.finish); 
} 


int binarySearch(vector<call>&calls, int ind) 
{ 
	
	int lo = 0, hi = ind - 1; 
	while (lo <= hi) 
	{ 
		int mid = (lo + hi) / 2; 
		if (calls[mid].finish <= calls[ind].start) 
		{ 
			if (calls[mid + 1].finish <= calls[ind].start) 
				lo = mid + 1; 
			else
				return mid; 
		} 
		else
			hi = mid - 1; 
	} 

	return -1; 
} 

int solve(vector<call>&arr) 
{ 
	ll n  = arr.size();
	sort(arr.begin(), arr.end(), myfunction); 
	
	int *dp = new int[n]; 
	dp[0] = arr[0].vol; 

	
	for (int i=1; i<n; i++) 
	{ 
		
		int inclProf = arr[i].vol; 
		int l = binarySearch(arr, i); 
		if (l != -1) 
			inclProf += dp[l]; 

		dp[i] = max(inclProf, dp[i-1]); 
	} 

	int result = dp[n-1]; 
	delete[] dp; 
	return result; 
} 

// Driver program 
int main() 
{ 
	ll n;
	cin>>n;
	vector<call>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].start;
	}
	for(int i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		arr[i].finish  = arr[i].start+x;
	}
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].vol;
	}
	cout<<solve(arr)<<endl; 
	return 0; 
} 
