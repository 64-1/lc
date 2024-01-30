#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map <int, int> map;
        for(int i = 0; i < nums.size(); ++i){
            if(map.find(target - nums[i]) != map.end()){
                result.push_back(map[target - nums[i]]);
                result.push_back(i);
            }
            else
                map.insert({nums[i], i});
        }
        return result;
    } // Add a semicolon here
};

int main(){
    Solution sol;
    vector<int> input = {2,7,11,15};
    vector<int> result = sol.twoSum(input, 9);

    cout << "result = " << endl;

    for(auto i : result){
        cout<<i<<" ";
    }
}
