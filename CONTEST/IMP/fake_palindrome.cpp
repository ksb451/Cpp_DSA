#include <bits/stdc++.h>
using namespace std;

// Function to get the count of substrings
// whose anagrams are palindromic
void countSubstring(string s)
{
	// Store the answer
	int answer = 0;

	// Map to store the freq of masks
	unordered_map<int, int> m;

	// Set frequency for mask
	// 00...00 to 1
	m[0] = 1;

	// Store mask in x from 0 to i
	int x = 0;
	for (int j = 0; j < s.length(); j++) {
		x ^= 1 << (s[j] - 'a');

		// Update answer
		answer += m[x];
		for (int i = 0; i < 26; ++i) {
			answer += m[x ^ (1 << i)];
		}

		// Update frequency
		m[x] += 1;
	}

	// Print the answer
	cout << answer;
}

// Driver Code
int main()
{
	string str ;
	cin>>str;

	// Function Call
	countSubstring(str);
	return 0;
}