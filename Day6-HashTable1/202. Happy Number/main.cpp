#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

/**
 * @class Solution
 * @brief Class that determines if a number is happy.
 */
class Solution {
public:
    /**
     * @brief Checks if a number is happy.
     * @param n The number to check.
     * @return True if the number is happy, false otherwise.
     */
    bool isHappy(int n) {
        vector<int> v; // Create a vector to store intermediate results
        unordered_set<int> s; // Create an unordered set to store seen numbers
        int sum = 0; // Initialize the sum variable

        while(true) // Start an infinite loop
        {
            sum = 0; // Reset the sum to 0
            for(; n > 0; n /= 10) // Iterate through each digit of the number
            {
                sum += (n % 10)*(n % 10); // Add the square of the current digit to the sum
            }

            if(sum == 1) // If the sum is 1, the number is happy
                return true;

            if(s.find(sum) != s.end()) // If the sum is already in the set, it's in a cycle and not happy
                return false;

            s.insert(sum); // Insert the sum into the set
            n = sum; // Update the number to be the sum for the next iteration
        }

        return false; // This line is unreachable, added for completeness
    }
};

int main(){
    Solution sol;
    cout << sol.isHappy(19) << endl;
}