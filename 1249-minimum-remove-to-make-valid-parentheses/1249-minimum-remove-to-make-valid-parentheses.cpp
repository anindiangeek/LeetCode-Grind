class Solution {
public:
    string minRemoveToMakeValid(string s) {
                vector<int> stk;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')')
            {
                if(stk.size()>0)
                {
                    stk.pop_back();
                }
                else
                {
                    s[i]='*';
                }
            }
            else if(s[i]=='(')
            {
                stk.push_back(i);
            }
        }
        for(int i=0;i<stk.size();i++)
        {
            s[stk[i]]='*';
        }
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='*')
            {
                ans+=s[i];
            }
        }
        return ans;

    }
};