#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* Left, TreeNode* Right) : val(x), left(Left), right(Right) {}
};

class Solution {
    public:
        vector<int> postorderTraversal(TreeNode* root){

                        vector<int> result;
                        stack<TreeNode*> s;
                        s.push(root);
                        while(!s.empty()){
                            TreeNode* node = s.top();
                            s.pop();
                            if(node!=nullptr){
                                result.push_back(node->val);
                                s.push(node->left);
                                s.push(node->right);
                            }
                        }
                        reverse(result.begin(), result.end());
            return result;
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