
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long int lld;

lld LIS(const vector<lld>& A)
{
    lld n=A.size();
    vector<lld>lis(n+1,1);
    for(lld i=0;i<=n;i++)
    {
        for(lld j=0;j<i;j++)
        {
            if(A[i]>A[j])
            {
                lis[i]=max(lis[i],lis[j]+1);
            }
        }
    }
    lld ans=*max_element(lis.begin(),lis.end());
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
