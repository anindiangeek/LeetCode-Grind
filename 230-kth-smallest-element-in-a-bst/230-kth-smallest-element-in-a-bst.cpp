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
    int kthSmallest(TreeNode* root, int k) 
    {
        TreeNode * itr=root;
        stack<TreeNode *> s;
        while(1)
        {
            while(itr!=nullptr)
            {
                s.push(itr);
                itr=itr->left;
            }
            itr=s.top();
            s.pop();
            if(--k==0) return itr->val;
            itr=itr->right;
        }
        return -1;
    }
};