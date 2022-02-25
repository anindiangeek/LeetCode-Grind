/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     bool isValid(TreeNode * root, TreeNode* root2)
    {
        // both are null
        if(!root && !root2) return true;
        
        else if(!root or !root2) return false;
        
        else if(root->val!=root2->val) return false;
        
        return isValid(root->left,root2->right) && isValid(root->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        
        return isValid(root,root);
    }
   
};