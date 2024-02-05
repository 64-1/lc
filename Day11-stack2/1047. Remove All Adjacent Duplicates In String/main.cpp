#include <iostream>
#include <stack>

using namespace std;

/**
 * @class Solution
 * @brief Class that provides a solution to remove all adjacent duplicates in a string.
 */
class Solution {
public:
    /**
     * @brief Removes all adjacent duplicates in the given string.
     * @param s The input string.
     * @return The string with all adjacent duplicates removed.
     */
    string removeDuplicates(string s) {
        stack<char> res; // Create a stack to store characters
        for(int i = 0; i < s.size(); i++){ // Iterate through each character in the input string
            if(res.empty() || res.top() != s[i]){ // If the stack is empty or the top of the stack is not equal to the current character
                res.push(s[i]); // Push the current character onto the stack
            }else{ // If the top of the stack is equal to the current character
                res.pop(); // Pop the top of the stack (remove the adjacent duplicate)
            }
        }

        string result = ""; // Create an empty string to store the result
        while(!res.empty()){ // While the stack is not empty
            result = res.top() + result; // Append the top of the stack to the beginning of the result string
            res.pop(); // Pop the top of the stack
        }
        return result; // Return the final result string
    }
};

int main(){
    Solution* obj = new Solution();
    cout << obj->removeDuplicates("abbaca") << endl;
    return 0;
}