#include <iostream>
#include <climits>
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
    int maxDepth = INT_MIN;
    int result=0;
    int findBottomLeftValue(TreeNode* root) {
        deepestLeft(root, 0);
        return result;
    }

    void deepestLeft(TreeNode* root, int depth){
        if(root->left==NULL && root->right==NULL){
            if(depth>maxDepth){
                maxDepth = depth;
                result = root->val;
            }
            return;
        }
        if(root->left!=NULL){
            deepestLeft(root->left, depth+1);
        }
        if(root->right!=NULL){
            deepestLeft(root->right, depth+1);
        }
        return;
    }
};

int main(){
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    Solution s;
    cout<<s.findBottomLeftValue(root);
}