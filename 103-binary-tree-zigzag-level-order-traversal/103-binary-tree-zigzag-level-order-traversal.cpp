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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // handling the base case.
        if (!root)
            return {};

        vector<vector<int>> Answer;
        
        deque <TreeNode *> DQ; // doubly ended queue for storing the next Nodes to process
        
        DQ.push_back(root);
        Answer.push_back({root->val});
        bool LeftToRight=false;
        
        while (!DQ.empty()) // while it's not empty
        {
            vector<int> CurrentLevel;  // sub answer to push nodes of the current level.
            int NodesToProcess = DQ.size(); // nodes to process in current level.
            
            if(LeftToRight)
            {
                LeftToRight=false;
                while (NodesToProcess--)
                {
                    TreeNode *tovisit = DQ.front();
                    DQ.pop_front();
                    if (tovisit->left) // if there exists a left node 
                    {
                        CurrentLevel.push_back(tovisit->left->val);
                        DQ.push_back(tovisit->left);
                    }
                    if (tovisit->right) // if there exists a right node
                    {
                        CurrentLevel.push_back(tovisit->right->val);
                        DQ.push_back(tovisit->right);
                    }
                }
            }
            else // going right to left
            {
                LeftToRight=true;
                while(NodesToProcess--)
                {
                    TreeNode *tovisit=DQ.back();
                    DQ.pop_back();
                    // going in reverse order & pusing in queue in reverse order
                    if (tovisit->right) // if there exists a right node
                    {
                        CurrentLevel.push_back(tovisit->right->val);
                        DQ.push_front(tovisit->right);
                    }
                    if (tovisit->left) // if there exists a left node 
                    {
                        CurrentLevel.push_back(tovisit->left->val);
                        DQ.push_front(tovisit->left);
                    }
                }
            }
            if(CurrentLevel.size()) Answer.push_back(CurrentLevel);
        }
        return Answer;
    }
};