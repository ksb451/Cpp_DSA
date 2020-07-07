//returns postion of strictly greater and strictly smaller elements

#include<vector>
using namespace std;

int upper_bound(vector<int>&A,int B)
{
    int ans=A.size();
    int start=0;
    int end=ans-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(A[mid]>B)
        {
            ans=mid;
            end=mid-1;
        }
        else if(A[mid]<=B)
        {
            start=mid+1;
        }
    }
    return ans;
}

int lower_bound(vector<int>&A,int B)
{
    int ans=-1;
    int start=0;
    int end=A.size()-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(A[mid]<B)
        {
            ans=mid;
            start=mid+1;
        }
        else if(A[mid]>=B)
        {
            end = mid - 1;
        }
    }
    return ans;
}