#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void printInOrder(TreeNode* root)
{
    if (root != NULL){
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
    }
}

void printPreOrder(TreeNode* root)
{
    if (root != NULL){
    cout << root->val << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
    }
}

void printPostOrder(TreeNode* root)
{
    if (root != NULL){
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->val << " ";
    }
}


class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        if(val < root->val){
            root->left = insertIntoBST(root->left, val);
        }else{
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

int main() {
    // Step 1: Create an initial BST
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    // Step 2: Insert a new value into the BST
    int val = 5;
    Solution sol;
    sol.insertIntoBST(root, val);

    // Step 3: Traverse and print the updated BST (In-order for a sorted output)
    cout << "Updated BST (In-order): ";
    printInOrder(root);
    cout << endl;

    return 0;
}