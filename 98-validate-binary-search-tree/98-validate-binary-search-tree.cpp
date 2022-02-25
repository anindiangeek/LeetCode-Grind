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
      int MaximumLeft(TreeNode *root)
  {
    if (!root)
      return INT_MIN;
    int temp = max(MaximumLeft(root->left), MaximumLeft(root->right));
    return max(temp, root->val);
  }

  int MinimumRight(TreeNode *root)
  {
    if (!root)
      return INT_MAX;
    int temp = min(MinimumRight(root->left), MinimumRight(root->right));
    return min(temp, root->val);
  }

  bool isValidBST(TreeNode *root)
  {
    if (!root)
      return true;

    if (root->left && MaximumLeft(root->left) >= root->val)
      return false;

    if (root->right && MinimumRight(root->right) <= root->val)
      return false;

    if (!isValidBST(root->left) or !isValidBST(root->right))
      return false;

    return true;
  }
};