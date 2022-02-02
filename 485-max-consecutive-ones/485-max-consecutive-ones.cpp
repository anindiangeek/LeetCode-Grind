class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int answer=0;int count=0;
        for(int i=0;i<=nums.size()-1;i++)
            answer=max(answer,count=(nums[i]==1)?count+1:0);
        return answer;
    }
};