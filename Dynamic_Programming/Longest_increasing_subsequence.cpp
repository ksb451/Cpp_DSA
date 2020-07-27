
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long int lld;

lld LIS(const vector<lld> &A)
{
    lld n = A.size();
    vector<lld> lis(n + 1, 1);
    for (lld i = 0; i <= n; i++)
    {
        for (lld j = 0; j < i; j++)
        {
            if (A[i] > A[j])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    lld ans = *max_element(lis.begin(), lis.end());
    return ans;
}

//to count the no of lcs
int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size(), maxlen = 1, ans = 0;
    vector<int> cnt(n, 1), len(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                if (len[j] + 1 > len[i]) //if we get a bigger subwquence
                {
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                }
                else if (len[j] + 1 == len[i]) //if we get a sequence equel to found previous
                    cnt[i] += cnt[j];          //so we add to the diff subsequence we can get
            }
        }
        maxlen = max(maxlen, len[i]); //length of lis;
    }
    // find the longest increasing subsequence of the whole sequence
    // sum valid counts
    for (int i = 0; i < n; i++)
        if (len[i] == maxlen)
            ans += cnt[i]; //count all the occurence with length lis
    return ans;
}

//the driver function

// int main()
// {
//     int t=1;
//     cin>>t;
//     while(t--)
//     {

//     }
//     return 0;
// }
