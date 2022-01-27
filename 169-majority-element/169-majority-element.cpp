class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate=0,vote=0;
        for(auto &value :nums)
        {
            if(vote==0)
            {
                candidate=value;
                vote=1;
            }
            else if(candidate==value)
                ++vote;
            else
                --vote;
        }
        return candidate;
    } 
};