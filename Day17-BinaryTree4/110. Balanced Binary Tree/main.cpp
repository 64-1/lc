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
    /**
     * Determines whether a binary tree is balanced.
     * A binary tree is balanced if the heights of the two subtrees of any node never differ by more than 1.
     *
     * @param root The root of the binary tree.
     * @return True if the binary tree is balanced, false otherwise.
     */
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int left = height(root->left);
        int right = height(root->right);
        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
    
    /**
     * Calculates the height of a binary tree.
     *
     * @param root The root of the binary tree.
     * @return The height of the binary tree.
     */
    int height(TreeNode* root) {
        if(root == NULL) return 0;
        int left = height(root->left);
        int right = height(root->right);
        return max(left, right) + 1;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution s;
    cout << s.isBalanced(root) << endl;
    return 0;
}