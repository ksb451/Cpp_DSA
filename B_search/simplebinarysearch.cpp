#include<iostream>
#include<vector>

using namespace std;

int Bsearch(vector<int>&A, int B)
{
    int start=0;
    int end=A.size();
    while(start<end)
    {
        int mid= start+ (end-start)/2;
        if(A[mid]==B)
        {
            return mid;
        }
        else if(A[mid]<B)
        {
            start=mid+1;
        }
        else if(A[mid]>B)
        {
            end=mid-1;
        }
    }
    return -1;
}