class Solution {
public:
    bool isSubsequence(string s, string t) {
        int first{0},second{0};
        while(second < t.length())
            if(t[second++]==s[first]) first++;
        return first==s.length();
    }
};