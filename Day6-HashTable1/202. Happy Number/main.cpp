#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        vector<int> v;
        unordered_set<int> s;
        int sum = 0;
        while(true)
        {
            sum = 0;
            for(; n > 0; n /= 10)
            {
                sum += (n % 10)*(n % 10);
            }
            if(sum == 1)
                return true;
            if(s.find(sum) != s.end())
                return false;
            s.insert(sum);
            n = sum;
        }
        return false;
    }
};

int main(){
    Solution sol;
    cout << sol.isHappy(19) << endl;
}