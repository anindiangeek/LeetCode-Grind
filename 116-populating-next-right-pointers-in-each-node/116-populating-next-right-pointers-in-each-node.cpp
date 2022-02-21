/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node * Step1(Node * root)
    {
        if(!root) return nullptr;
        if(root->left) root->left->next=root->right;
        if(root->right) root->right->next=nullptr;
        connect(root->left);
        connect(root->right);
        return root;
    }
    Node* connect(Node* root) {
        if(!root) return nullptr;
        root=Step1(root);
        Node * first=root->left,*second=root->right;
        while(first && second)
        {
            first=first->right;
            second=second->left;
            if(first && second)
            first->next=second;
        }
        return root;
    }
};