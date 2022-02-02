class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int Sum= nums.size()*(nums.size()+1)/2,OtherSum=0;
        for(auto value:nums)
            OtherSum+=value;
        return Sum-OtherSum;
    }
};