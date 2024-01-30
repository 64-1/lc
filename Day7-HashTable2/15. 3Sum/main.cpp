#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i]>0)
                return ans;
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right){
                int sum = nums[i]+nums[left]+nums[right];
                if(sum > 0){
                    right--;
                }
                else if(sum < 0){
                    left++;
                }
                else{
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    ans.push_back(temp);
                    while(left < right && nums[left] == temp[1])
                        left++;
                    while(left < right && nums[right] == temp[2])
                        right--;
                }

            }
        }
        return ans;        
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result1 = sol.threeSum(nums1);
    cout << "Test case 1:\n";
    for (const auto& triplet : result1) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    // Test case 2
    vector<int> nums2 = {0, 0, 0};
    vector<vector<int>> result2 = sol.threeSum(nums2);
    cout << "Test case 2:\n";
    for (const auto& triplet : result2) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    // Add more test cases here...

    return 0;
}