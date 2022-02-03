class Solution {
public:
    int minSubArrayLen(int Target, vector<int>& nums) {
        unsigned int answer = INT_MAX, CurrentSum = 0, Tail = 0, Head = 0;
        for (; Tail < nums.size(); Tail++)
        {
            CurrentSum += nums[Tail];

            while (CurrentSum >= Target)
            {
                answer = min(answer, Tail - Head + 1);
                CurrentSum -= nums[Head++];
            }
        }
        return (answer == INT_MAX) ? 0 : answer; 
    }
};