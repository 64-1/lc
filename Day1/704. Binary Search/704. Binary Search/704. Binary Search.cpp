#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        return search(0, nums.size()-1, target, nums);
    }

    int search(int left, int right, int target, vector<int>& nums)
    {
        if (left > right)
            return -1;

        int median = (right + left) / 2;
        if (target == nums[median])
        {
            return median;
        }

        if (target < nums[median])
        {
            return search(left, median-1, target, nums);
        }
        else
        {
            return search(median+1, right, target, nums);
        }
    }
};



int main()
{
    Solution sol;
    vector<int> nums = { -1,0,3,5,9,12 };
    int target = 9;
    int ans = sol.search(nums, target);
    cout << ans << endl;
}

