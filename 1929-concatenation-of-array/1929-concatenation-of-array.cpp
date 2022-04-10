class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> answer;
        answer.insert(answer.end(),nums.begin(),nums.end());
        answer.insert(answer.end(),nums.begin(),nums.end());
        return answer;
    }
};