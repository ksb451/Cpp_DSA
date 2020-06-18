#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;

#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;

//highly optimized codee
// int minCut(string A) {
    
//      int n = A.size();
//         vector<int> cut(n+1, 0);  // number of cuts for the first k characters
//         for (int i = 0; i <= n; i++) cut[i] = i-1;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; i-j >= 0 && i+j < n && A[i-j]==A[i+j] ; j++) // odd length palindrome
//                 cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

//             for (int j = 1; i-j+1 >= 0 && i+j < n && A[i-j+1] == A[i+j]; j++) // even length palindrome
//                 cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
//         }
//         return cut[n];
// }


bool ispalindrome(string str,int i,int j)//function to check 
{
    if(i>=j)
        return true;
    while(i<j)
    {
        if(str[i]!=str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int partition(string str,int i,int j,vector<vector<int>>&dp)
{
    if(i>=j)
    {
        return dp[i][j]=0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(ispalindrome(str,i,j))
    {
        return dp[i][j]=0;
    }
    else
    {
        int left;
        int right;
        int mn=INT_MAX;
        for(int k=i;k<j;k++)
        {
            if(dp[i][k]!=-1)//optimization to reduce recursion call overhead;
            {
                left=dp[i][k];
            }
            else
            {
                left=partition(str,i,k,dp);
            }
            if(dp[k+1][j]!=-1)
            {
                right=dp[k+1][j];
            }
            else
            {
                right=partition(str,k+1,j,dp);
            }
            int temp=left+right+1;
            mn=min(mn,temp);
        }
        return dp[i][j]=mn;
    }
}
int main()
{
    int t;
    cin>>t;
    cin.get();
    while(t--)
    {
        string s;
        cin>>s;
        cin.get();
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        cout<<partition(s,0,n-1,dp)<<endl;
    }
    
}

//bottom up codee to reduce recursive call overhead 
//faster

// Returns count of all possible parenthesizations that lead to 
// result true for a boolean expression with symbols like true 
// and false and operators like &, | and ^ filled between symbols 
int countParenth(char symb[], char oper[], int n) 
{ 
	int F[n][n], T[n][n]; 

	// Fill diaginal entries first 
	// All diagonal entries in T[i][i] are 1 if symbol[i] 
	// is T (true). Similarly, all F[i][i] entries are 1 if 
	// symbol[i] is F (False) 
	for (int i = 0; i < n; i++) 
	{ 
		F[i][i] = (symb[i] == 'F')? 1: 0; 
		T[i][i] = (symb[i] == 'T')? 1: 0; 
	} 

	// Now fill T[i][i+1], T[i][i+2], T[i][i+3]... in order 
	// And F[i][i+1], F[i][i+2], F[i][i+3]... in order 
	for (int gap=1; gap<n; ++gap) 
	{ 
		for (int i=0, j=gap; j<n; ++i, ++j) 
		{ 
			T[i][j] = F[i][j] = 0; 
			for (int g=0; g<gap; g++) 
			{ 
				// Find place of parenthesization using current value 
				// of gap 
				int k = i + g; 

				// Store Total[i][k] and Total[k+1][j] 
				int tik = T[i][k] + F[i][k]; 
				int tkj = T[k+1][j] + F[k+1][j]; 

				// Follow the recursive formulas according to the current 
				// operator 
				if (oper[k] == '&') 
				{ 
					T[i][j] += T[i][k]*T[k+1][j]; 
					F[i][j] += (tik*tkj - T[i][k]*T[k+1][j]); 
				} 
				if (oper[k] == '|') 
				{ 
					F[i][j] += F[i][k]*F[k+1][j]; 
					T[i][j] += (tik*tkj - F[i][k]*F[k+1][j]); 
				} 
				if (oper[k] == '^') 
				{ 
					T[i][j] += F[i][k]*T[k+1][j] + T[i][k]*F[k+1][j]; 
					F[i][j] += T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j]; 
				} 
			} 
		} 
	} 
	return T[0][n-1]; 
} 