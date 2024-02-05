#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief A data structure that maintains the maximum value within a sliding window.
 * 
 * This data structure, named controlNet, is designed to keep track of the maximum value within a sliding window.
 * It stores the maximum value and maintains a storage vector that holds the elements within the window.
 * The push() function is used to add elements to the storage vector, while the pop() function removes elements from the vector.
 * The max() function returns the maximum value within the window.
 */
struct controlNet{
    vector<int> storage; /**< The storage vector that holds the elements within the sliding window. */

    /**
     * @brief Constructs a controlNet object.
     */
    controlNet(): storage{} {};

    /**
     * @brief Adds an element to the storage vector, maintaining the maximum value within the window.
     * 
     * This function adds the given value to the storage vector, while ensuring that the maximum value within the window is maintained.
     * It removes any elements from the storage vector that are smaller than the given value.
     * 
     * @param v The value to be added to the storage vector.
     */
    void push(int v){
        while(!storage.empty() && storage.back() < v){
            storage.pop_back();
        }
        storage.push_back(v);
    }

    /**
     * @brief Removes an element from the storage vector.
     * 
     * This function removes the given value from the storage vector.
     * If the value to be removed is the first element in the storage vector, it is erased from the vector.
     * 
     * @param v The value to be removed from the storage vector.
     */
    void pop(int v){
        if(storage.front() == v){
            storage.erase(storage.begin());
        }
    }

    /**
     * @brief Returns the maximum value within the sliding window.
     * 
     * This function returns the maximum value within the sliding window, which is stored in the storage vector.
     * 
     * @return The maximum value within the sliding window.
     */
    int max(){
        return storage.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        controlNet control; // Declare an instance of the controlNet struct
        vector<int> result; // Create a vector to store the maximum values within the sliding window
        for(int i = 0; i < nums.size(); i++){ // Iterate through the input vector
            control.push(nums[i]); // Add the current element to the controlNet storage vector
            if(i >= k - 1){ // If the window size is reached
                result.push_back(control.max()); // Add the maximum value within the window to the result vector
                control.pop(nums[i - k + 1]); // Remove the first element of the window from the controlNet storage vector
            }
        }
        return result; // Return the vector containing the maximum values within the sliding window
        }
};



int main(){
    Solution s;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> result = s.maxSlidingWindow(nums, k);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
