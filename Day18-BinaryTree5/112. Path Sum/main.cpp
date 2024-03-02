#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* constructTree(const vector<int>& values, int index) {
    if (index >= values.size() || values[index] == -1) {
        return nullptr;
    }
        
    TreeNode* root = new TreeNode(values[index]);
    root->left = constructTree(values, 2 * index + 1);
    root->right = constructTree(values, 2 * index + 2);
        
    return root;
}

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        return traversal(root, targetSum);
    }

    bool traversal(TreeNode* root, int targetSum){
        if(root->left == NULL && root->right == NULL && targetSum == 0) {
            return true;
        }
        if(root->left == NULL && root->right == NULL) {
            return false;
        }
        if(root->left){
            if(hasPathSum(root->left, targetSum - root->left->val)){
                return true;
            }
        }
        if(root->right){
            if(hasPathSum(root->right, targetSum - root->right->val)){
                return true;
            }
        }
        return false;
    }
};

int main(){
    // Usage:
    vector<int> treeValues = {5, 4, 8, 11, 7, 2, 13, -1, -1, -1, -1, -1, -1, 4, 1};
    TreeNode* root = constructTree(treeValues, 0);
    Solution s;
    cout << s.hasPathSum(root, 22);
    return 0;
}