#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void replaceNum(string &s){
        int i = 0;
        while(i<s.size()){
            if('0' <= s[i] && s[i] <= '9'){
                s.replace(i, 1, "number");
            }
            else
                i++;
        }
        cout << s << endl;
    }
};  

int main() {
    Solution s;
    string str;
    getline(cin, str);
    s.replaceNum(str);
    return 0;
}