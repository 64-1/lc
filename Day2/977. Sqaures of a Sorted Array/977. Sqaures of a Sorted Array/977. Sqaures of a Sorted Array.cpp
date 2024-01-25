#include <iostream>
#include <vector>

using namespace std;

    class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            int h = 0;
            int j = nums.size() -1;
            int l = nums.size();
            vector<int> result (l);
            int k = nums.size() - 1;
            for (int i = 0; i < nums.size(); ++i)
            {
                nums[i] *= nums[i];
            }

            while (h <= j) {
                if (nums[h] <= nums[j])
                {
                    result[k] = nums[j];
                    --k;
                    --j;
                }
                else
                {
                    result[k] = nums[h];
                    --k;
                    ++h;
                }
                
            }
            return result;
        }
    };

int main()
{
    Solution sol;
    vector<int> input = { -7,-3,2,3,11 };
    vector<int> result;
    result = sol.sortedSquares(input);
    for (int i : result) {
        cout << i << " ";
    }
}

