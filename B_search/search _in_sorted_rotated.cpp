#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int find_pivot(vector<int>&nums)
    {
        int start=0;
        int N=nums.size();
        int end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int prev=(mid+N-1)%N;
            int next=(mid+1)%N;
            if(nums[mid]<=nums[prev]&&nums[mid]<=nums[next])
            {
                return mid;
            }
            else if(nums[mid]<nums[end]|| mid ==end)
            {
                end=prev;
            }
            else if(nums[mid]>nums[start]|| mid==start)
            {
                start=next;
            }
        }
        return -1;
        
    }
    int search(int start,int end,int x,vector<int>&nums)
    {
        if(start<0 || end <0)
            return -1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==x)
            {
                return mid;
            }
            else if(nums[mid]<x)
            {
                start=mid+1;
            }
            else if(nums[mid]>x)
            {
                end=mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot=find_pivot(nums);
        int r1=search(0,pivot-1,target,nums);
        int r2=search(pivot,nums.size()-1,target,nums);
        if(r1==-1 && r2 ==-1)
        {
            return -1;
        }
        else if(r1!= -1)
            return r1;
        return r2;
        
    }
};


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right =  nums.size()-1, mid;
        
        while(left<=right)
        {
            mid = (left + right) >> 1;
            if(nums[mid] == target) return true;

            // the only difference from the first one, trickly case, just updat left and right
            if( (nums[left] == nums[mid]) && (nums[right] == nums[mid]) ) {++left; --right;}

            else if(nums[left] <= nums[mid])
            {
                if( (nums[left]<=target) && (nums[mid] > target) ) right = mid-1;
                else left = mid + 1; 
            }
            else
            {
                if((nums[mid] < target) &&  (nums[right] >= target) ) left = mid+1;
                else right = mid-1;
            }
        }
        return false;
    }
};