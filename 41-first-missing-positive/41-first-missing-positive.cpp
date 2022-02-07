class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // there are several ways to mark the presense of elements in the array.
        // 1st method - add the n number to each number in the range and later divide and see if lie in the range.
        // 2nd method - mark the present element in [1..n] range with a -ve symbol and later check that which was the index marked -ve +1 is the answer.
        
        
        // using second method here.
        for(auto &value : nums)
            if(value<=0 or value>nums.size())
                value=nums.size()+1;
        
        for(int i=0;i<nums.size();i++)
        {
            int value=abs(nums[i]);
            
            if(value>nums.size())
                continue;
            if(nums[value-1]>0)
                nums[value-1]=-1*nums[value-1];
        }
        
        for(int i=0;i<nums.size();i++)
            if(nums[i]>0)
               return i+1;
        return nums.size()+1;
    }
};