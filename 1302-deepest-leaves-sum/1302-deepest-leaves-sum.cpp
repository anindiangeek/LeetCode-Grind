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
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<TreeNode*>> levels;
        queue<TreeNode*> toDo;
        toDo.push(root);
        
        while(!toDo.empty()){
            vector<TreeNode*> level;
            while(!toDo.empty()) { level.push_back(toDo.front()); toDo.pop(); }
            levels.push_back(level);
            
            for(TreeNode* l: level){
                if(l->left) toDo.push(l->left);
                if(l->right) toDo.push(l->right);
            }
        }
        
        int deepestSum(0);
        for(int i(0); i<levels[levels.size()-1].size(); i++)
            deepestSum+=(levels[levels.size()-1][i])->val;
        
        return deepestSum;
    }
};
