class Solution {
public:
    int maxOperations(vector<int>& nums, int target) 
    {
        unordered_map<int,int> Frequency;
        int operations{0};
        for(int number: nums)
        {
           int OtherNumber = target - number;
           if(Frequency[OtherNumber]>0)
           {
               operations++;
               Frequency[OtherNumber]--;
           }
           else Frequency[number]++;
        }
        return operations;
    }
};