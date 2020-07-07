// Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 

// Return the number of negative numbers in grid.

 

// Example 1:

// Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
// Output: 8
// Explanation: There are 8 negatives number in the matrix.
// Example 2:

// Input: grid = [[3,2],[1,0]]
// Output: 0

#include<vector>
#include<iostream>

using namespace std;
int lower_bound(vector<int>&A,int B)
{
    int ans=A.size();
    int start=0;
    int end=ans-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(A[mid]<B)
        {
            ans=mid;
            end=mid-1;
        }
        else if(A[mid]>=B)
        {
            start = mid + 1;
        }
    }
    return ans;
}
int countNegatives(vector<vector<int>>& grid) {
    int m=grid.size();
    int ans=0;
    for(int i=0;i<m;i++)
    {
        int q=lower_bound(grid[i],0);
        cout<<q<<endl;
        ans+=grid[i].size()-q;
    }
    return ans;
    
}
int main()
{
    vector<vector<int>>X={{4,3,2,1},{3,2,1,0},{2,1,0,-1},{1,0,-1,-2}};
    cout<<countNegatives(X);
    return 0;
}
