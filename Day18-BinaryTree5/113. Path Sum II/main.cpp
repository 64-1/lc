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

void printTree(TreeNode* node, int level = 0) {
    if (node == nullptr) {
        return;
    }
    printTree(node->right, level + 1);
    cout << string(level * 4, ' ') << node->val << "\n";
    printTree(node->left, level + 1);
}

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        traversal(root, targetSum, path, result);
        return result;
    }
    void traversal(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& result){
        if(root == NULL) return;
        path.push_back(root->val);
        targetSum -= root->val;
        if(root->left == NULL && root->right == NULL && targetSum == 0) {
            result.push_back(path);
        }
        if(root->left){
            traversal(root->left, targetSum, path, result);
        }
        if(root->right){
            traversal(root->right, targetSum, path, result);
        }
        path.pop_back();
    }
};

int main() {
    // Corrected tree values for the intended structure:
    vector<int> treeValues = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, 5,  1};
    TreeNode* root = constructTree(treeValues, 0);

    // Debug: Print the tree to verify its structure
    cout << "Constructed binary tree:" << endl;
    printTree(root);

    Solution s;
    int targetSum = 22;
    cout << "Paths that sum to " << targetSum << ":" << endl;
    vector<vector<int>> result = s.pathSum(root, targetSum);

    if (result.empty()) {
        cout << "No paths found with sum " << targetSum << endl;
    } else {
        for (auto& path : result) {
            for (int val : path) {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
