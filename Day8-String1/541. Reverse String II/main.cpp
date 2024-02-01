#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        if(k>=s.size()) 
            return reverse(s, 0, s.size()-1);
        int left = 0;
        int right = k - 1;
        while(right < s.size()) {
            s = reverse(s, left, right);
            left += 2*k;
            right += 2*k;
        }
        if(left < s.size()) {
            s = reverse(s, left, s.size()-1);
        }
        return s; // Add this line to return the modified string
    }

    string reverse(string s, int left, int right) {
        while(left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};

int main() {
    Solution s;
    string str = "abcdefg";
    cout << s.reverseStr(str, 2) << endl;
    return 0;
}