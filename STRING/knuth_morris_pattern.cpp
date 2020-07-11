#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void calculate_lps(string &pattern, vector<int> &lps)
{
    int l = pattern.length();
    int i = 1;
    int j = 0;
    while (i < l)
    {
        if (pattern[i] == pattern[j])
        {
            lps[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> KMPSearch(string str, string pattern)
{
    int n = str.length();
    int m = pattern.length();
    vector<int> lps(m, 0);
    vector<int> ans;
    calculate_lps(pattern, lps);
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (pattern[j] == str[i])
        {
            j++;
            i++;
        }

        if (j == m)
        {
            ans.push_back(i - j);
            j = lps[j - 1];
        }

        else if (i < n && pattern[j] != str[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}