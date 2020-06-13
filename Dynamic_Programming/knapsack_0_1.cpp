#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>>dp(1001,vector<int>(1001,-1));//a storege table with maximum of 1000 items and 1000 capacity .//with capacity in the ith line and item no in jth line. 
//basic knapsack recursion function
int knapsack_recur(vector<int>&Weight,vector<int>Value,int capacity, int item_no)
{
    if(capacity==0||item_no==0)
    {
        return 0;
    }
    if(Weight[item_no]<=capacity)
    {
        return max(Value[item_no-1]+knapsack_recur(Weight,Value,capacity-Weight[item_no-1],item_no-1),knapsack_recur(Weight,Value,capacity,item_no-1));
    }
    else
    {
        return knapsack_recur(Weight,Value,capacity,item_no-1);
    }
}
//knapsack_recursion function with memoisation Top-down
int knapsack_recur_dp(vector<int>&Weight,vector<int>Value,int capacity, int item_no)
{
    if(capacity==0||item_no==0)//base casee
    {
        return 0;
    }
    if(dp[capacity][item_no]!=-1)//if value is already calculated than
    {
        return dp[capacity][item_no];//retun the value no need to iterate agaain
    }
    else//if not calculated
    {
        if(Weight[item_no]<=capacity)//if the item can be included we have two choice to consider it or nott so we consider the max value we can get by both the ways
        {
            dp[capacity][item_no]=max(Value[item_no-1]+knapsack_recur(Weight,Value,capacity-Weight[item_no-1],item_no-1),knapsack_recur(Weight,Value,capacity,item_no-1));
            return dp[capacity][item_no];//we first store the values than return it
        }
        else//if the item can not be included we have only one choice
        {
            dp[capacity][item_no]=knapsack_recur(Weight,Value,capacity,item_no-1);
            return dp[capacity][item_no];
        }
    }
}

//iterative dp function Bottom up

int iterative_knapsack(vector<int>&Weight,vector<int>Value,int capacity)
{
    //initialisation
    int n=Weight.size();   
    for(int i=0;i<=capacity;i++)
        for(int j=0;j<n+1;j++)
            if(i==0||j==0)
                dp[i][0]=0;
    //dp
    for(int i=1;i<=capacity;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(Weight[j-1]<=i)
            {
                dp[i][j]=max(Value[j-i]+dp[i-Weight[j-i]][j-1],dp[i][j-1]);
            }
            else
            {
                dp[i][j]=dp[i][j-1];
            }
        }
    }
    return dp[capacity][n];
}