class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,answer=0,n=nums.size();
        while(j<n)
        {
            if(nums[j]==0)
                if(k)
                    k--;
                else
                    while(nums[i++]!=0);
            answer=max(answer,j-i+1);
            ++j;
        }
        return answer;
    }
};