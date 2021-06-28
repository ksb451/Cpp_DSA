//**sn0wrus**//
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class MovieRentingSystem {
    private:
    struct cmp1{
        bool operator()(const vector<int>&a, const vector<int>&b)
        {
            if(a[0] < b[0]){
                return true;
            }
            else if(a[0]==b[0])
            {
                if(a[1] < b[1])
                {
                    return true;
                }
            }
            return false;
        }
    };
    
    struct cmp2{
        bool operator()(const vector<int>&a, const vector<int>&b)
        {
            if(a[0] < b[0]){
                return true;
            }
            else if(a[0]==b[0])
            {
                if(a[1] < b[1])
                {
                    return true;
                }
                else if(a[1]==b[1])
                {
                    if(a[2]<b[2])
                    {
                        return true;
                    }
                }
            }
            return false;
        }
    };
    
    
    int shop_cnt;
    vector<unordered_map<int,int>>movie_list;
    unordered_map<int, set< vector<int>, cmp1 > >movie_price;
    
    multiset<vector<int>,cmp2>sale;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        shop_cnt=n;
        movie_list.resize(n+1);
        for(auto i:entries)
        {
            movie_list[i[0]][i[1]] = i[2];
            vector<int>temp(2);
            temp[0]=i[2];
            temp[1]=i[0];
            movie_price[i[1]].insert({i[2],i[0]});
        }
    }
    
    vector<int> search(int movie) {
        vector<int>ans;
        int x=0;
        for(auto i:movie_price[movie])
        {
            ans.push_back(i[1]);
            x++;
            if(x>=5)
            {
                break;
            }
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        movie_price[movie].erase({movie_list[shop][movie], shop});
        sale.insert({movie_list[shop][movie], shop, movie});
    }
    
    void drop(int shop, int movie) {
        movie_price[movie].insert({movie_list[shop][movie], shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>>ans;
        int x=0;
        for(auto i:sale)
        {
            ans.push_back({i[1],i[2]});
            x++;
            if(x>=5)
            {
                break;
            }
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */