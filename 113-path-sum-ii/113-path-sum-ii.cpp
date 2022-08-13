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
    vector<vector<int>> answer;
    void dfs(TreeNode * root, int targetSum, vector<int>& v)
    {
        if(!root) return;
        
        v.push_back(root->val);
        
        targetSum -=root->val;

        
        
        if(!root->left and !root->right)
        {
           if(targetSum == 0)
                answer.push_back(v);
        }
        else
        {
            dfs(root->left,targetSum,v);
            dfs(root->right,targetSum,v);
        }
        
        //targetSum +=root->val;
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> v;
        dfs(root,targetSum,v);
        return answer;
    }
};