class Solution {
public:
    int findDuplicate(vector<int>& nums) {
         int slow = nums[0], fast = nums[0];
        // first phase of flyod's algorithm.
        // finding intersection.
        do
        {
            // moving single step.
            slow = nums[slow];
            // moving two steps.
            fast = nums[nums[fast]];
        } while (slow != fast);

        // second phase of flyod's algorithm.
        fast = nums[0];
        while (fast != slow)
        {
            slow = nums[slow];
            fast = nums[fast];
            // they will meet at starting of loop.
        }
        return fast; 
   }
};