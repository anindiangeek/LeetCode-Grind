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
class Solution
{
  public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};

        queue<TreeNode *> q;
        vector<vector<int>> v;
        q.push(root);
        v.push_back({root->val});
        while (!q.empty())
        {
            vector<int> second;
            int NodesToProcess = q.size();
            while (NodesToProcess--)
            {
                TreeNode *tovisit = q.front();
                if (tovisit->left)
                {
                    second.push_back(tovisit->left->val);
                    q.push(tovisit->left);
                }
                if (tovisit->right)
                {
                    second.push_back(tovisit->right->val);
                    q.push(tovisit->right);
                }
                q.pop();
            }
            if (second.size()) v.push_back(second);
        }
        return v;
    }
};