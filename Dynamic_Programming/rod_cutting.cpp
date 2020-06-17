// There is a rod of length N lying on x-axis with its left end at x = 0 and right end at x = N. Now, there are M weak points on this rod denoted by positive integer values(all less than N) A1, A2, …, AM. You have to cut rod at all these weak points. You can perform these cuts in any order. After a cut, rod gets divided into two smaller sub-rods. Cost of making a cut is the length of the sub-rod in which you are making a cut.

// Your aim is to minimise this cost. Return an array denoting the sequence in which you will make cuts. If two different sequences of cuts give same cost, return the lexicographically smallest.

// Notes:

// Sequence a1, a2 ,…, an is lexicographically smaller than b1, b2 ,…, bm, if and only if at the first i where ai and bi differ, ai < bi, or if no such i found, then n < m.
// N can be upto 109.


//function returns one of such array if multiple are possible;

#include<iostream>
#include<vector>
#include<iterator>
#include<map>
#include<climits>
#include<numeric>
#include<algorithm>
using namespace std;

pair<long long,vector<int>>helper(int s,int e,vector<int>&B,map<pair<int,int>,pair<long long,vector<int>>>&dp)
{
    if(dp.find(make_pair(s,e))!=dp.end())//if already calculated
    {
        return dp[make_pair(s,e)];
    }
    else
    {
        pair<int,int>fir=make_pair(s,e);
        long long cost=INT_MAX;
        pair<long long,vector<int>>sec=make_pair(0,vector<int>());//general pair
        pair<long long,vector<int>>left=make_pair(0,vector<int>());//left pair
        pair<long long,vector<int>>right=make_pair(0,vector<int>());//riht pair
        int ind;//the best index to cut
        for(int i=0;i<B.size();i++)
        {
            if(B[i]>s&&B[i]<e)//if the cutting point lies between the current length
            {
                int temp_cost;
                pair<long long,vector<int>>temp_left=helper(s,B[i],B,dp);
                pair<long long,vector<int>>temp_right=helper(B[i],e,B,dp);
                temp_cost=e-s+temp_left.first+temp_right.first;
                if(temp_cost<cost)//check the minimum cost and store the values accordingly
                {
                    cost=temp_cost;
                    ind=i;
                    left=temp_left;
                    right=temp_right;
                }
            }
        }
        if(cost!=INT_MAX)//this condition fails if the if state ment inside loop evaluates to true evne once i.e a cutting pount exist between the start and end point
        {
            sec.first=cost;
            sec.second.push_back(ind);
            for(auto i:left.second)
            {
                sec.second.push_back(i);
            }
            for(auto i:right.second)
            {
                sec.second.push_back(i);
            }
        }//if condition is false than return the general pair made at the begining
        dp[fir]=sec;
        return dp[fir];
    }
}


vector<int> rodCut(int A, vector<int> &B) {
    if(B.size()==0)
    {
        return vector<int>();
    }
    sort(B.begin(),B.end());
    map<pair<int,int>,pair<long long,vector<int>>>dp;
    pair<long long,vector<int>>ans=helper(0,A,B,dp);
    vector<int>ANS;
    for(auto i:ans.second)
    {
        ANS.push_back(B[i]);
    }
    return ANS;
    
}
//add main function to run

//after teh function run we can chack dp for more of such array with costs so can get teh lexicographical smller or all if we want;