#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int startX = 0, startY = 0;
        int offSet = 1, count = 0;
        int i=0, j = 0;
        int x = n;
        vector<vector<int>> ans(n, vector<int>(n, 0));

        while (x>1)
        {
            for (j = startY; j < n - offSet; j++)
            {
                ans[startX][j] = ++count;
                cout << "coordinate = " << i << j << endl;
                cout << "count = " << count << endl;
            }
            cout << endl;

            for (i = startX; i < n - offSet; i++)
            {
                ans[i][j] = ++count;
                cout << "coordinate = " << i << j << endl;
                cout << "count = " << count << endl;
            }
            cout << endl;

            for (; j > startY; j--)
            {
                ans[i][j] = ++count;
                cout << "coordinate = " << i << j << endl;
                cout << "count = " << count << endl;
            }
            cout << endl;

            for (; i > startX; i--)
            {
                ans[i][j] = ++count;
                cout << "coordinate = " << i << j << endl;
                cout << "count = " << count << endl;
            }
            cout << endl;


            startX++;
            startY++;
            offSet++;
            x--;
        }
        if (n % 2 == 1)
        {
            int half = n / 2;
            ans[half][half] = ++count;
        }
        return ans;
    }
};

int main()
{
    int input = 3;
    Solution sol;
    vector<vector<int>> output = sol.generateMatrix(input);
    for (int i = 0; i < input; i++)
    {
        for (int j = 0; j < input; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}


