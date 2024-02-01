#include <iostream>
#include <string>

using namespace std;

#include <algorithm>

class Solution {
    public :
        void rightRotation(string &s, int k){
            int n = s.size();
            k %= n;
            reverse(s.begin(), s.begin() + n - k);
            reverse(s.begin() + n - k, s.end());
            reverse(s.begin(), s.end());
            cout << s << endl;
        }
};

int main() {
    Solution s;
    string str;
    int k;
    getline(cin, str);
    cin >> k;
    s.rightRotation(str, k);
    return 0;
}