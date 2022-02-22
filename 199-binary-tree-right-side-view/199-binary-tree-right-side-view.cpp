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
        void Helper(TreeNode *root, vector<int> &v, int level)
    {
        if (!root) // base case.
            return;

        // as for every level we will have one node only so we will push the first node.
        if (v.size() == level)
            v.push_back(root->val);

        // we go deep right and add first node to our answer, similarly for the left we will go left first.
        Helper(root->right, v, level + 1);
        Helper(root->left, v, level + 1);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> RightView;
        int level = 0;
        Helper(root, RightView, level);
        return RightView;
    }
};