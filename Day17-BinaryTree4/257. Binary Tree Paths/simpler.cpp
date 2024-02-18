#include <iostream>
#include <vector>
#include <string>

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
    vector<string> binaryTreePaths (TreeNode* root){
        vector<string> result;
        string path;
        if(root == NULL) return result;
        traversal(root, path, result);
        return result;
    }

    void traversal(TreeNode* root, string path, vector<string>& result){
        path += to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            result.push_back(path);
            return;
        }
        if(root->left){
            traversal(root->left, path + "->", result);
        }
        if(root->right){
            traversal(root->right, path + "->", result);
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    Solution s;
    vector<string> result = s.binaryTreePaths(root);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
    return 0;
}