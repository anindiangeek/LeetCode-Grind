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
        vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        vector<double> ans;
        queue<TreeNode *> Todo;
        Todo.push(root);
        
        while(!Todo.empty())
        {
            int64_t n = Todo.size(), sum=0,child=n;
            while(n--)
            {
                TreeNode * temp = Todo.front();
                Todo.pop();
                sum += temp->val;
                if(temp->left)
                   Todo.push(temp->left);
                if(temp->right)
                   Todo.push(temp->right);
            }
            ans.push_back((double)sum/child);
            
        }
        return ans;
    }
};