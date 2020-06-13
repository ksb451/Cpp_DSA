//#include<bits/stdc++.h>//contains all
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>//for INT_MAX
#include<cstring>//for memset
using namespace std;

int dp[1001][1001];
int mincost(const vector<int>&Fill_cap,const vector<int> &Price,int capacity,int item_no)
{
    if(capacity==0)
    {
        return 0;
    }
    else if(capacity!=0&&item_no==0)
    {
        return INT_MAX/2;//this is a guess. never try to do it this wayy. i m still triyng to figure out the correct solution
    }
    if(dp[capacity][item_no]!=-1)
    {
        return dp[capacity][item_no];
    }
    else
    {
        if(Fill_cap[item_no-1]<=capacity)
        {
            dp[capacity][item_no]=min(min(Price[item_no-1]+mincost(Fill_cap,Price,capacity-Fill_cap[item_no-1],item_no),Price[item_no-1]+mincost(Fill_cap,Price,capacity-Fill_cap[item_no-1],item_no-1)),mincost(Fill_cap,Price,capacity,item_no-1));
            return dp[capacity][item_no];
        }
        else
        {
            dp[capacity][item_no]= mincost(Fill_cap,Price,capacity,item_no-1);
            return dp[capacity][item_no];
        }
    }
}

int solve(const vector<int> &A, const vector<int> &Fill_cap, const vector<int> &Price) {
    memset(dp,-1,sizeof(dp));
    int min_cost=0;
    int n=Fill_cap.size();
    for(int i=0;i<A.size();i++)
    {
        int x=mincost(Fill_cap,Price,A[i],n);
        //cout<<x<<" ";
        min_cost+=x;
    }
    return min_cost;
}

//driver function
int main()
{
    int t=1;
    cin>>t;
    while(t--)
    {
        cout<<"enter no of friends : ";
        int n;
        cin>>n;
        int d;
        vector<int>friend_cap;
        vector<int>dishes_cap;
        vector<int>dishes_price;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            friend_cap.push_back(x);
        }
        cout<<" enter no of dishes: ";
        cin>>d;
        cout<<" enter filling capacity of dishes: ";
        for(int i=0;i<d;i++)
        {
            int x;
            cin>>x;
            dishes_cap.push_back(x);
        }
        cout<<" enter price of dishes: ";
        for(int i=0;i<d;i++)
        {
            int x;
            cin>>x;
            dishes_price.push_back(x);
        }
        cout<<"min cost is "<<solve(friend_cap,dishes_cap,dishes_price);
    }
    return 0;
}