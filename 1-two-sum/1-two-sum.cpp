class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>M;
        for(int i=0;i<nums.size();i++)
        {
            auto it=M.find(target-nums[i]);
            
            if(it!=M.end())
                return {i,it->second};
            
            M[nums[i]]=i;
        }
        return {};
    }
};