#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode () : val(0), left(NULL), right(NULL) {}
    TreeNode (int x) : val(x), left(NULL), right(NULL) {}
    TreeNode (int x, TreeNode* Left, TreeNode* Right) : val(x), left(Left), right(Right) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> result;
        if(root!=NULL)
            q.push(root);
        while(!q.empty()){
            double size = q.size();
            double sum = 0;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            double avg = sum / size;
            result.push_back(avg);
        }
        return result;
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution s;
    vector<double> ans = s.averageOfLevels(root);
    for(int i = 0; i < ans.size(); i ++){
        cout<<ans[i]<<" ";
    }
}