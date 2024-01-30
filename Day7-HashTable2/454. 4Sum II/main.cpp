#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map <int, int> map;
        int count = 0;
        for(int i = 0; i < nums1.size(); ++i){
            for(int j = 0; j < nums2.size(); ++j){
                int sum = nums1[i] + nums2[j];
                if(map.find(sum) != map.end()){
                    map[sum]++;
                }
                else
                    map.insert({sum, 1});
            }
        }

        for(int i = 0; i < nums3.size(); ++i){
            for(int j = 0; j < nums4.size(); ++j){
                int sum = 0 - (nums3[i] + nums4[j]);
                if(map.find(sum) != map.end()){
                    count += map[sum];
                }
            }
        }

        return count;
    
    }

};


int main(){
    Solution sol;
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {-2,-1};
    vector<int> nums3 = {-1,2};
    vector<int> nums4 = {0,2};
    int ans = sol.fourSumCount(nums1,nums2,nums3,nums4);
    cout << ans << endl;

    return 0;
}