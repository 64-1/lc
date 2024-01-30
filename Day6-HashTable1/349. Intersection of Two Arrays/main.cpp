#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> res;
        for (int i = 0; i < nums2.size(); ++i)
        {
            if (s1.find(nums2[i]) != s1.end())
            {
                res.insert(nums2[i]);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};

int main() {
    // Create two input vectors
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    // Create an instance of the Solution class
    Solution solution;

    // Call the intersection function and store the result
    vector<int> result = solution.intersection(nums1, nums2);

    // Print the elements in the result vector
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
