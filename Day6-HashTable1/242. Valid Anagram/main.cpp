#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        vector<int> count(26, 0);

        //if the alphabet exist in string s, increment the count
        for(int i = 0; i < s.size(); i++) 
        {
            count[s[i] - 'a']++;
        }

        //if the alphabet exist in string t, decrement the count
        for (int i = 0; i < t.size(); i++)
        {
            count[t[i] - 'a']--;
        }

        //check if the count is 0, if not return false
        for(int i = 0; i < 26; i++) 
        {
            if(count[i] != 0) 
            {
                return false;
            }
        }
        return true;
    }
};

int main() {
    // Your code here
    Solution s;
    string s1 = "anagram";
    string s2 = "nagaram";
    cout << s.isAnagram(s1, s2) << endl;

    return 0;
}
