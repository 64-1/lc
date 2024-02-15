#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        Traversal(root, result);
        return result;
    }

    void Traversal(TreeNode* root, vector<int>& res){
        if(root == NULL){
            return; 
        }
        res.push_back(root->val);
        Traversal(root->left, res);
        Traversal(root->right, res);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    Solution s;
    vector<int> result = s.preorderTraversal(root);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}