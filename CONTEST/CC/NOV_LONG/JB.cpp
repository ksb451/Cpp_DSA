#include <bits/stdc++.h>
using namespace std; 


long solve(unsigned long A,unsigned long B) 
{ 
    unsigned long XX = (A - B)/2; 
    unsigned long a = 0ULL, b = 0ULL; 
    for (unsigned long i=0ULL; i<64; i++) 
    { 
        unsigned long Xi = (B & (1ULL << i)); 
        unsigned long Ai = (XX & (1ULL << i)); 
        if (Xi == 0 && Ai == 0)
        {

        }
        else if (Xi == 0 && Ai > 0) 
        { 
            a = ((1ULL << i) | a);  
            b = ((1ULL << i) | b);  
        } 
        else if (Xi > 0 && Ai == 0) 
        { 
            a = ((1ULL << i) | a);  
        }
        else{
            return 0;
        }
    }
    if(((a+b)==A) && ((a^b)==B))
        return (min(a,b)*2) + (max(a,b)*3);
    else{
        return 0;
    }
}  
  

vector<long> bitwiseEquation(vector<long>a, vector<long> b) 
{ 
    vector<long>ans;
    for(int i=0;i<a.size();i++)
    {
        ans.push_back(solve(a[i], b[i]));
    } 
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        long a,b;
        cin>>a>>b;
        solve(a,b);
    }
    return 0;
}