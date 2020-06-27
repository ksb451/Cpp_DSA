// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

// Try to solve it in linear time/space.

// Example :

// Input : [1, 10, 5]
// Output : 5 



//the idea is to create 1 more bucket so that atlest one will remain empty
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maximumGap(const vector<int> &A) {
    if(A.size()<2)
    {
        return 0;
    }
    if (A.size()==2)
    {
        return abs(A[0]-A[1]);
    }
    //base cases complete
    int n=A.size();
    int max_val=INT_MIN;
    int min_val=INT_MAX;
    for(int i=0;i< A.size();i++)
    {
        max_val=max(max_val,A[i]);//max value of array
        min_val=min(min_val,A[i]);//min value of array
    }
    //create n-1 buckets for n-2 items as we are excluding min and max value of array
    vector<int>bucket_max(n-1,INT_MIN);//create bucket for storing maximum value
    vector<int>bucket_min(n-1,INT_MAX);//creat bucket for storing minimum value
    double bucket_len=(double(max_val)-double(min_val))/double(n-1);//bucket length
    for(int i=0;i<n;i++)
    {
        if(A[i]==max_val||A[i]==min_val)
        {
            continue;
        }
        int bucket_no=int(double(A[i]-min_val)/bucket_len);
        bucket_max[bucket_no]=max(bucket_max[bucket_no],A[i]);//store the value in bucket
        bucket_min[bucket_no]=min(bucket_min[bucket_no],A[i]);
    }
    int gap=0;
    int prev=min_val;
    for(int i=0;i<n-1;i++)
    {
        if(bucket_min[i]==INT_MAX)//if bucket is empty
        {
            continue;
        }
        gap=max(gap,bucket_min[i]-prev);//calculate maximum gap
        prev=bucket_max[i];
    }
    gap=max(gap,max_val-prev);//for the last element
    return gap;
    
}
