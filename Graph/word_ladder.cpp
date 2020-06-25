#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<iterator>
#include<queue>
using namespace std;


void formans(unordered_map<string,unordered_set<string>>&parent,vector<vector<string>>&ans,vector<string>temp,string start)
{
    string t=*(temp.end()-1);
    if(t==start)
    {
        reverse(temp.begin(),temp.end());//because it is formed in recursive order.
        ans.push_back(temp);
        return;
    }
    for(auto i:parent[t])
    {
        temp.push_back(i);
        formans(parent,ans,temp,start);
        temp.erase(temp.end()-1);
    }
}

vector<vector<string> > findLadders(string A, string B, vector<string> &C) {
    vector<vector<string>>ans;
    unordered_map<string,int>dict;
    for(auto i:C)
    {
        //cout<<i<<" ";
        dict[i]=-1;
    }
    dict[A]=1;
    queue<string>Q;
    Q.push(A);
    unordered_map<string,unordered_set<string>>parent;//set is used to prevent duplicate value and unorder for better time complexity
    while(Q.empty()==false)
    {
        string curr=Q.front();
        Q.pop();
        for(int i=0;i<curr.length();i++)
        {
            string temp=curr;
            for(char j='a';j<='z';j++)
            {
                temp[i]=j;
                if((dict.find(temp)!=dict.end())&&((dict[temp]==-1)||dict[temp]==dict[curr]+1))//the last condition is to consider multiple ladder of same length
                {
                    Q.push(temp);
                    parent[temp].insert(curr);
                    dict[temp]=dict[curr]+1;
                    //cout<<temp<<" "<<dict[temp]<<" ";
                }
            }
        }
    }
    //return dict[B];//for the length of smallest ladder
    vector<string>temp;
    temp.push_back(B);
    formans(parent,ans,temp,A);//function to form the ladder
    return ans;
}
