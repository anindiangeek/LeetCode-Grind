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
    TreeNode* bstToGst(TreeNode* root) 
    {
        if(!root) return{};
        vector<int> Tree;
        stack<TreeNode *> s;
        TreeNode * t=root;
        while (t!=nullptr or !s.empty())
        {
            while(t!=nullptr)
            {
                s.push(t);
                t=t->left;
            }
            t=s.top();
            s.pop();
            Tree.push_back(t->val);
            t=t->right;
        }
        vector<int> prefix((int)Tree.size());
        std::inclusive_scan(Tree.begin(), Tree.end(), prefix.begin());
        
        s.push(root);
        while (!s.empty())
        {
            TreeNode *t = s.top();
            s.pop();
            int index = (lower_bound(Tree.begin(), Tree.end(), t->val) - Tree.begin());
            t->val += (prefix[prefix.size() - 1] - prefix[index]);
            if (t->right)
                s.push(t->right);
            if (t->left)
                s.push(t->left);
        }
        return root;
    }
};