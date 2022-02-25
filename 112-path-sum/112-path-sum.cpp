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
     bool dfs(TreeNode *root,int S,int cs)
    {
        if(!root) return false;
        
        cs+=root->val;
        // is leaf node & sum matches
        if(!root->left && !root->right)
            return cs==S;
        
        return dfs(root->left,S,cs) or dfs(root->right,S,cs);
    }
    bool hasPathSum(TreeNode *root, int S) 
    {
        return dfs(root,S,0);
    }
};