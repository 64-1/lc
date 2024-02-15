#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *Left, TreeNode *Right) : val(x), left(Left), right(Right) {}
};

class Solution {
    public:
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> result;
            Traversal(root, result);
            return result;
        }
        void Traversal(TreeNode* root, vector<int>& vec){
            if(root == NULL) return;
            Traversal(root->left, vec);
            Traversal(root->right, vec);
            vec.push_back(root->val);
        }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    Solution s;
    vector<int> result = s.postorderTraversal(root);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
}