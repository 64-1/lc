#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*>_children){
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> result;
        if(root!=NULL){
            q.push(root);
        }
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            while(size--){
                Node* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(!node->children.empty()){
                    for(int i = 0; i < node->children.size(); i++){
                        q.push(node->children[i]);
                    }
                }
            }
            result.push_back(level);
        }
        return result;
    }
};

int main() {
    Node* root = new Node(1);
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));
    Solution s;
    vector<vector<int>> result = s.levelOrder(root);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}