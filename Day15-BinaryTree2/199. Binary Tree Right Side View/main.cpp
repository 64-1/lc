#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* Left, TreeNode* Right) : val(x), left(Left), right(Right) {}
};

class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
            queue<TreeNode*> q;
            vector<int> result;
            if(root!=NULL){
                q.push(root);
            }
            while(!q.empty()){
                int size = q.size();
                vector<int> level;
                while(size--){
                    TreeNode* node = q.front();
                    q.pop();
                    level.push_back(node->val);
                    if(node->right){
                        q.push(node->right);
                    }
                    if(node->left){
                        q.push(node->left);
                    }
                }
                int ans = level.front();
                result.push_back(ans);
            }
            return result;
        }      
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    Solution s;
    vector<int> result = s.rightSideView(root);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}