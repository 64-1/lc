#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        return summation(root, sum);
    }

    int summation(TreeNode* root, int sum){
        if(root == NULL){
            return sum;
        }
        if(root->left != NULL && root->left->left == NULL && root->left->right == NULL){
            sum += root->left->val;
        }
        sum = summation(root->left, sum);
        sum = summation(root->right, sum);
        return sum;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    cout << s.sumOfLeftLeaves(root) << endl;
    return 0;
}