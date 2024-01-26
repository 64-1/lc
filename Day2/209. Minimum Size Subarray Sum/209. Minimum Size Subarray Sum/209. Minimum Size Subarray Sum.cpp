#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int i = 0;
        int result = INT_MAX;
        int sum = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while (sum >= target)
            {
                int length = j - i + 1;
                result = min(result, length);
                sum -= nums[i];
                i++;
            }
        }
        if (result == INT_MAX)
        {
            return 0;
        }
        return result;
    }
};

int main()
{
    vector<int> input = { 2,3,1,2,4,3 };
    int target = 7;
    Solution sol;
    int ans = sol.minSubArrayLen(target,input);
    cout << ans;
}


