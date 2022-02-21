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
    int ans=0;
    public:
    int h(TreeNode * root)
    {
             if(!root) return 0;
        int LeftHeight=h(root->left);
        int RightHeight=h(root->right);
        ans=max(ans,LeftHeight+RightHeight);
        return 1 + max(LeftHeight, RightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        h(root);
        return ans;
    }
};