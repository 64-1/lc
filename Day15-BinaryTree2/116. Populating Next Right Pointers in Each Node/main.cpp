#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root!=NULL){
            q.push(root);
        }
        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node* node = q.front();
                q.pop();
                if(size!=0){
                    node->next = q.front();
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right)
                    q.push(node->right);
            }
        }
        return root;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Solution s;
    Node* result = s.connect(root);
    for(Node* node = result; node!=NULL; node = node->left){
        for(Node* n = node; n!=NULL; n = n->next){
            cout << n->val << " ";
        }
        cout << "#";
        cout << endl;
    }
    return 0;
}