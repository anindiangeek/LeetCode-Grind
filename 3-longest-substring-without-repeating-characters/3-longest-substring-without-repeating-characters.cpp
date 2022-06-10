class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int answer{0};
        vector<int> Hash(256, -1); 
        // we store the index if the element is present
        for (int i = 0, j = -1; i < size(s); i++)
        {
            if (Hash[s[i]] > j)
                j = Hash[s[i]];
            Hash[s[i]] = i; // saving the index
            answer = max(answer, i - j);
        }
        return answer;
    }
};