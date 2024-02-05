#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
struct controlNet{
    unordered_map<int, int> storage;

    void push(int v){
        storage[v] ++;
    }
    void pop(int v){
        storage.erase(v);
    }
    int max(){ // Define a member function "max" that returns an integer
        int max = 0; // Initialize a variable "max" with value 0
        int maxKey = 0; // Initialize a variable "maxKey" with value 0
        for(auto it = storage.begin(); it != storage.end(); it++){ // Iterate over the elements in the "storage" unordered_map
            if(it->second > max){ // Check if the current element's value is greater than the current maximum
                max = it->second; // Update the maximum value
                maxKey = it->first; // Update the key corresponding to the maximum value
            }
        }
        return maxKey; // Return the key with the maximum value
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        controlNet control;
        int freq = 0;
        for(int i = 0; i < nums.size(); i++){
            control.push(nums[i]);
        }
        vector<int> result;
        for(int i = 0; i < k; i++){
            result.push_back(control.max());
            control.pop(control.max());
        }
        return result;
    }
};



int main(){
    Solution s;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> result = s.topKFrequent(nums, k);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}