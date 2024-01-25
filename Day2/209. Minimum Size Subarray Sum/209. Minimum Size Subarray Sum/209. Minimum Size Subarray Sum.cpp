#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = 0;
        int sum = 0;
        int i,j = 0;
        for (int j = 0; j < nums.size(); ++j)
        {
            for(int i = 0; i <= j; ++i)
            { 
                sum += nums[i];
                ++length;
                if (target <= sum)
                {
                    return length;
                }
            }
            cout << "sum = " << sum << endl;
            sum = 0;
            length = 0;
        }
        return 0;
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


