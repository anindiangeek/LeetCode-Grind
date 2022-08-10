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
    TreeNode* Recur(vector<int> &nums,int L,int R)
    {
        if(L>R)  return {};
        
        int mid = (L + R)/2;
        TreeNode * temp = new TreeNode(nums[mid]);
        
        temp->left = Recur(nums,L, mid-1);
        temp->right = Recur(nums,mid+1,R);
        
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return Recur(nums,0,nums.size()-1);
    }
};