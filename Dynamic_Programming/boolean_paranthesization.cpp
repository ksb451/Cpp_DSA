// Given an expression, A, with operands and operators (OR , AND , XOR), in how many ways can you evaluate the expression to true, by grouping in different ways?

// Operands are only true and false.

// Return the number of ways to evaluate the expression modulo 103 + 3.


#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

string make_key(int i,int j,bool istrue)//utility function to make unique keyy
{
    if(istrue)
    {
        return to_string(i)+"_"+to_string(j)+"_"+"T";
    }
    else
    {
        return to_string(i)+"_"+to_string(j)+"_"+"F";
    }
}

int bool_paran(string s,int i,int j,bool istrue,unordered_map<string,int>&mp)
{
    string key=make_key(i,j,istrue);
    if(i>j)//no value in expression
        return false;
    if(i==j)//if only one value
    {
        if(istrue)
        {
            return s[i]=='T';
        }
        else
        {
            return s[i]=='F';
        }
    }
    if(mp.find(key)!=mp.end())//if already calculated
    {
        return mp[key];
    }
    int ans=0;
    int lt;//left true
    int rt;//right true
    int lf;//left false
    int rf;//right false
    for(int k=i+1;k<j;k+=2)
    {
        string ltk=make_key(i,k-1,true);//left true key
        string lfk=make_key(i,k-1,false);//left false key
        string rtk=make_key(k+1,j,true);//right true key
        string rfk=make_key(k+1,j,false);//rght false key
        if(mp.find(ltk)!=mp.end())//chek if already calculated to avoid calling function
            lt=mp[ltk];
        else
            lt=bool_paran(s,i,k-1,true,mp);

        if(mp.find(lfk)!=mp.end())
            lf=mp[lfk];
        else
            lf=bool_paran(s,i,k-1,false,mp);

        if(mp.find(rtk)!=mp.end())
            rt=mp[rtk];
        else
            rt=bool_paran(s,k+1,j,true,mp);

        if(mp.find(rfk)!=mp.end())
            rf=mp[rfk];
        else
            rf=bool_paran(s,k+1,j,false,mp);
//after calculating all the four lf,lt,rt,rf
        if(s[k]=='&')
        {
            if(istrue)//to evaluate to true
            {
                ans=ans + (lt * rt);
            }
            else//to rvaluate to false
            {
                ans=ans + (lf * rt) + (lt * rf) + (lf * rf);
            }   
        }    
        else if(s[k]=='|')
        {
            if(istrue)
            {
                ans=ans + (lf * rt) + (lt * rf) + (lt * rt);        
            }
            else
            {
                ans=ans + (lf * rf);
            }
        }    
        else if(s[k]=='^')
        {
            if(istrue)
            {
                ans=ans + (lt * rf) + (lf * rt);
            }
            else
            {
                ans=ans + (lf * rf) + (lt * rt);
            }
        }
    }
    return mp[key]=ans;//store the values
}


int main()
{
    int t;
    cin>>t;
    cin.get();
    while(t--)
    {
        string s;
        cin>>s;
        cin.get();
        int n=s.length();
        unordered_map<string,int>mp;
        mp.clear();
        //map<pair<int,int>,pair<int,int>>dp;//first pair is the keyy that is i,j//second pair is false and true values;
        cout<<bool_paran(s,0,n-1,true,mp);
    }
}