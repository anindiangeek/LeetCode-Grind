class Solution {
public:
     string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int left=0, len = 1;
        for(int i = 0; i < s.size(); i++)
        {
            dp[i][i] = true;
            if(i == s.size() - 1) break;
            dp[i][i+1] = (s[i] == s[i+1]);
            if(dp[i][i+1] && len == 1)
            {
                left = i;
                len = 2;
            }
        }
        
        
        for(int i = s.size() - 3; i >= 0; i --)
        {
            for(int j = i + 2; j < s.size(); j++)
            {
                dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
                if(dp[i][j] && (j - i + 1) > len)
                {
                    len = j - i + 1;
                    left = i;
                }
            }
        }
        
        return s.substr(left, len);
    }
};