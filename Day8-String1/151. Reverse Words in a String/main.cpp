#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

class Solution {
public:
    string trim(const string s){
        //find_first_not_of function is used to find the index of the first character in the string that is not one of the specified whitespace characters 
        size_t start = s.find_first_not_of(" \t\n\r\f\v");
        //find_last_not_of function is used to find the index of the last character in the string that is not one of the specified whitespace characters
        size_t end = s.find_last_not_of(" \t\n\r\f\v");

        //npos is a static member constant value with the greatest possible value for an element of type size_t.
        if(start == string::npos) 
            return "";
        
        return s.substr(start, end-start+1);
    }

    string reverseWords(string s) {
        s = trim(s);
        if(s.empty()) 
            return s;
        
        vector<string> words;
        int i = 0;
        while(i<s.size()){
            int j = i;
            if(!isspace(s[i])){
                while(j<s.size() && !isspace(s[j])){
                    j++;
                }
                words.push_back(s.substr(i, j-i));
            }
            i = j+1;
        }
        string res = "";
        for(int i=words.size()-1; i>=0; --i){
            res += words[i];
            if(i>0) 
                res += " ";
        }
        return res;
    }
};

int main(){
    Solution s;
    string str = "  the sky is blue  ";
    cout << s.reverseWords(str) << endl;
    return 0;
}