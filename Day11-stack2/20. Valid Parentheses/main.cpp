#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> res;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                res.push(s[i]);
            }else{
                if(res.empty()){
                    return false;
                }
                if(s[i] == ')' && res.top() != '('){
                    return false;
                }
                if(s[i] == ']' && res.top() != '['){
                    return false;
                }
                if(s[i] == '}' && res.top() != '{'){
                    return false;
                }
                res.pop();
            }
                
        }
        return res.empty();
    }
};

int main(){
    Solution* obj = new Solution();
    cout << obj->isValid("()") << endl;
    cout << obj->isValid("()[]{}") << endl;
    cout << obj->isValid("(]") << endl;
    cout << obj->isValid("([)]") << endl;
    cout << obj->isValid("{[]}") << endl;
    return 0;
}   