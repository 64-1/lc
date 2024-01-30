#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int repeat = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == val)
            {
                cout << "int i = " << i << endl;
                nums.erase(nums.begin()+i);
                --i;
                cout << nums.size() << endl;
                ++repeat;
            }
        }
        return repeat;
    }
};

int main()
{
    Solution sol;
    vector<int> input = { 0,1,2,2,3,0,4,2 };
    int output = sol.removeElement(input, 2);
    cout << output << endl;
    for (auto i : input) {
        cout << i << " ";
    }

}

