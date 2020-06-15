//dp solution to maximum length arithmatic subsequence
//similar to longest incresing subsequencee btt with the diff element for which map is used

int solve(const vector<int> &A) {
    int n=A.size();
    if(n==0||n==1||n==2)//base cases
    {
        return n;
    }
    vector<unordered_map<int,int>>dp(n);//a vector of map
    int MAX=2;//to keep the record of maximum length so that we dont have to serch it after words by running loops
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            int diff=A[j]-A[i];
            if(dp[j].find(diff)!=dp[j].end())//if diff exist in the previous than
            {
                int k=dp[j][diff]+1;
                MAX=max(MAX,k);//kepp record of max length
                dp[i][diff]=k;//keep the record in the current which wil be used after wards
            }
            else
            {
                dp[i][diff]=2;
            }
        }
    }
    return MAX;
}