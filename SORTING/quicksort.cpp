
#include <bits/stdc++.h>
using namespace std;

void quicksort(vector<int> &nums, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int pivot = nums[left + (right - left) / 2];
    int ind = partition(nums, left, right, pivot);
    quicksort(nums, left, ind - 1);
    quicksort(nums, ind, right);
}
int partition(vector<int> &nums, int left, int right, int pivot)
{
    while (left <= right)
    {
        while (nums[left] < pivot)
        {
            left++;
        }
        while (nums[right] > pivot)
        {
            right--;
        }
        if (left <= right)
        {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }
    return left;
}
vector<int> sortArray(vector<int> &nums)
{
    int n = nums.size();
    quicksort(nums, 0, n - 1);
    return nums;
}
