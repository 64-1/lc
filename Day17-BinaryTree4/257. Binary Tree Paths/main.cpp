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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if(root == NULL) return result;
        traversal(root, path, result);
        return result;
    }

    void traversal(TreeNode* root, vector<int>& path, vector<string>& result) {
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            string sPath;
            for(int i = 0; i < path.size()-1; i++){
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size()-1]);
            result.push_back(sPath);
            return;
        }

        if(root->left){
            traversal(root->left, path, result);
            path.pop_back();
        }
        if(root->right){
            traversal(root->right, path, result);
            path.pop_back();
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