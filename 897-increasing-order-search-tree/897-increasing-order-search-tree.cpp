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
    TreeNode* increasingBST(TreeNode* root) {
         if (!root or (!root->left && !root->right))
            return root;
        stack<TreeNode *> s1;
        vector<TreeNode *> s2;
        TreeNode *t = root, *NewHead = nullptr;
        bool FoundHead = false;
        while (t != nullptr or !s1.empty())
        {
            while (t != nullptr)
            {
                s1.push(t);
                t = t->left;
            }

            t = s1.top();
            s1.pop();

            if (!FoundHead)
            {
                NewHead = t;
                FoundHead = true;
            }
            s2.push_back(t);
            t = t->right;
        }
        TreeNode *temp = NewHead;
        temp->left = nullptr;
        for (auto p : s2)
        {
            if (p == NewHead)
                continue;
            else
            {
                temp->right = p;
                temp->left = nullptr;
                temp = temp->right;
            }
        }
        temp->right = nullptr;
        temp->left = nullptr;
        return NewHead;
    }
};