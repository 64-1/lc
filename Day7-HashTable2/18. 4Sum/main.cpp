#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int k=0; k < nums.size(); ++k){
            if(nums[k]>=0 && nums[k]>target)
                break;
            if(k>0 && nums[k] == nums[k-1])
                continue;
            for(int i = k+1; i<nums.size(); ++i ){
                if(nums[i] + nums[k]>target && nums[i] + nums[k] > 0)
                    break;
                if(i>k+1 && nums[i] == nums[i-1]){
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;

                while(left < right){
                    long long sum = static_cast<long long>(nums[i]+nums[k]+nums[left]+nums[right]);
                    if(sum > target){
                        right--;
                    }
                    else if(sum < target){
                        left++;
                    }
                    else{
                        vector<int> temp = {nums[k], nums[i], nums[left], nums[right]};
                        ans.push_back(temp);
                        while(left < right && nums[left] == nums[left+1])
                            left++;
                        while(left < right && nums[right] == nums[right-1])
                            right--;
                        left++;
                        right--;

                    }

                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++) {
            // 剪枝处理
            if (nums[k] > target && nums[k] >= 0) {
            	break; // 这里使用break，统一通过最后的return返回
            }
            // 对nums[k]去重
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            for (int i = k + 1; i < nums.size(); i++) {
                // 2级剪枝处理
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
                    break;
                }

                // 对nums[i]去重
                if (i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left) {
                    // nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出
                    if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target) {
                        right--;
                    // nums[k] + nums[i] + nums[left] + nums[right] < target 会溢出
                    } else if ((long) nums[k] + nums[i] + nums[left] + nums[right]  < target) {
                        left++;
                    } else {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // 对nums[left]和nums[right]去重
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;

                        // 找到答案时，双指针同时收缩
                        right--;
                        left++;
                    }
                }

            }
        }
        return result;
    }
};



int main() {
    // The main function does nothing.
    Solution sol;
    //Test case 1
    vector<int> nums1 = {-3,-2,-1,0,0,1,2,3};
    vector<vector<int>> result1 = sol.fourSum(nums1,0);
    cout << "Test case 1:\n";
    for(const auto& quadra : result1){
        for(int num : quadra){
            cout << num << " ";
        }
        cout<<endl;
    }
    return 0;
}
