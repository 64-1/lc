#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for(int i = 0; i < magazine.size(); ++i){
            if(map.find(magazine[i])==map.end()){
                map.insert({magazine[i], 1});
            }
            else
                map[magazine[i]]++;
        }

        for(int i = 0; i < ransomNote.size(); ++i){
            if(map.find(ransomNote[i]) != map.end()){
                if(map[ransomNote[i]] != 0)
                    map[ransomNote[i]]--;
                else
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};

int main(){
    Solution sol;
    string ransomNote = "a";
    string magazine = "b";
    cout << sol.canConstruct(ransomNote, magazine) << endl;
    return 0;
}