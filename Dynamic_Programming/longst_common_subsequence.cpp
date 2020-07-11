#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
//basic recursive function with huge overhead
int recursive(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (x[n - 1] == y[m - 1])
    {
        return 1 + recursive(x, y, n - 1, m - 1);
    }
    else
    {
        return max(recursive(x, y, n, m - 1), recursive(x, y, n - 1, m));
    }
}
//top down approch with memoziation
int topdown(string &x, string &y, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
    {
        return dp[n][m] = 0;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if (x[n - 1] == y[m - 1])
    {
        return dp[n][m] = 1 + topdown(x, y, n - 1, m - 1, dp);
    }
    else
    {
        return dp[n][m] = max(topdown(x, y, n, m - 1, dp), topdown(x, y, n - 1, m, dp));
    }
}
//bottom up approch no recursive call overhead.
int bottomup(string &x, string &y, int n, int m, vector<vector<int>> &dp)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                if (x[i - 1] == y[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
    }
    return dp[n][m];
}

pair<int, string> max(pair<int, string> a1, pair<int, string> a2)
{
    if (a1.first > a2.first)
    {
        return a1;
    }
    else if (a1.first == a2.first)
    {
        if (a1.second < a2.second) //to get the lexicographically smallest string
            return a1;
    }
    return a2;
}
//function to print the longest common substring
//same as the previous function called bottom up btt with storing string
string lcsubstring(string &A, string &B, int a, int b, map<pair<int, int>, pair<int, string>> &dps) //using a map for storing string
{
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if (i == 0 || j == 0)
            {
                dps[make_pair(i, j)] = make_pair(0, ""); //empty string for length zero
            }
            else
            {
                if (A[i - 1] == B[j - 1]) //if a letter matches
                {
                    dps[make_pair(i, j)] = make_pair(dps[make_pair(i - 1, j - 1)].first + 1,
                                                     dps[make_pair(i - 1, j - 1)].second + A[i - 1]); //take care of order while adding or else will get the reverse string
                }
                else
                {
                    dps[make_pair(i, j)] = max(dps[make_pair(i - 1, j)], dps[make_pair(i, j - 1)]); //if nott than compare //defined a aompare function for that
                }
            }
        }
    }
    return dps[make_pair(a, b)].second;
}

int main()
{
    int t;
    cin >> t;
    cin.get();
    while (t--)
    {
        // int a, b;
        // cin >> a >> b;
        // cin.get();
        string A, B;
        cin >> A;
        //cin >> B;
        int a = A.length();
        //int b = B.length();
        B = A;
        reverse(B.begin(), B.end());
        int b = B.length();
        //cout<<A<<a<<B<<b<<endl;
        vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));
        //length of longest common subsequence
        // cout << recursive(A, B, a, b) << endl;
        // cout << topdown(A, B, a, b, dp) << endl;
        cout << A << endl
             << B << endl;
        cout << bottomup(A, B, a, b, dp) << endl;
        //print the longest common subsequence;
        map<pair<int, int>, pair<int, string>> dps;

        cout << lcsubstring(A, B, a, b, dps) << endl;
    }
    //code
    return 0;
}