#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* Left, TreeNode* Right) : val(x), left(Left), right(Right) {}
};

class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> result;
            stack<TreeNode*> s;
            TreeNode* cur = root;
            while(cur!=NULL || !s.empty()){
                if(cur!=NULL){
                    s.push(cur);
                    cur = cur->left;
                }
                else{
                    cur = s.top();
                    s.pop();
                    result.push_back(cur->val);
                    cur = cur->right;
                }

            }
            return result;
        }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    Solution s;
    vector<int> result = s.inorderTraversal(root);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}