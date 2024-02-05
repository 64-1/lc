#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

/**
 * @class Solution
 * @brief Class that evaluates Reverse Polish Notation expressions.
 */
class Solution {
public:
    /**
     * @brief Evaluates the given Reverse Polish Notation expression.
     * @param tokens The vector of tokens representing the expression.
     * @return The result of the evaluation.
     */
    int evalRPN(vector<string>& tokens) {
        int i = 0;
        stack <int> res;
        while (i < tokens.size())
        {
            /* code */

            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] =="/"){
                int a = res.top();
                res.pop();
                int b = res.top();
                res.pop();
                if(tokens[i] == "+"){
                    res.push(a+b);
                }
                else if (tokens[i] == "-"){
                    res.push(b-a);
                }
                else if (tokens[i] == "*"){
                    res.push(a*b);
                }
                else if (tokens[i] == "/"){
                    res.push(b/a);
                }
            }
            else{
                res.push(stoi(tokens[i]));
            }
            i++;
        }
        return res.top();
        
    }
};

int main(){
    Solution* obj = new Solution();
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << obj->evalRPN(tokens) << endl;
    tokens = {"4", "13", "5", "/", "+"};
    cout << obj->evalRPN(tokens) << endl;
}