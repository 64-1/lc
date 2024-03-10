#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};

void preOrder(TreeNode* root){
    if(root == nullptr) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }else{
            if(root->left == nullptr){
                return root->right;
            }else if(root->right == nullptr){
                return root->left;
            }else{
                TreeNode* minNode = getMin(root->right);
                root->val = minNode->val;
                root->right = deleteNode(root->right, minNode->val);
            }
        }
        return root;
    }

    TreeNode* getMin(TreeNode* node){
        while(node->left != nullptr){
            node = node->left;
        }
        return node;
    }
    TreeNode* successor(TreeNode* root){
        root = root->right;
        while(root->left != nullptr){
            root = root->left;
        }
        return root;
    }
    
};

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    Solution s;
    TreeNode* res = s.deleteNode(root, 3);
    preOrder(res);
    return 0;
}