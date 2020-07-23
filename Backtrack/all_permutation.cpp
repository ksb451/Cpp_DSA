#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(vector<vector<int>> &ans, vector<int> temp, int start, int n, vector<int> &nums)
    {
        if (start == n - 1)
        {
            temp.push_back(nums[start]);
            ans.push_back(temp);
            return;
        }
        else
        {
            for (int i = start; i < n; i++)
            {
                temp.push_back(nums[i]);
                swap(nums[i], nums[start]);
                backtrack(ans, temp, start + 1, n, nums);
                swap(nums[i], nums[start]);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(ans, temp, 0, nums.size(), nums);
        return ans;
    }
};