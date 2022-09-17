class Solution {
public:
    vector<vector<int>> dp;
   int helper(int index,vector<int>& nums, vector<int>& multi, int start) 
   {    if (dp[index][start] != INT_MIN) return dp[index][start];
    int end= nums.size()-1-(index-start);
      if(index== multi.size())  return 0;
       return dp[index][start]= max(multi[index]*nums[start]+ helper(index+1, nums,multi, start+1),multi[index]*nums[end]+ helper(index+1, nums, multi, start) );
       
   }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n= nums.size();
        int m= multipliers.size();
         dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
        return helper(0, nums, multipliers, 0);
    } 
};