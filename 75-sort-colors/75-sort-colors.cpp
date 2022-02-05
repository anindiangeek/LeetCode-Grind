class Solution {
public:
    void sortColors(vector<int>& nums) {
        //using DNF algorithm to solve the the problem.
        int low=0,high=nums.size()-1,mid=0;
        for(int i=0;mid<=high;i++)
        {
            switch(nums[i])
            {
                case 0:
                       swap(nums[low++],nums[i]);
                case 1:
                        mid++;        
                    break;
                case 2:
                       swap(nums[high--],nums[i--]);
            }
        }
    }
};