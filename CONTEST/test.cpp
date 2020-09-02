#include <bits/stdc++.h>
using namespace std;
// 2 5 6 7
/*
exiting 1	 csum 3
exiting 1	 csum 2
exiting 1	 csum 1
exiting 1	 csum 0
Empty
*/
void count(set<vector<int >> &st, vector<int > &v , int sum ,int csum,int n,vector<int > a,int i){
    //if(csum>4){return;}
    if(csum > sum || i>=n){
         return;
    }
    if(csum == sum ){
        st.insert(v);
        //v.clear();
        return;
    }
    else{
        int j=i;
        //for(int j=i ; j<n; j++){
        if(a[j]+csum>sum){
            return;
        }
        else{
        v.push_back(a[j]);
       // cout<<"entering "<<a[j]<<"\t";
        //csum=csum+a[j];
        count(st,v,sum,csum+a[j],n,a,j);
       // cout<<"exiting "<<a[j]<<"\t";
        v.pop_back();
        count(st,v,sum,csum,n,a,j+1);
        
        }
        
        //}
        return;
    }
}
vector<int > remdup(int a[] , int n){
    vector<int > b ;
    b.push_back(a[0]);
    for(int i=1,j=1 ;i<n ; i++,j++){
        while(a[i]==a[i-1]){
           i++; 
        }
        b.push_back(a[i]);
    }
    return b;
}
int main() {
	//code
	int t;
	cin>>t; 
	while(t--){
	    int n;
	    cin>>n; 
	    int a[n];
	    for(int i =0 ;i< n ;i++){
	        cin>>a[i];
	    }
	    int sum ;
	     cin>>sum;
	    sort(a,a+n);
	    vector<int > b;
	    b=remdup(a,n);
	    n = b.size();
	   
	    set<vector<int > > st;
	    vector<int > v;
	    count(st,v,sum,0,n,b,0);
	    for(auto it = st.begin(); it!=st.end(); it++){
	        vector<int > x = *it;
	        int i;
	        cout<<"(";
	        for(i =0 ;i< x.size()-1; i++){
	            cout<<x[i]<<" ";
	        }
	        cout<<x[i]<<")";
	        
	    }
	    if(st.size()==0){
	        cout<<"Empty";
	    }
	    cout<<endl;
	        
	}
	return 0;
}