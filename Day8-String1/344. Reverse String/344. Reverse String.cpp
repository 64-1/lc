#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size()-1;
        while(left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

int main() {
    Solution sol;
    vector<char> s = {'h','e','l','l','o'};
    sol.reverseString(s);
    for(auto i : s){
        cout << i << " ";
    }
    return 0;
}